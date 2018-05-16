#include <unistd.h>
extern unsigned int __page_size = getpagesize();

const char* tf_git_version() {return "v1.2-llvm-5-g08819d3ae";}
const char* tf_compiler_version() {return __VERSION__;}
