// #include <stdio.h>
// #include <stdlib.h>
// #include <windows.h>

// #define BUFF_SIZ 16384
// int main(int argc, char *argv[])
// {
//   HANDLE hIn, hOut;
//   DWORD nIn, nOut; // tels us number of bites we have in/output
//   CHAR buf[BUFF_SIZ];
//   LPWSTR lpwszFile1, lpwszFile2;
//   // LPWSTR long pointer wide string ,wide mean=> 1 byte = 16 bit use to stre unicode
//   INT iLen1, iLen2;

//   if (argc != 3)
//   {
//     fprintf(stderr, "Usage:cp file1 file2 \n");
//     return 1;
//   }
//   lpwszFile1 = (LPTSTR)malloc(510);
//   lpwszFile2 = (LPTSTR)malloc(510);
//   // in windows we say ASSCI multi byte charecter string
//   iLen1 = MultiByteToWideChar(CP_ACP, 0, argv[1], -1, lpwszFile1, 510);
//   iLen2 = MultiByteToWideChar(CP_ACP, 0, argv[2], -1, lpwszFile2, 510);
//   // we do above step bc window api ask us to provid a wide string as argument

//   hIn = CreateFile(lpwszFile1, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//   if (hIn == INVALID_HANDLE_VALUE)
//   {
//     fprintf(stderr, "cannot open input file :%s", GetLastError());
//     return 2;
//   }

//   hOut = CreateFile(lpwszFile2, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
//   if (hOut == INVALID_HANDLE_VALUE)
//   {
//     fprintf(stderr, "cannot open output file :%x", GetLastError());
//     return 3;
//   }

//   while (ReadFile(hIn, buf, BUFF_SIZ, &nIn, NULL) && nIn > 0)
//   {
//     WriteFile(hOut, buf, nIn, &nOut, NULL);
//     if (hIn != hOut)
//     {
//       fprintf(stderr, "Flat write error :%x", GetLastError());
//       CloseHandle(hIn);
//       CloseHandle(hOut);
//       return 4;
//     }
//   }

//   CloseHandle(hIn);
//   CloseHandle(hOut);
//   return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define BUFF_SIZ 16384 // Increased buffer size for better performance with Windows API

int main(int argc, char *argv[])
{
    // Initialize handles to an invalid state
    HANDLE hIn = INVALID_HANDLE_VALUE;
    HANDLE hOut = INVALID_HANDLE_VALUE;
    // DWORD variables for number of bytes read/written
    DWORD nIn, nOut; 
    // Buffer for file data
    CHAR buf[BUFF_SIZ]; 

    // Pointers for dynamically allocated wide character file names (required by CreateFileW)
    LPWSTR lpwszFile1 = NULL;
    LPWSTR lpwszFile2 = NULL;
    
    // For storing the length of the converted wide strings
    INT iLen1, iLen2; 

    // 1. Argument Check
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s file1 file2 \n", argv[0]);
        return 1;
    }

    // 2. Allocate memory for wide string file names (512 bytes is enough for two max-length wide strings)
    lpwszFile1 = (LPWSTR)malloc(512); 
    lpwszFile2 = (LPWSTR)malloc(512);

    // Check if memory allocation succeeded
    if (lpwszFile1 == NULL || lpwszFile2 == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        if (lpwszFile1) free(lpwszFile1);
        if (lpwszFile2) free(lpwszFile2);
        return 9; 
    }
    
    // Convert multibyte (char*) arguments to wide string (LPWSTR).
    // The buffer size is given in WCHAR count (512 bytes / 2 bytes per WCHAR)
    iLen1 = MultiByteToWideChar(CP_ACP, 0, argv[1], -1, lpwszFile1, 512 / sizeof(WCHAR));
    iLen2 = MultiByteToWideChar(CP_ACP, 0, argv[2], -1, lpwszFile2, 512 / sizeof(WCHAR));

    // Check if conversion succeeded
    if (iLen1 == 0 || iLen2 == 0) {
        fprintf(stderr, "Error converting filenames to wide characters: %lu\n", GetLastError());
        free(lpwszFile1);
        free(lpwszFile2);
        return 10;
    }

    // 3. Open Input File (CreateFileW is the Unicode version)
    hIn = CreateFileW(
        lpwszFile1, 
        GENERIC_READ, 
        FILE_SHARE_READ, 
        NULL, 
        OPEN_EXISTING, 
        FILE_ATTRIBUTE_NORMAL, 
        NULL
    );
    if (hIn == INVALID_HANDLE_VALUE)
    {
        // FIX: Changed %s to %lu (unsigned long) for the numeric error code
        fprintf(stderr, "Cannot open input file. Error code: %lu\n", GetLastError());
        free(lpwszFile1);
        free(lpwszFile2);
        return 2;
    }

    // 4. Open Output File
    hOut = CreateFileW(
        lpwszFile2, 
        GENERIC_WRITE, 
        0, // No sharing for the output file during write
        NULL, 
        CREATE_ALWAYS, // Creates new file or overwrites existing one
        FILE_ATTRIBUTE_NORMAL, 
        NULL
    );
    if (hOut == INVALID_HANDLE_VALUE)
    {
        fprintf(stderr, "Cannot open output file. Error code: %lu\n", GetLastError());
        CloseHandle(hIn); // Clean up the input handle
        free(lpwszFile1);
        free(lpwszFile2);
        return 3;
    }

    // 5. Main Copy Loop: ReadFile returns non-zero on success. Loop continues while bytes are read (nIn > 0).
    while (ReadFile(hIn, buf, BUFF_SIZ, &nIn, NULL) && nIn > 0)
    {
        // Attempt to write the data that was just read (nIn bytes)
        // FIX: Check return value of WriteFile AND ensure nOut (bytes written) matches nIn (bytes read)
        if (!WriteFile(hOut, buf, nIn, &nOut, NULL) || nOut != nIn)
        {
            // Error occurred: either WriteFile failed, or it didn't write all the bytes
            fprintf(stderr, "File write error. Bytes written: %lu. Error code: %lu\n", 
                nOut, GetLastError());

            // Clean up resources
            CloseHandle(hIn);
            CloseHandle(hOut);
            free(lpwszFile1);
            free(lpwszFile2);
            return 4;
        }
    }
    
    // Check if the loop ended because of a read error (not just EOF)
    if (GetLastError() != ERROR_SUCCESS) {
        fprintf(stderr, "File read error during copy loop. Error code: %lu\n", GetLastError());
        CloseHandle(hIn);
        CloseHandle(hOut);
        free(lpwszFile1);
        free(lpwszFile2);
        return 5;
    }

    // 6. Clean Up
    CloseHandle(hIn);
    CloseHandle(hOut);
    
    // FIX: Free the allocated memory to prevent memory leaks
    free(lpwszFile1);
    free(lpwszFile2);
    
    return 0;
}
