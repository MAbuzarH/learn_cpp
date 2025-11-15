#include <windows.h>
#include <stdio.h>

int main()
{
  HANDLE hFile;
  DWORD bytesWritten;
  const char *data = "This File is locked by the current process. \n";

  printf("=== File Locking Demonstration ===\n\n");

  // create or open a file for reading and writing
  hFile = CreateFileA("lockedfile.txt", GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

  if (hFile == INVALID_HANDLE_VALUE)
  {
    printf("Error: Unable to create/open file (Error Code: %lu)\n", GetLastError());
    return 1;
  }

  printf("File 'lockedfile.txt' created successfully.\n");

  // write initial data
  WriteFile(hFile, data, (DWORD)strlen(data), &bytesWritten, NULL);
  printf("Data written to file (%lu bytes).\n", bytesWritten);

  // 3 Lock the file region (simulate exclusive access)
  OVERLAPPED ov = {0};
  DWORD lockStart = 0;
  DWORD lockLength = 100; // lock first 100 bytes

  if (LockFile(hFile, lockStart, 0, lockLength, 0))
  {
    printf("File region [0 - 100 bytes] locked successfully.\n");
  }
  else
  {
    printf("Error: Unable to lock file (Error Code: %lu)\n", GetLastError());
    CloseHandle(hFile);
    return 1;
  }

  printf("\nFile is now locked. Try opening 'lockedfile.txt' in another program (e.g., Notepad).\n");
  printf("It will fail until the lock is released.\n");

  // 4 Wait to simulate another operation
  printf("\nSimulating processing (file locked)...\n");
  Sleep(5000); // 5 seconds delay

  // 5 Unlock the file region
  if (UnlockFile(hFile, lockStart, 0, lockLength, 0))
  {
    printf("File region unlocked successfully.\n");
  }
  else
    printf("Error: Unable to unlock file (Error Code: %lu)\n", GetLastError());

  // 6 Close handle
  CloseHandle(hFile);
  printf("File closed successfully.\n");

  printf("\n=== File Locking Demonstration Completed ===\n");
  
  return 0;
}
