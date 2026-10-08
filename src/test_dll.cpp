#include <windows.h>
#include <iostream>

using AnalyzerVersion = const char* (*)();

int main()
{
    HMODULE library = LoadLibraryA("../build/libVideoAnalyzer.dll");

    if (!library)
    {
        std::cerr << "Failed to load DLL" << std::endl;
        return 1;
    }

    auto analyzer_version =
        reinterpret_cast<AnalyzerVersion>(
            GetProcAddress(library, "analyzer_version")
        );

    if (!analyzer_version)
    {
        std::cerr << "Failed to find analyzer_version" << std::endl;
        FreeLibrary(library);
        return 1;
    }

    std::cout << analyzer_version() << std::endl;

    FreeLibrary(library);

    return 0;
}
