#include <stdio.h>
#include <stdlib.h>
#include </usr/include/dlfcn.h>
#include "arith.h"
int main(int argc, char* argv[])
{
  int a = 4;
  int b = 3;
  int ret = 0;

  // 加载动态库
  void *p_Handler = dlopen("./arith.so", RTLD_NOW);
  if (!p_Handler)
  {
    printf("%s\n",dlerror());
    exit(1);
  }

  // 引入接口函数
  char *error;
  typedef int (*arith_add)(int, int);
  arith_add pf_add_interface;
  pf_add_interface = (arith_add)dlsym(p_Handler, "add");
  error = dlerror();
  if (error)
  {
    printf("%s\n", error);
    exit(1);
  }
  
  // 调用
  ret = pf_add_interface(a,b);

  printf(" %d + %d = %d\n",a,b,ret);
  dlclose(p_Handler); // 关闭句柄
  return 0;
}
