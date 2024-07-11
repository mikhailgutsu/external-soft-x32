#include <windows.h>

bool IsDebuggerPresentCheck() {
    return IsDebuggerPresent();
}

bool CheckRemoteDebuggerPresentCheck() {
    BOOL debuggerPresent = FALSE;
    CheckRemoteDebuggerPresent(GetCurrentProcess(), &debuggerPresent);
    return debuggerPresent;
}
