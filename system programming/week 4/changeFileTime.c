#include <windows.h>
#include <tchar.h>
#include <stdio.h>

int _tmain(int argc, TCHAR *argv[])
{
  HANDLE hfile;
  FILETIME ftCreate, ftAccess, ftWrite, ftCurrent;
  SYSTEMTIME stUTC, stLocal;

  if (argc < 2)
  {
    _tprintf(_T("Usage: SetFileTimeExample <filename>\n"));
    return 1;
  }

  // Step 1: Open or create the file
   hfile = CreateFile(argv[1],
                       GENERIC_READ | GENERIC_WRITE,
                       0,
                       NULL,
                       OPEN_ALWAYS,
                       FILE_ATTRIBUTE_NORMAL,
                       NULL);

  if (hfile = INVALID_HANDLE_VALUE)
  {
    _tprintf(_T("Error opening file. Error code: %lu\n"), GetLastError());
    return 2;
  }

  // Step 2: Retrieve current system time in FILETIME format (UTC)
  GetSystemTimeAsFileTime(&ftCurrent); // This gets time directly as FILETIME

  // Optional: You can also use GetSystemTime + SystemTimeToFileTime
  // GetSystemTime(&stUTC);
  // SystemTimeToFileTime(&stUTC, &ftCurrent);

  // Step 3: Display current system time for understanding
  FileTimeToSystemTime(&ftCurrent, &stUTC);
  _tprintf(_T("Current UTC Time: %02d/%02d/%d %02d:%02d:%02d\n"),
           stUTC.wDay, stUTC.wMonth, stUTC.wYear,
           stUTC.wHour, stUTC.wMinute, stUTC.wSecond);

  // Step 4: Retrieve existing file times (before changing)
  if (!GetFileTime(hfile, &ftCreate, &ftAccess, &ftWrite))
  {
    _tprintf(_T("Failed to get file time. Error code: %lu\n"), GetLastError());
    CloseHandle(hfile);
    return 3;
  }

  // step5: Set all three time(creation,Access,Write) to current time;
  if (!SetFileTime(hfile, &ftCurrent, &ftCurrent, &ftCurrent))
  {
    _tprintf(_T("Error setting file time. Error code: %lu\n"), GetLastError());
    CloseHandle(hfile);
    return 4;
  }

  _tprintf(_T("File times successfully updated to current UTC time.\n"));

  // Step 6: Verify by reading again
  GetFileTime(hfile, &ftCreate, &ftAccess, &ftWrite);
  FileTimeToSystemTime(&ftCreate, &stUTC);
  _tprintf(_T("New Creation Time: %02d/%02d/%d %02d:%02d:%02d\n"),
           stUTC.wDay, stUTC.wMonth, stUTC.wYear,
           stUTC.wHour, stUTC.wMinute, stUTC.wSecond);

  CloseHandle(hfile);
  return 0;
}