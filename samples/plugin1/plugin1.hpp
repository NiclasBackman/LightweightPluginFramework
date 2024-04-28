#ifndef _PLUGIN1_HPP
#define _PLUGIN1_HPP

#include <typeinfo>
#include "interface.hpp"

class Plugin1 : public Interface
{
public:
  Plugin1(){}
  void Init();
  void DoOperation();
  std::string Name() const
  {
    return typeid(Plugin1).name();
  }
};

#endif
