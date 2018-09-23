#include <iostream>
#include <dlfcn.h>

int main() {
    using std::cout;
    using std::cerr;

    char url[] = "http://churchinplano.org/mp3/PSRP/2012WT/2012-WT-Outlines-with-Verses-E.pdf";

    cout << "C++ dlopen demo\n\n";

    // open the library
    cout << "Opening plug-in ...\n";
    void* handle = dlopen("./plugin/libspeed_test_curl.so", RTLD_LAZY);
    
    if (!handle) {
        cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    }
    
    // load the symbol
    cout << "Loading symbol plug-in API...\n";
    typedef void (*plugin_t)(char[]);

    // reset errors
    dlerror();
    plugin_t plugin = (plugin_t) dlsym(handle, "curl_download");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol 'plugin': " << dlsym_error <<
            '\n';
        dlclose(handle);
        return 1;
    }
    
    // use it to do the calculation
    cout << "Calling plugin...\n";
    plugin(url);
    
    // close the library
    cout << "Closing library...\n";
    dlclose(handle);
}

