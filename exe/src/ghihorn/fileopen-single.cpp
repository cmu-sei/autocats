// cl.exe -nologo -Gm- -GR- -EHa- -Oi fileopen0.cpp -link -nodefaultlib
// -subsystem:windows kernel32.lib
#include <windows.h>
BOOL Open() {
    HANDLE hFile;

    hFile = CreateFile("File.txt",             // name of the write
                       GENERIC_WRITE,          // open for writing
                       0,                      // do not share
                       NULL,                   // default security
                       CREATE_NEW,             // create new file only
                       FILE_ATTRIBUTE_NORMAL,  // normal file
                       NULL);

   
    CloseHandle(hFile);

    return true;
}

void __stdcall WinMainCRTStartup() {}