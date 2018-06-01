TARDIR := $(MAKEFILE_DIR)/gen/tar/

# Kinemic classifier
KINEMIC_PATH := $(LIBDIR)libtfclassifier-lite.a

KINEMIC_SRCS := \
tensorflow/contrib/lite/kinemic/TFClassifierLite.cc
KINEMIC_OBJS := $(addprefix $(OBJDIR), \
$(patsubst %.cc,%.o,$(patsubst %.c,%.o,$(KINEMIC_SRCS))))

$(KINEMIC_PATH): $(KINEMIC_OBJS) $(LIB_OBJS)
	@mkdir -p $(dir $@)
	$(AR) $(ARFLAGS) $(KINEMIC_PATH) $(KINEMIC_OBJS) $(LIB_OBJS)

KINEMIC_PACKAGE:= $(TARDIR)tfclassifier-lite-$(HOST_OS)-$(ARCH).tar.gz
$(KINEMIC_PACKAGE): $(KINEMIC_PATH)
	@mkdir -p $(dir $@)
	@mkdir -p $(TARDIR)
	cd $(LIBDIR) \
	&& tar -czf $(notdir $(KINEMIC_PACKAGE)) $(notdir $(KINEMIC_PATH)) \
	&& mv $(notdir $(KINEMIC_PACKAGE)) $(TARDIR)

KINEMIC_PACKAGE_MD5 := $(KINEMIC_PACKAGE).md5
$(KINEMIC_PACKAGE_MD5): $(KINEMIC_PACKAGE)
	md5 -q $(KINEMIC_PACKAGE) > $(KINEMIC_PACKAGE_MD5) \
	&& cat $(KINEMIC_PACKAGE_MD5)

kinemic: $(KINEMIC_PACKAGE) $(KINEMIC_PACKAGE_MD5)
