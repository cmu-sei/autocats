// cl.exe -nologo -Gm- -GR- -EHa- -Oi msvc32b-call-apis-twice-nested-simple.cpp
// -link -nodefaultlib -subsystem:windows kernel32.lib
#include <windows.h>

HANDLE hFile2 = (HANDLE)43;  

bool goal = false;

void __stdcall WinMainCRTStartup() {
    HANDLE hFile;

    hFile = CreateFile("name",                 // name of the write
                       GENERIC_WRITE,          // open for writing
                       0,                      // do not share
                       NULL,                   // default security
                       CREATE_NEW,             // create new file only
                       FILE_ATTRIBUTE_NORMAL,  // normal file
                       NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        return;
    }
    CloseHandle(hFile2);
}