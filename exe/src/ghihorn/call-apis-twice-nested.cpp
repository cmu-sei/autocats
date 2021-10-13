// cl.exe -nologo -Gm- -GR- -EHa- -Oi msvc32b-call-apis-twice-nested.cpp -link -nodefaultlib -subsystem:windows kernel32.lib
#include <windows.h>

void __stdcall WinMainCRTStartup() {
    HANDLE hFile, hFile2;
    LPCSTR name = "File.txt";
    LPCSTR name2 = "File2.txt";

    hFile = CreateFile(name,                   // name of the write
                       GENERIC_WRITE,          // open for writing
                       0,                      // do not share
                       NULL,                   // default security
                       CREATE_NEW,             // create new file only
                       FILE_ATTRIBUTE_NORMAL,  // normal file
                       NULL);

    hFile2 = CreateFile(name2,                  // name of the write
                        GENERIC_WRITE,          // open for writing
                        0,                      // do not share
                        NULL,                   // default security
                        CREATE_NEW,             // create new file only
                        FILE_ATTRIBUTE_NORMAL,  // normal file
                        NULL);

    if (hFile != INVALID_HANDLE_VALUE) {
        CloseHandle(hFile);
    }
    if (hFile2 != INVALID_HANDLE_VALUE) {
        CloseHandle(hFile2);
    }
    return;
}