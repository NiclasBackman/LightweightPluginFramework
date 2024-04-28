#include <stdio.h>

#include <iostream>
#include "plugin2.hpp"

using namespace std;

#define DO_LOG   cout << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << endl
#define DO_C_LOG printf("%s:%s:%d\n", __FILE__,  __FUNCTION__,  __LINE__ )

void Plugin2::Init()
{
  DO_LOG;
}

void Plugin2::DoOperation()
{
  DO_LOG;
}

