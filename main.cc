// @file main.cc
// @brief COM port opner.
// @author Mamoru Kaminaga
// @date 2017-11-04
// Copyright 2017 Mamoru Kaminaga
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <windows.h>


bool OpenComPort8(int to_open_port_num) {
  if ((to_open_port_num <= 0) || (to_open_port_num > 8)) return false;

  // COM port is opened.
  HKEY hkey = nullptr;
  DWORD dwdisposition;

  LONG result = RegCreateKeyEx(
      HKEY_LOCAL_MACHINE,
      L"SYSTEM\\CurrentControlSet\\Control\\COM Name Arbiter",
      0,
      nullptr,
      REG_OPTION_VOLATILE,
      KEY_ALL_ACCESS,
      nullptr,
      &hkey,
      &dwdisposition);
  if (result != ERROR_SUCCESS) return false;

  // COM port is read.
  DWORD old_port_flags = 0x00;
  DWORD size = static_cast<int>(sizeof(old_port_flags));

  result = RegQueryValueEx(
      hkey,
      L"ComDB",
      nullptr,
      nullptr,
      (LPBYTE) &old_port_flags,
      &size);
  if (result != ERROR_SUCCESS) return false;

  // COP port flag is set.
  uint8_t port_mask = ~(0x01 << (to_open_port_num - 1));
  uint8_t port_flags = static_cast<uint8_t>(old_port_flags) & port_mask;

  wprintf(L"Old: %d", static_cast<int>(old_port_flags));

  // COM port is closed.
  RegCloseKey(hkey);

  return true;
}

int main(int argc, char* argv[]) {

  int to_open_port_num = 0;
  wprintf(L"Which COM port to open? (1 - 8)\n");
  wprintf(L">");
  wscanf_s(L"%d", &to_open_port_num);
  fflush(stdin);

  if (!OpenComPort8(to_open_port_num)) {
    wprintf(L"Failed to open COM%d\n", to_open_port_num);
    system("pause");

    return -1;
  }

  wprintf(L"Opened COM%d\n", to_open_port_num);
  system("pause");

  return 0;
}
