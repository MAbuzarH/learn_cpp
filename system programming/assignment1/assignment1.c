#include <windows.h>
#include <tchar.h>
#include <stdio.h>

// Assignment 1 - FileInfoCopy - CS609 - Fall 2025

int main()
{
  HANDLE hFile;
  DWORD bytesWritten, bytesRead;
  CHAR buffer[256];
  BOOL result;

  printf("=== File Information and Copy Utility ===\n\n");

  // step1 create or open sourse.txt
  hFile = CreateFileA("source.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

  if (hFile == INVALID_HANDLE_VALUE)
  {
    printf("Error: Unable to create file (Error Code: %lu)\n", GetLastError());
    return 1;
  }
  printf("source.txt created successfully.\n");

  // 2 Write Student ID and Name

  const char *content = "BC220401629-Syed Muhammad Abuzar Haider\n";
  printf("Writing student details into source.txt...\n");

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
  printf("closing source.txt successfully after writing...\n\n");

  // step 3 Open same file for reading
  printf("Step 3: Opening source.txt for reading...\n");

  hFile = CreateFileA("source.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
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

  printf("Contents of source.txt:%s", buffer);

  CloseHandle(hFile);
  printf("source.txt closed after reading.\n\n");

  // 4 Copy file to destination.txt
  printf("Copying source.txt to destination.txt...\n");

  if (CopyFileA("source.txt", "destination.txt", FALSE))
  {
    printf("File copied successfully.\n\n");
  }
  else
  {
    printf("Error: Unable to copy file (Error Code: %lu)\n", GetLastError());
    return 1;
  }

  // retrieve and display file information
  printf("Geting file information...\n");

  DWORD fileSizeSrc = GetFileSize(CreateFileA("source.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL), NULL);
  DWORD fileSizeDest = GetFileSize(CreateFileA("destination.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL), NULL);

  // file size
  printf("Source.txt  Size: %lu bytes\n", fileSizeSrc);
  printf("destination.txt Size: %lu bytes\n", fileSizeDest);
  // file attributes
  printf("Source.txt Attributes: %lu\n", GetFileAttributesA("source.txt"));
  printf("destination.txt Attributes: %lu\n", GetFileAttributesA("destination.txt"));

  // get current directory
  CHAR currentDir[MAX_PATH];
  DWORD dirLength = GetCurrentDirectoryA(MAX_PATH, currentDir);
  if (dirLength == 0)
    printf("Error retrieving current directory (Error Code: %lu)\n", GetLastError());
  else
    printf("Current Working Directory: %s\n", currentDir);

  printf("\n=== Program completed successfully! ===\n");

  return 0;
}