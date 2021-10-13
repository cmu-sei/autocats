//@formatter:off
// cl.exe -nologo -Gm- -GR- -EHa- -Oi simple-kernel32.cpp -link /dll
// /out:kernel32.dll -nodefaultlib /entry:DllMain
//@formatter:on

#include <windows.h>

#ifdef __cplusplus  // If used by C++ code,
extern "C" {        // we need to export the C interface
#endif
}

unsigned int handle = 0x42;

__declspec(dllexport) HANDLE
    __stdcall CreateFile(LPCSTR lpFileName, DWORD dwDesiredAccess,
                         DWORD dwShareMode,
                         LPSECURITY_ATTRIBUTES lpSecurityAttributes,
                         DWORD dwCreationDisposition,
                         DWORD dwFlagsAndAttributes, HANDLE hTemplateFile) {
    if (lpFileName != NULL && dwDesiredAccess != 0 && dwShareMode != 0 &&
        lpSecurityAttributes != NULL && dwCreationDisposition != 0 &&
        dwFlagsAndAttributes != 0 && hTemplateFile != INVALID_HANDLE_VALUE) {
        __asm { nop }
    }

    return (HANDLE)(++handle);
}

__declspec(dllexport) BOOL __stdcall CloseHandle(HANDLE hObject) {
    if (hObject != INVALID_HANDLE_VALUE) {
        return true;
    }
    return false;
}

BOOL __stdcall DllMain(HINSTANCE hinstDLL,  // handle to DLL module
                       DWORD fdwReason,     // reason for calling function
                       LPVOID lpReserved)   // reserved
{
    return TRUE;
}
