// Assignment 1 - FileInfoCopy - CS609 - Fall 2025
// Topic: File Information and Copy Utility using Windows API
// Objective: To demonstrate file creation, reading, copying, and information retrieval using Windows API functions.

#include <windows.h>
#include <stdio.h>

void PrintFileTime(FILETIME ft, const char *label)
{
    SYSTEMTIME stUTC, stLocal;
    FileTimeToSystemTime(&ft, &stUTC);
    SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);

    printf("%s: %02d-%02d-%04d %02d:%02d:%02d\n",
           label,
           stLocal.wDay, stLocal.wMonth, stLocal.wYear,
           stLocal.wHour, stLocal.wMinute, stLocal.wSecond);
}

int main()
{
    HANDLE hFile;
    DWORD bytesWritten, bytesRead;
    CHAR buffer[256];
    BOOL result;

    printf("=== File Information and Copy Utility ===\n\n");

    // 1️⃣ Create and open source.txt
    printf("Step 1: Creating and opening source.txt...\n");
    hFile = CreateFileA(
        "source.txt",
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (hFile == INVALID_HANDLE_VALUE)
    {
        printf("Error: Unable to create file (Error Code: %lu)\n", GetLastError());
        return 1;
    }

    printf("source.txt created successfully.\n");

    // 2️⃣ Write Student ID and Name
    const char *content = "Student ID: 123456\nName: Muhammad Abuzar\n";
    printf("Step 2: Writing student details into source.txt...\n");

    result = WriteFile(hFile, content, (DWORD)strlen(content), &bytesWritten, NULL);
    if (!result)
    {
        printf("Error: Unable to write to file (Error Code: %lu)\n", GetLastError());
        CloseHandle(hFile);
        return 1;
    }

    printf("Data written successfully (%lu bytes).\n", bytesWritten);

    // Close file
    CloseHandle(hFile);
    printf("source.txt closed successfully.\n\n");

    // 3️⃣ Open same file for reading
    printf("Step 3: Opening source.txt for reading...\n");
    hFile = CreateFileA(
        "source.txt",
        GENERIC_READ,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (hFile == INVALID_HANDLE_VALUE)
    {
        printf("Error: Unable to open file for reading (Error Code: %lu)\n", GetLastError());
        return 1;
    }

    printf("Reading file content...\n");

    result = ReadFile(hFile, buffer, sizeof(buffer) - 1, &bytesRead, NULL);
    if (!result)
    {
        printf("Error: Unable to read file (Error Code: %lu)\n", GetLastError());
        CloseHandle(hFile);
        return 1;
    }

    buffer[bytesRead] = '\0'; // Null terminate
    printf("Contents of source.txt:\n-------------------------\n%s\n-------------------------\n", buffer);

    CloseHandle(hFile);
    printf("source.txt closed after reading.\n\n");

    // 4️⃣ Copy file to destination.txt
    printf("Step 4: Copying source.txt to destination.txt...\n");

    if (CopyFileA("source.txt", "destination.txt", FALSE))
        printf("File copied successfully.\n\n");
    else
    {
        printf("Error: Unable to copy file (Error Code: %lu)\n", GetLastError());
        return 1;
    }

    // 5️⃣ Retrieve and display file information
    printf("Step 5: Retrieving file information...\n");

    WIN32_FIND_DATAA findDataSrc, findDataDest;
    HANDLE hFindSrc = FindFirstFileA("source.txt", &findDataSrc);
    HANDLE hFindDest = FindFirstFileA("destination.txt", &findDataDest);

    if (hFindSrc == INVALID_HANDLE_VALUE || hFindDest == INVALID_HANDLE_VALUE)
    {
        printf("Error: Unable to retrieve file info (Error Code: %lu)\n", GetLastError());
        return 1;
    }

    DWORD fileSizeSrc = GetFileSize(CreateFileA("source.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL), NULL);
    DWORD fileSizeDest = GetFileSize(CreateFileA("destination.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL), NULL);

    printf("\nSource File Information:\n");
    printf("------------------------\n");
    printf("File Size: %lu bytes\n", fileSizeSrc);
    printf("File Attributes: %lu\n", GetFileAttributesA("source.txt"));
    PrintFileTime(findDataSrc.ftCreationTime, "Created");
    PrintFileTime(findDataSrc.ftLastWriteTime, "Modified");
    PrintFileTime(findDataSrc.ftLastAccessTime, "Accessed");

    printf("\nDestination File Information:\n");
    printf("-----------------------------\n");
    printf("File Size: %lu bytes\n", fileSizeDest);
    printf("File Attributes: %lu\n", GetFileAttributesA("destination.txt"));
    PrintFileTime(findDataDest.ftCreationTime, "Created");
    PrintFileTime(findDataDest.ftLastWriteTime, "Modified");
    PrintFileTime(findDataDest.ftLastAccessTime, "Accessed");

    FindClose(hFindSrc);
    FindClose(hFindDest);

    // 6️⃣ Print current working directory
    printf("\nStep 6: Getting current directory...\n");
    CHAR currentDir[MAX_PATH];
    DWORD dirLength = GetCurrentDirectoryA(MAX_PATH, currentDir);
    if (dirLength == 0)
        printf("Error retrieving current directory (Error Code: %lu)\n", GetLastError());
    else
        printf("Current Directory: %s\n", currentDir);

    printf("\n=== Program completed successfully! ===\n");

    return 0;
}
