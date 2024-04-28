#ifndef _INTERFACE_HPP
#define _INTERFACE_HPP
#include <string>

class Interface
{
public:
    virtual void Init() = 0;
    virtual void DoOperation() = 0;
    virtual std::string Name() const = 0;
};
#endif