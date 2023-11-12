#include "popup.h"

#include <iostream>

int popup(std::string data, std::string title, bool sound){
  if(sound) PlaySound("notification.wav",NULL,SND_FILENAME|SND_ASYNC); 
  return MessageBox(HWND_TOP, title.data(), data.data(), 1);
}
