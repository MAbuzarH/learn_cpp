#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define DIRNAME_LEN (MAX_PATH + 2)

//---------------------------------------------
// Function: printString
// Purpose:  Prints one or more strings to a console or file handle
//---------------------------------------------
BOOL printString(HANDLE hOut, ...)
{
    DWORD msgLen, count;
    LPCTSTR pMsg;
    va_list pMsgList; // variable argument list

    va_start(pMsgList, hOut); // initialize varargs

    // FIX: Proper parentheses for va_arg() + condition
    while ((pMsg = va_arg(pMsgList, LPCTSTR)) != NULL)
    {
        msgLen = lstrlen(pMsg); // get string length

        // FIX: 'WriteFile' and 'sizeof(TCHAR)' capitalization
        if (!WriteConsole(hOut, pMsg, msgLen, &count, NULL) &&
            !WriteFile(hOut, pMsg, msgLen * sizeof(TCHAR), &count, NULL))
        {
            va_end(pMsgList);
            return FALSE;
        }
    }

    va_end(pMsgList);
    return TRUE; // FIX: Added return TRUE when successful
}

//---------------------------------------------
// Function: PrintMsg
// Purpose:  Prints a single message to the output handle
//---------------------------------------------
BOOL PrintMsg(HANDLE hOut, LPCTSTR pMsg)
{
    return printString(hOut, pMsg, NULL);
}

//---------------------------------------------
// Function: ConsolePrompt
// Purpose:  Displays a message, reads user input from console
//---------------------------------------------
BOOL ConsolePrompt(LPCTSTR pPromptMsg, LPTSTR pResponse, DWORD maxChar, BOOL echo)
{
    HANDLE hIn, hOut;
    DWORD charIn;
    BOOL success;
    DWORD echoFlag;

    // Open console input
    hIn = CreateFile(
        _T("CONIN$"),
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    // Open console output
    hOut = CreateFile(
        _T("CONOUT$"),
        GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING, // FIX: Changed from CREATE_ALWAYS (don't overwrite console)
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (hIn == INVALID_HANDLE_VALUE || hOut == INVALID_HANDLE_VALUE)
    {
        _tprintf(_T("Error opening console.\n"));
        return FALSE;
    }

    // Configure console modes
    echoFlag = echo ? ENABLE_ECHO_INPUT : 0;

    success =
        SetConsoleMode(hIn, ENABLE_LINE_INPUT | echoFlag | ENABLE_PROCESSED_INPUT) &&
        SetConsoleMode(hOut, ENABLE_WRAP_AT_EOL_OUTPUT | ENABLE_PROCESSED_OUTPUT) &&
        printString(hOut, pPromptMsg, NULL) &&
        ReadConsole(hIn, pResponse, maxChar - 2, &charIn, NULL);

    if (success)
    {
        pResponse[charIn - 2] = _T('\0'); // replace newline with null terminator
    }
    else
    {
        _tprintf(_T("ConsolePrompt failure\n"));
    }

    CloseHandle(hIn);
    CloseHandle(hOut);
    return success;
}

//---------------------------------------------
// Function: main
// Purpose:  Prints the current directory path
//---------------------------------------------
int _tmain(int argc, TCHAR *argv[])
{
    TCHAR pwdBuffer[DIRNAME_LEN];
    DWORD lenCurDir;

    lenCurDir = GetCurrentDirectory(DIRNAME_LEN, pwdBuffer);

    if (lenCurDir == 0)
    {
        _tprintf(_T("Failure getting pathname\n"));
        return 1;
    }

    if (lenCurDir > DIRNAME_LEN)
    {
        _tprintf(_T("Pathname is too long.\n"));
        return 2;
    }

    PrintMsg(GetStdHandle(STD_OUTPUT_HANDLE), pwdBuffer);
    printString(GetStdHandle(STD_OUTPUT_HANDLE),"hi","Iam a print string",NULL);
    return 0;
}


// #include <windows.h>
// #include <tchar.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdarg.h>
// #define DIRNAME_LEN (MAX_PATH + 2)
// BOOL printString(HANDLE hOut, ...)
// {
//   DWORD msgLen, count;
//   LPCTSTR pMsg;
//   va_list pMsgList;         // current message list
//   va_start(pMsgList, hOut); // start processing msgs
//   while (pMsg = va_arg(pMsgList, LPCTSTR) != NULL)
//   {
//     msgLen = lstrlen(pMsg);
//     if (!WriteConsole(hOut, pMsg, msgLen, &count, NULL) && !writeFile(hOut, pMsg, msgLen * sizeOf(TCHAR), &count, NULL))
//     {
//       va_end(pMsgList);
//       return FALSE;
//     }
//   }
// }
// BOOL PrintMsg(HANDLE hOut, LPCTSTR pMsg)
// {
//   return printString(hOut, pMsg, NULL);
// }

// BOOL ConsolePrompt(LPCTSTR pPromptMsg, LPTSTR pResponse, DWORD maxChar, BOOL echo)
// {
//   HANDLE hIn, hOut;
//   DWORD charIn, echoFlag;
//   BOOL success;
//   hIn = CreateFile(
//       _T("CONIN$"),
//       GENERIC_READ | GENERIC_WRITE,
//       0,
//       NULL,
//       OPEN_EXISTING,
//       FILE_ATTRIBUTE_NORMAL,
//       NULL);

//   // Open output file for writing (create or overwrite)
//   hOut = CreateFile(
//       _T("CONOUT$"),
//       GENERIC_WRITE,
//       0,
//       NULL,
//       CREATE_ALWAYS,
//       FILE_ATTRIBUTE_NORMAL,
//       NULL);
//   echoFlag = echo ? ENABLE_ECHO_INPUT : 0;
//   success = SetConsoleMode(hIn, ENABLE_LINE_INPUT | echoFlag | ENABLE_PROCESSED_INPUT) && SetConsoleMode(hOut, ENABLE_WRAP_AT_EOL_OUTPUT | ENABLE_PROCESSED_OUTPUT) && printString(hOut, pPromptMsg, NULL) && ReadConsole(hIn, pResponse, maxChar - 2, &charIn, NULL);
//   if (success)
//   {
//     pResponse[charIn - 2] = _T('\0');
//   }
//   else
//   {
//     // ReportError(_T("ConsolePrompt failure"), 0, TRUE);
//     printf("ConsolePrompt failure");
//   }
//   CloseHandle(hIn);
//   CloseHandle(hOut);
//   return success;
// }

// int _tmain(int argc, TCHAR *argv[])
// {
//   TCHAR pwdBuffer[DIRNAME_LEN];
//   DWORD lenCurDir;
//   lenCurDir = GetCurrentDirectory(DIRNAME_LEN, pwdBuffer);
//   if (lenCurDir == 0)
//   { // ReportError(_T("faliure getting pathname"), 1, TRUE);
//     printf("faliure getting pathname");
//   }
//   if (lenCurDir > DIRNAME_LEN)
//   {
//     // ReportError(_T("pathname is too long."), 2, FALSE);
//     printf("pathname is too long.");
//   }
//   PrintMsg(GetStdHandle(STD_OUTPUT_HANDLE),pwdBuffer);
//   return 0;
// }
