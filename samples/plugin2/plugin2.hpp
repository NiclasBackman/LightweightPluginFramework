#ifndef _PLUGIN2_HPP
#define _PLUGIN2_HPP

#include <typeinfo>
#include "interface.hpp"

class Plugin2 : public Interface
{
public:
  Plugin2(){}
  void Init();
  void DoOperation();
  std::string Name() const
  {
    return typeid(Plugin2).name();
  }
};

#endif
