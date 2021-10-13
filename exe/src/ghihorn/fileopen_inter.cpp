#include <windows.h>

// cl.exe -nologo -Gm- -GR- -EHa- -Oi fileopen2.cpp -link -nodefaultlib -subsystem:windows kernel32.lib

VOID Close(HANDLE hFile) {
    if (hFile != INVALID_HANDLE_VALUE) {
        CloseHandle(hFile);
    }
}

VOID Open() {
    HANDLE hFile, hFile2;

    hFile = CreateFile("File.txt",             // name of the write
                       GENERIC_WRITE,          // open for writing
                       0,                      // do not share
                       NULL,                   // default security
                       CREATE_NEW,             // create new file only
                       FILE_ATTRIBUTE_NORMAL,  // normal file
                       NULL);

    Close(hFile2);

}



void __stdcall WinMainCRTStartup() { Open(); }