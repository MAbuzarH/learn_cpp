#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define BUF_SIZE 256

//--------------------------------------------------
// Function: ReportError
// Purpose:  Prints a custom error message along with
//           the system error message (if requested).
//--------------------------------------------------
void ReportError(LPCTSTR userMessage, DWORD exitCode, BOOL printErrorMessage)
{
    DWORD errNum = GetLastError(); // Gets the last Windows API error
    LPTSTR lpSysMsg = NULL;        // Pointer for system error text

    _ftprintf(stderr, _T("%s\n"), userMessage);

    if (printErrorMessage)
    {
        DWORD eMsgLen = FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL,
            errNum,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
            (LPTSTR)&lpSysMsg,
            0,
            NULL);

        if (eMsgLen > 0)
        {
            _ftprintf(stderr, _T("%s\n"), lpSysMsg);
        }
        else
        {
            _ftprintf(stderr, _T("Unknown error code: %lu\n"), errNum);
        }

        if (lpSysMsg != NULL)
            LocalFree(lpSysMsg);
    }

    if (exitCode > 0)
        ExitProcess(exitCode);
}

//--------------------------------------------------
// Function: Options
// Purpose:  Parses command-line options (flags)
// Example:  program.exe -a -b file.txt
//--------------------------------------------------
// DWORD Options(int argc, LPCTSTR argv[], LPCTSTR Optstr, ...)
DWORD Options(int argc, TCHAR *argv[], LPCTSTR Optstr, ...)
{
    va_list pFlagList;
    LPBOOL pFlag;
    int iFlag = 0, iArg;

    va_start(pFlagList, Optstr);

    while ((pFlag = va_arg(pFlagList, LPBOOL)) != NULL && iFlag < (int)_tcslen(Optstr))
    {
        *pFlag = FALSE;
        for (iArg = 1; !(*pFlag) && iArg < argc && argv[iArg][0] == _T('-'); iArg++)
        {
            // Check if option exists in command-line
            *pFlag = _tcschr(argv[iArg], Optstr[iFlag]) != NULL;
        }
        iFlag++;
    }

    va_end(pFlagList);

    // Return index of first non-option argument
    for (iArg = 1; iArg < argc && argv[iArg][0] == _T('-'); iArg++)
        ;
    return iArg;
}

//--------------------------------------------------
// Function: CatFile
// Purpose:  Copies contents from input file to output file
//--------------------------------------------------
static void CatFile(HANDLE hInFile, HANDLE hOutFile)
{
    DWORD nIn, nOut;
    BYTE buffer[BUF_SIZE];

    while (ReadFile(hInFile, buffer, BUF_SIZE, &nIn, NULL) && (nIn != 0))
    {
        WriteFile(hOutFile, buffer, nIn, &nOut, NULL);
    }
}

//--------------------------------------------------
// Function: main
// Purpose:  Demonstrates file opening and error handling
//--------------------------------------------------
int _tmain(int argc, TCHAR *argv[])
{
    BOOL flagA, flagB;
    DWORD firstArgIndex;

    // --- Test Options() function ---
    firstArgIndex = Options(argc, argv, _T("ab"), &flagA, &flagB, NULL);

    _tprintf(_T("flagA = %d\n"), flagA);
    _tprintf(_T("flagB = %d\n"), flagB);
    _tprintf(_T("First non-option argument index = %lu\n"), firstArgIndex);

    if (firstArgIndex < (DWORD)argc)
    {
        _tprintf(_T("Non-option argument: %s\n"), argv[firstArgIndex]);
    }

    // --- Test file handling & ReportError() ---
    HANDLE hFile = CreateFile(
        _T("nonexistent.txt"),
        GENERIC_READ,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (hFile == INVALID_HANDLE_VALUE)
    {
        ReportError(_T("Error opening file."), 0, TRUE);
    }
    else
    {
        _tprintf(_T("File opened successfully!\n"));
        CloseHandle(hFile);
    }

    return 0;
}



// #include <windows.h>
// #include <tchar.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdarg.h>
// #define BUF_SIZE 256
// void ReportError(LPCTSTR userMessage, DWORD exitCode, BOOL printErrorMessage)
// {
//   DWORD errNum = GetLastError();
//   LPTSTR lpSysMsg = NULL;

//   _ftprintf(stderr, _T("%s\n"), userMessage);

//   if (printErrorMessage)
//   {
//     DWORD eMsgLen = FormatMessage(
//         FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
//         NULL,
//         errNum,
//         MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
//         (LPTSTR)&lpSysMsg,
//         0,
//         NULL);

//     if (eMsgLen > 0)
//     {
//       _ftprintf(stderr, _T("%s\n"), lpSysMsg);
//     }
//     else
//     {
//       _ftprintf(stderr, _T("Unknown error code: %lu\n"), errNum);
//     }

//     if (lpSysMsg != NULL)
//       LocalFree(lpSysMsg);
//   }

//   if (exitCode > 0)
//     ExitProcess(exitCode);
// }

// DWORD Options(int argc, LPCTSTR argv[], LPCTSTR Optstr,...)
// {
//   va_list pFlagList;
//   LPBOOL pFlag;
//   int iFlag = 0, iArg;
//   va_start(pFlagList, Optstr);

//   while ((pFlag = va_arg(pFlagList, LPBOOL)) != NULL && iFlag < (int)_tcslen(Optstr))
//   {
//     *pFlag = FALSE;
//     for (iArg = 1; !(*pFlag) && iArg < argc && argv[iArg][0] == _T('-'); iArg++)
//     {
//       *pFlag = memtchar(argv[iArg],Optstr[iFlag],_tcslen(argv[iArg])) !=NULL;
//     }
//     iFlag++;
//   }
//   va_end(pFlagList);
//   for (iArg = 1; iArg < argc && argv[iArg][0] == _T('-'); iArg++)
//     ;
//   return iArg;
// }

// static void CatFile(HANDLE hInFile, HANDLE hOutFile)
// {
//   DWORD nIn, nOut;
//   BYTE buffer[BUF_SIZE];
//   while (ReadFile(hInFile, buffer, BUF_SIZE, nIn, NULL) && (nIn != 0) && WriteFile(hOutFile, buffer, nIn, &nOut, NULL))
//     ;
//   return;
// }
// int main(void)
// {
//   HANDLE hFile = CreateFile(
//       _T("nonexistent.txt"),
//       GENERIC_READ,
//       0,
//       NULL,
//       OPEN_EXISTING,
//       FILE_ATTRIBUTE_NORMAL,
//       NULL);

//   if (hFile == INVALID_HANDLE_VALUE)
//   {
//     ReportError(_T("Error opening file."), 0, TRUE);
//   }
//   else
//   {
//     CloseHandle(hFile);
//   }

//   return 0;
// }

// #if (WIN32_WINNT >= 0x600)
// #define WIN32_WINNT 0x600
// #else
// #if (WIN32_WINNT >= 0x500)
// #endif
// #endif
// #ifdef UNICODE
// #undef _UNICODE
// #endif
// #define LANG_DFLT_LANG_ENGLISH
// #include "ENVIORNMENT.h"
// #include <windows.h>
// #include <tchar.h>
// #include <stdio.h>
// #include <stdlib.h>

// #include <malloc.h> // memory allocation
// #include <io.h>
// #include <winsock2.h>
// #include "support.h"
// #include _MT
// #include <process.h>
// #endf
// #include "Everything.h"
// VOID ReportError(LPCTSTR userMessage, DWORD exitCode, BOOL printErrorMessage)
// {
//   DWORD eMsgLen, errNum = GetLastError();
//   LPSTR IpvSysMsg;
//   _ftprint(stderr, _t(% s \n), userMessage);
//   if (printErrorMessage)
//   {
//     eMsgLen = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMATE_MESSAGE_FROM_SYSTEM, NULL, errNum, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&lpsSysMsg, 0, NULL);
//     if (eMsgLen > 0)
//     {
//       _ftprint(stderr, T("%s\n", lpvSysMsg));
//     }
//     else
//     {
//       _ftprint(stderr, _T("LastErrorNumber ,%d\n", errNum));
//     }
//     if (lpvSysMsg != NULL)
//       LOCALFree(lpvSysMsg);
//   }
//   if (exitCode > 0)
//     ExitProcess(exitCode);
//   return;
// // }