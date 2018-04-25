#include<iostream>
#include<windows.h>
#include<cstring>
using namespace std;
int main()
{

After much trial and error, the following works for me:

LPCWSTR a = L"open cannon.mp3 type mpegvideo";                  

int error = 99;                  

error = mciSendString(a, NULL,0,0);                  

int error2;                  

LPCWSTR b = L"play cannon.mp3";                

error2 = mciSendString(b, NULL, 0, 0)
}
  
