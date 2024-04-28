
#include <stdio.h>
//#include "../interface.hpp"
#include "./plugin1.hpp"

#define DO_C_LOG printf("%s:%s:%d\n", __FILE__,  __FUNCTION__,  __LINE__ )

#ifdef __cplusplus
extern "C" {
#endif

static Interface *instance = NULL;

void Init()
{
  DO_C_LOG;
}

int DoOperation(char *arg)
{
  DO_C_LOG;
  printf("Arg; %s\n", arg?arg:"");
  return 0;
}

Interface *GetHandle()
{
  DO_C_LOG;
  if(instance == NULL)
  {
    instance = new Plugin1();
  }
  return instance;
}

void ReleaseHandle(Interface *plugin)
{
  DO_C_LOG;
  if(plugin)
  {
    delete plugin;
  }
}

#ifdef __cplusplus
}
#endif  
