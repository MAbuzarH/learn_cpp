// ExceptionDemo.c
// Demonstrates Structured Exception Handling (SEH) and Filter Expressions in Windows
// Using Windows API functions for error reporting
//given code only work on visual studio 
#include <windows.h>
#include <stdio.h>

void ReportError(LPCSTR msg)
{
    DWORD err = GetLastError();
    LPVOID lpMsgBuf;

    FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        err,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPSTR)&lpMsgBuf,
        0,
        NULL);

    printf("%s\nError %lu: %s\n", msg, err, (char *)lpMsgBuf);
    LocalFree(lpMsgBuf);
}

// Custom filter function
LONG WINAPI ExceptionFilter(EXCEPTION_POINTERS *ep)
{
    DWORD code = ep->ExceptionRecord->ExceptionCode;

    printf("\n[Filter] Exception caught! Code: 0x%08lX\n", code);

    // You can decide how to handle specific exceptions here
    switch (code)
    {
    case EXCEPTION_ACCESS_VIOLATION:
        printf("[Filter] Access Violation detected!\n");
        return EXCEPTION_EXECUTE_HANDLER; // Handle the exception
    case EXCEPTION_INT_DIVIDE_BY_ZERO:
        printf("[Filter] Division by Zero detected!\n");
        return EXCEPTION_EXECUTE_HANDLER;
    default:
        printf("[Filter] Unknown exception, continuing search...\n");
        return EXCEPTION_CONTINUE_SEARCH; // Pass it up the chain
    }
}

int main()
{
    printf("=== Structured Exception Handling Demo ===\n\n");

    __try
    {
        printf("1️⃣ Creating a file using Windows API...\n");

        HANDLE hFile = CreateFileA(
            "seh_demo.txt",
            GENERIC_WRITE,
            0,
            NULL,
            CREATE_ALWAYS,
            FILE_ATTRIBUTE_NORMAL,
            NULL);

        if (hFile == INVALID_HANDLE_VALUE)
        {
            ReportError("Error creating file");
        }
        else
        {
            const char *text = "This file was created before an exception occurred.\n";
            DWORD written;
            WriteFile(hFile, text, (DWORD)strlen(text), &written, NULL);
            CloseHandle(hFile);
        }

        printf("\n2️⃣ Simulating a division by zero exception...\n");
        int x = 5, y = 0;
        int result = x / y; // This triggers EXCEPTION_INT_DIVIDE_BY_ZERO
        printf("Result: %d\n", result);

        printf("\n3️⃣ Simulating access violation...\n");
        int *ptr = NULL;
        *ptr = 10; // This triggers EXCEPTION_ACCESS_VIOLATION
    }

    __except (ExceptionFilter(GetExceptionInformation()))
    {
        printf("\n[Handler] Exception handled safely. Continuing program...\n");
    }

    __finally
    {
        printf("\n[Finally] Cleaning up resources (executed whether exception occurs or not)...\n");
    }

    printf("\nProgram continues normally after exception handling.\n");
    printf("=== End of Exception Handling Demo ===\n");
    return 0;
}
