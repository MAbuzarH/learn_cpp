#include <stdio.h>
#include <windows.h>
#include <tchar.h> // Needed for TCHAR and _T macros

#define STRING_SIZ 256

// ========================== STRUCT DEFINITIONS ==========================

typedef struct _RECORD
{
    DWORD referenceCount;              // How many times record has been referenced
    SYSTEMTIME recordCreationTime;     // When record was created
    SYSTEMTIME recordLastReferenceTime;// Last time it was accessed
    SYSTEMTIME recordUpdateTime;       // Last time it was updated
    TCHAR dataString[STRING_SIZ];      // Actual string data stored in record
} RECORD;

typedef struct _HEADER
{
    DWORD numRecords;         // Total number of records in the file
    DWORD numNonEmptyRecords; // How many records are actually used
} HEADER;

// ========================== ERROR HANDLING FUNCTION ==========================

void ReportError(LPCTSTR userMessage, DWORD exitCode, BOOL printErrorMessage)
{
    DWORD errNum = GetLastError();
    LPTSTR lpSysMsg = NULL;

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

// ========================== MAIN FUNCTION ==========================

int _tmain(int argc, TCHAR *argv[])
{
    HANDLE hFile;
    LARGE_INTEGER currentPtr;
    DWORD OpenOption, nXfer, recNo;
    RECORD record = {0};
    TCHAR string[STRING_SIZ], command;
    HEADER header = {0};
    OVERLAPPED ov = {0}, ovZero = {0};
    SYSTEMTIME currentTime;
    BOOL headerChange = FALSE, recordChange = FALSE;
    BOOL prompt = (argc <= 3);

    // ========================== OPENING FILE ==========================
    if (argc < 2)
    {
        ReportError(_T("Usage: RecordAccess file [nrec]"), 1, FALSE);
    }

    // If third argument (record count) provided, create new file
    if (argc >= 3 && _ttoi(argv[2]) > 0)
    {
        OpenOption = CREATE_ALWAYS;
    }
    else
    {
        OpenOption = OPEN_EXISTING;
    }

    hFile = CreateFile(argv[1], GENERIC_READ | GENERIC_WRITE, 0, NULL, OpenOption, FILE_FLAG_RANDOM_ACCESS, NULL);

    if (hFile == INVALID_HANDLE_VALUE)
    {
        ReportError(_T("Cannot open file"), 2, TRUE);
    }

    // ========================== CREATE NEW FILE ==========================
    if (OpenOption == CREATE_ALWAYS)
    {
        header.numRecords = _ttoi(argv[2]);
        header.numNonEmptyRecords = 0;

        if (!WriteFile(hFile, &header, sizeof(HEADER), &nXfer, &ovZero))
        {
            ReportError(_T("Error writing header"), 3, TRUE);
        }

        // Extend file size to hold all records
        currentPtr.QuadPart = (LONGLONG)sizeof(RECORD) * header.numRecords + sizeof(HEADER);
        if (!SetFilePointerEx(hFile, currentPtr, NULL, FILE_BEGIN))
        {
            ReportError(_T("Error setting file pointer"), 4, TRUE);
        }

        if (!SetEndOfFile(hFile))
        {
            ReportError(_T("Error extending file"), 5, TRUE);
        }

        _tprintf(_T("Empty file with %lu records created.\n"), header.numRecords);
        CloseHandle(hFile);
        return 0;
    }

    // ========================== READ EXISTING FILE HEADER ==========================
    if (!ReadFile(hFile, &header, sizeof(HEADER), &nXfer, &ovZero))
    {
        ReportError(_T("Error reading header"), 6, TRUE);
    }

    _tprintf(_T("File %s contains %lu non-empty records (of %lu total)\n"), argv[1], header.numNonEmptyRecords, header.numRecords);

    // ========================== MAIN LOOP ==========================
    while (TRUE)
    {
        _tprintf(_T("\nEnter r(read)/w(write)/d(delete)/q(quit) and record number eg w 2: "));
        _tscanf(_T(" %c %lu"), &command, &recNo);

        if (command == _T('q'))
            break;

        if (recNo >= header.numRecords)
        {
            _tprintf(_T("Record number too large. Try again.\n"));
            continue;
        }

        currentPtr.QuadPart = (LONGLONG)recNo * sizeof(RECORD) + sizeof(HEADER);
        ov.Offset = currentPtr.LowPart;
        ov.OffsetHigh = currentPtr.HighPart;

        if (!ReadFile(hFile, &record, sizeof(RECORD), &nXfer, &ov))
        {
            ReportError(_T("Error reading record"), 7, TRUE);
        }

        GetSystemTime(&currentTime);
        record.recordLastReferenceTime = currentTime;

        // ========================== READ ==========================
        if (command == _T('r'))
        {
            if (record.referenceCount == 0)
            {
                _tprintf(_T("Record %lu is empty.\n"), recNo);
            }
            else
            {
              // GetLocalTime(&record.recordCreationTime);
                _tprintf(_T("Record %lu data: %s\nCreation Time: %02d/%02d/%d %02d:%02d:%02d\n"), recNo, record.dataString,record.recordCreationTime.wDay,
         record.recordCreationTime.wMonth,
         record.recordCreationTime.wYear,
         record.recordCreationTime.wHour,
         record.recordCreationTime.wMinute,
         record.recordCreationTime.wSecond);
            }
        }

        // ========================== WRITE ==========================
        else if (command == _T('w'))
        {
            _tprintf(_T("Enter new data string: "));
            _fgetts(string, STRING_SIZ, stdin);
            string[_tcslen(string) - 1] = '\0'; // Remove newline

            record.referenceCount++;
            record.recordUpdateTime = currentTime;
            if (record.referenceCount == 1)
                record.recordCreationTime = currentTime;

            _tcsncpy(record.dataString, string, STRING_SIZ - 1);
            recordChange = TRUE;
            headerChange = TRUE;
            header.numNonEmptyRecords++;
        }

        // ========================== DELETE ==========================
        else if (command == _T('d'))
        {
            if (record.referenceCount == 0)
            {
                _tprintf(_T("Record %lu already empty.\n"), recNo);
            }
            else
            {
                record.referenceCount = 0;
                record.dataString[0] = '\0';
                header.numNonEmptyRecords--;
                recordChange = TRUE;
                headerChange = TRUE;
                GetLocalTime(&currentTime);
                _tprintf(_T("Record %lu deleted. at: %02d/%02d/%d %02d:%02d:%02d\n"), recNo,currentTime.wDay,
               currentTime.wMonth,
                currentTime.wYear,
                currentTime.wHour,
                currentTime.wMinute,
                currentTime.wSecond );
            }
        }

        // ========================== WRITE UPDATES ==========================
        if (recordChange)
        {
            if (!WriteFile(hFile, &record, sizeof(RECORD), &nXfer, &ov))
            {
                ReportError(_T("Error writing record"), 8, TRUE);
            }
        }

        if (headerChange)
        {
            if (!WriteFile(hFile, &header, sizeof(HEADER), &nXfer, &ovZero))
            {
                ReportError(_T("Error updating header"), 9, TRUE);
            }
        }

        _tprintf(_T("Now file contains %lu non-empty records.\n"), header.numNonEmptyRecords);
    }

    CloseHandle(hFile);
    return 0;
}
