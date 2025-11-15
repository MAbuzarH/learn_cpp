// ConsoleHandlerDemo.c
// Demonstrates handling Ctrl+C, Close, Logoff, and Shutdown events
#include <windows.h>
#include <stdio.h>

BOOL WINAPI ConsoleHandler(DWORD ctrType)
{
  switch (ctrType)
  {
  case CTRL_C_EVENT:
    printf("Ctrl+C detected! Cleaning up before exit...\n");
    return TRUE; // TRUE = event handled; don’t terminate
  case CTRL_BREAK_EVENT:
    printf("Ctrl+Break detected! Ignoring...\n");
    return TRUE;
  case CTRL_CLOSE_EVENT:
    printf("Console window is being closed. Saving data...\n");
    Sleep(2000); // simulate cleanup delay
    return TRUE;
  case CTRL_LOGOFF_EVENT:
    printf("User is logging off. Shutting down safely...\n");
    return TRUE;
  case CTRL_SHUTDOWN_EVENT:
    printf("System is shutting down. Performing final tasks...\n");
    return TRUE;
  default:
    return FALSE; // Not handled
  }
}

int main()
{
  if (SetConsoleCtrlHandler(ConsoleHandler, TRUE))
  {
    printf("Console control handler registered successfully.\n");
  }
  else
  {
    printf("Failed to register handler. Error: %lu\n", GetLastError());
    return 1;
  }
  printf("Program running. Try pressing Ctrl+C or closing the console...\n");
  printf("Press 'q' to quit manually.\n");
  char ch;
  do
  {
    ch = getchar();
  } while (ch != 'q');

  printf("Exiting program normally.\n");
  return 0;
}