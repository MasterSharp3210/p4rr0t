#include "pch.h"
#include <windows.h>
#include <stdio.h>

void Console() {
    AllocConsole();
    FILE* stream;
    freopen_s(&stream, "CONOUT$", "w", stdout);
    freopen_s(&stream, "CONOUT$", "w", stderr);
}

DWORD WINAPI CrashThread(LPVOID lpParam) {
    Console();

    Sleep(1500);
    printf("Exploiting program\n");

    bool pointerSuccess = false;

    __try {
        printf("Pwning program\n");
        int* panic_pointer = (int*)0;
        *panic_pointer = 666;

        pointerSuccess = true;
        printf("Process terminated!\n");
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        printf("ERROR: Exploit failed - Caught memory exception (Access Violation) from pointer!\n");
    }

    printf("Second attempt: Trying to crash program with ExitProcess exploit\n");

    Sleep(1500);

    ExitProcess(0);

    printf("Process terminated!\n");

    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);

        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)CrashThread, NULL, 0, NULL);
        break;

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}