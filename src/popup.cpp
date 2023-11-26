#include "popup.h"

#include <iostream>

void popup(std::string data, std::string title, std::string url, bool sound){
  if(sound) PlaySound("notification.wav",NULL,SND_FILENAME|SND_ASYNC); 
  int clicked = MessageBox(HWND_TOP, title.data(), data.data(), MB_ICONINFORMATION | MB_OK);
  if(clicked == IDOK) ShellExecute(NULL, "open", url.data(), NULL, NULL, SW_SHOWNORMAL);
  return;
}
