#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <iostream>
#include <fstream>
#include <string>

void LogInjection(const std::string& message) {
    std::ofstream logFile("injection_log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << message << std::endl;
        logFile.close();
    }
}

bool CheckForInjectedDLLs(DWORD processID) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processID);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        return false;
    }

    MODULEENTRY32 moduleEntry;
    moduleEntry.dwSize = sizeof(MODULEENTRY32);

    if (Module32First(hSnapshot, &moduleEntry)) {
        do {
            if (strstr(moduleEntry.szModule, "injectable_dll.dll") != NULL) {
                std::string message = "Injected DLL found: " + std::string(moduleEntry.szModule);
                LogInjection(message);
                CloseHandle(hSnapshot);
                return true;
            }
        } while (Module32Next(hSnapshot, &moduleEntry));
    }

    CloseHandle(hSnapshot);
    return false;
}

int main() {
    DWORD processID;
    std::cout << "Enter the target process ID to check for injection: ";
    std::cin >> processID;

    if (CheckForInjectedDLLs(processID)) {
        std::cout << "Injected DLL detected. Log updated." << std::endl;
    } else {
        std::cout << "No injected DLL detected." << std::endl;
    }

    return 0;
}
