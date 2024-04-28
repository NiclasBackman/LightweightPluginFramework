#include <iostream>
#include <string.h>
#include "interface.hpp"
#include "plugin_manager.hpp"

using namespace std;

int main(int argc, char** argv)
{
  cout << "Starting up..." << endl;

  string path("./");
  auto pm = new PluginManager<Interface*>(path);

  auto plugins = pm->GetAllPlugins();
  for (auto it = plugins.begin(); it != plugins.end(); ++it)
  {
    auto interface = ((*it)->GetInterface());
    cout << "Calling plugin:" << interface->Name() << endl;
    interface->Init();
    interface->DoOperation();
  }
  delete pm;
  cout << "done" << endl;  
  return 0;
}
