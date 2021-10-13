//cl.exe -nologo -Gm- -GR- -EHa- -Oi inc.cpp -link -nodefaultlib -subsystem:windows kernel32.lib

#include <windows.h>
unsigned int inc = 0x42;

int func0() {
    inc += 1;
    return (++inc);
}

int __stdcall WinMainCRTStartup() {
   
   int x = func0();
   if (x == 0x44) {
       return 1;
   }
   return 2;
}
