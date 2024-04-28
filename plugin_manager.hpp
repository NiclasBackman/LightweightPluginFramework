#ifndef _PLUGIN_MANAGER_HPP
#define _PLUGIN_MANAGER_HPP

#include <dirent.h>
#include <dlfcn.h>
#include <filesystem>
#include <list>
#include <string>

using namespace std;

template <typename T> class PluginManager
{
    typedef T (*func_get_handle_t)(void);
    typedef void (*func_release_handle_t)(T);

    class PluginEntry
    {
        public:
        PluginEntry(T interface, func_release_handle_t releaseHandle)
        {
            mInterface = interface;
            mReleaseHandle = releaseHandle;
        }

        T GetInterface() const
        {
            return mInterface;
        }

        func_release_handle_t GetReleaseHandle() const
        {
            return mReleaseHandle;
        }

        private:
        T mInterface;
        func_release_handle_t mReleaseHandle;
    };
    
    public:
    PluginManager(string& pluginPath)
    {
        for (const auto & entry : filesystem::directory_iterator(pluginPath))
        {
            if(entry.path().extension() == ".so")
            {
                cout << "Found plugin: " << entry.path() << endl;
                void *handle;
                if ( (handle = dlopen(entry.path().c_str(), RTLD_LAZY)) == NULL)
                {
                    cerr << "Failed to open lib, error: " << strerror(errno) << endl;
                    continue;
                }
                T (*get_handle_fn)(void) = (func_get_handle_t)dlsym(handle, "GetHandle");
                if (dlerror() != NULL)
                {
                    cerr << "Failed to grab 'GetHandle', error: " << strerror(errno) << endl;
                    dlclose(handle);
                    continue;
                }
                void (*release_handle_fn)(T) = (func_release_handle_t)dlsym(handle, "ReleaseHandle");
                if (dlerror() != NULL)
                {
                    cerr << "Failed to grab 'ReleaseHandle', error: " << strerror(errno) << endl;
                    dlclose(handle);
                    continue;
                }

                T plugin = get_handle_fn();
                PluginEntry *entry = new PluginEntry(plugin, release_handle_fn);
                mPlugins.push_back(entry);
            }
        }
    }

    ~PluginManager()
    {
        cout << "In destructor" << __LINE__ << endl;
        for (auto it = mPlugins.begin(); it != mPlugins.end(); ++it)
        {
            auto interface = ((*it)->GetInterface());
            auto releaseHandle = ((*it)->GetReleaseHandle());
            releaseHandle(interface);
            delete *it;
        }
    }

    std::list<PluginEntry*> GetAllPlugins() const
    {
        return mPlugins;
    }

    private:
    std::list<PluginEntry*> mPlugins;
};

#endif