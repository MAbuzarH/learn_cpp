#include <windows.h>
#include <tchar.h>
#include <stdio.h>

void PrintFileTime(FILETIME ft)
{
  SYSTEMTIME stUTC, stLocal;
  FileTimeToSystemTime(&ft, &stUTC);
  SystemTimeToTzSpecificLocalTime(NULL, &ft, &stUTC);

  _tprintf(_T("%02d/%02d/%d %02d:%02d:%02d"), stLocal.wDay, stLocal.wMonth, stLocal.wYear, stLocal.wHour, stLocal.wMinute, stLocal.wSecond);
}

void PrintAttributes(DWORD attr)
{
  if (attr & FILE_ATTRIBUTE_DIRECTORY)
  {
    _tprintf(_T("<DIR> "));
  }
  if (attr & FILE_ATTRIBUTE_READONLY)
  {
    _tprintf(_T("[R] "));
  }
  if (attr & FILE_ATTRIBUTE_HIDDEN)
  {
    _tprintf(_T("[H] "));
  }
  if (attr & FILE_ATTRIBUTE_SYSTEM)
  {
    _tprintf(_T("[S] "));
  }
  if (attr & FILE_ATTRIBUTE_ARCHIVE)
  {
    _tprintf(_T("[A] "));
  }
}

int _tmain(int argc, TCHAR *argv[])
{
  WIN32_FIND_DATA findFileData;
  HANDLE hfind = INVALID_HANDLE_VALUE;
  TCHAR dirSpec[MAX_PATH];
  // If no argument, use current directory
  if (argc < 2)
  {
    _tcscpy(dirSpec, _T("*"));
  }
  else
  {
    _stprintf(dirSpec, _T("% s\\*"));
  }
  hfind = FindFirstFile(dirSpec, &findFileData);
  if (hfind == INVALID_HANDLE_VALUE)
  {
    _tprintf(_T("Error: Cannot open directory.\n"));
    return 1;
  }
  _tprintf(_T("Listing of %s\n\n"), (argc < 2) ? _T(".") : argv[1]);
  _tprintf(_T("%-30s %-10s %-20s %-20s\n"), _T("File Name"), _T("Size(Bytes)"), _T("Created"), _T("Modified"));
  _tprintf(_T("----------------------------------------------------------------------------------------\n"));

  do
  {
    LARGE_INTEGER fileSize;
    fileSize.LowPart = findFileData.nFileSizeLow;
    fileSize.HighPart = findFileData.nFileSizeHigh;

    _tprintf(_T("%-30s %-10lld"), findFileData.cFileName, fileSize.QuadPart);
    PrintFileTime(findFileData.ftCreationTime);
    _tprintf(_T("   "));
    PrintFileTime(findFileData.ftLastWriteTime);
    _tprintf(_T("   "));
    PrintAttributes(findFileData.dwFileAttributes);
    _tprintf(_T("\n"));

  } while (FindNextFile(hfind, &findFileData) != 0);
  FindClose(hfind);
  return 0;
}