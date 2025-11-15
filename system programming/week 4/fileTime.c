#include <windows.h>
#include <stdio.h>

void showTime(SYSTEMTIME st)
{
  printf("%02d-%02d-%04d %02d:%02d:%02d\n",
         st.wDay, st.wMonth, st.wYear,
         st.wHour, st.wMinute, st.wSecond);
}

void optionMenu(WIN32_FIND_DATA fileData)
{
  int choice;
  SYSTEMTIME stUTC, stLocal;
  printf("\nChoose what to display:\n");
  printf("1. Access Time (A)\n");
  printf("2. Modified Time (M)\n");
  printf("3. Creation Time (C)\n");
  printf("4. All (AMC)\n");
  printf("5. Exit\n");

  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    FileTimeToSystemTime(&fileData.ftLastAccessTime, &stUTC);
    SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
    printf("\nAccess Time (A): ");
    showTime(stLocal);
    break;
  case 2:
    FileTimeToSystemTime(&fileData.ftLastWriteTime, &stUTC);
    SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
    printf("\nModified Time (M): ");
    showTime(stLocal);
    break;
  case 3:
    FileTimeToSystemTime(&fileData.ftCreationTime, &stUTC);
    SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
    printf("\nCreation Time (C): ");
    showTime(stLocal);
    break;
  case 4:
    printf("\n--- File Time Details (AMC) ---\n");
    FileTimeToSystemTime(&fileData.ftCreationTime, &stUTC);
    SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
    printf("Created:   ");
    showTime(stLocal);

    FileTimeToSystemTime(&fileData.ftLastWriteTime, &stUTC);
    SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
    printf("Modified:  ");
    showTime(stLocal);

    FileTimeToSystemTime(&fileData.ftLastAccessTime, &stUTC);
    SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
    printf("Accessed:  ");
    showTime(stLocal);
    break;
  case 5:
    printf("Exiting menue...\n");
    return;

  default:
    printf("Invalid choies\n");
  }
}

int main()
{
  WIN32_FIND_DATA fileData;
  HANDLE hFind;
  char fileName[MAX_PATH];

  printf("Enter a file name (with extension): ");
  scanf("%s", fileName);

  hFind = FindFirstFile(fileName, &fileData);

  if (hFind == INVALID_HANDLE_VALUE)
  {
    printf("File not found.\n");
    return 1;
  }
  printf("\nFile: %s\n", fileData.cFileName);
  optionMenu(fileData);
  FindClose(hFind);
  return 0;
}