#include "debug_api.h"

namespace debug {
BOOL DebugAPI::CreateProcess(
    LPCTSTR lpApplicationName,
    LPTSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPCTSTR lpCurrentDirectory,
    LPSTARTUPINFO lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation) {
  return ::CreateProcess(lpApplicationName,
                         lpCommandLine,
                         lpProcessAttributes,
                         lpThreadAttributes,
                         bInheritHandles,
                         dwCreationFlags,
                         lpEnvironment,
                         lpCurrentDirectory,
                         lpStartupInfo,
                         lpProcessInformation);
}

BOOL DebugAPI::CloseHandle(HANDLE hObject) {
  return ::CloseHandle(hObject);
}

BOOL DebugAPI::ReadProcessMemory(HANDLE hProcess,
                                 LPCVOID lpBaseAddress,
                                 LPVOID lpBuffer,
                                 SIZE_T nSize,
                                 SIZE_T *lpNumberOfBytesRead) {
  return ::ReadProcessMemory(hProcess,
                             lpBaseAddress,
                             lpBuffer,
                             nSize,
                             lpNumberOfBytesRead);
}

BOOL DebugAPI::WriteProcessMemory(HANDLE hProcess,
                                  LPVOID lpBaseAddress,
                                  LPCVOID lpBuffer,
                                  SIZE_T nSize,
                                  SIZE_T *lpNumberOfBytesWritten) {
  return ::WriteProcessMemory(hProcess,
                              lpBaseAddress,
                              lpBuffer,
                              nSize,
                              lpNumberOfBytesWritten);
}

BOOL DebugAPI::FlushInstructionCache(HANDLE hProcess,
                                     LPCVOID lpBaseAddress,
                                     SIZE_T dwSize) {
  return ::FlushInstructionCache(hProcess, lpBaseAddress, dwSize);
}

BOOL DebugAPI::GetThreadContext(HANDLE hThread,LPCONTEXT lpContext) {
  return ::GetThreadContext(hThread,lpContext);
}

BOOL DebugAPI::SetThreadContext(HANDLE hThread, CONTEXT *lpContext) {
  return ::SetThreadContext(hThread, lpContext);
}

BOOL DebugAPI::WaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent,
                                 DWORD dwMilliseconds) {
  return ::WaitForDebugEvent(lpDebugEvent, dwMilliseconds);
}

BOOL DebugAPI::ContinueDebugEvent(DWORD dwProcessId,
                                  DWORD dwThreadId,
                                  DWORD dwContinueStatus) {
  return ::ContinueDebugEvent(dwProcessId, dwThreadId, dwContinueStatus);
}

BOOL DebugAPI::TerminateThread(HANDLE hThread, DWORD dwExitCode) {
  return ::TerminateThread(hThread, dwExitCode);
}

BOOL DebugAPI::DebugBreakProcess(HANDLE Process) {
  return ::DebugBreakProcess(Process);
}

BOOL DebugAPI::Wow64GetThreadContext(HANDLE hThread,PWOW64_CONTEXT lpContext) {
  return ::Wow64GetThreadContext(hThread,lpContext);
}

BOOL DebugAPI::Wow64SetThreadContext(HANDLE hThread,const WOW64_CONTEXT* lpContext) {
  return ::Wow64SetThreadContext(hThread, lpContext);
}

BOOL DebugAPI::IsWow64Process(HANDLE hProcess,PBOOL Wow64Process) {
  return ::IsWow64Process(hProcess,Wow64Process);
}

BOOL DebugAPI::DebugActiveProcess(DWORD dwProcessId) {
  return ::DebugActiveProcess(dwProcessId);
}

BOOL DebugAPI::DebugActiveProcessStop(DWORD dwProcessId) {
  return ::DebugActiveProcessStop(dwProcessId);
}
}  // namespace debug