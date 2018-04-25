#include<iostream>
#include<windows.h>
#include<cstring>
using namespace std;
int main()
{


MCIERROR me =
  mciSendString("open C:\\Users\\DUCS\\Downloads\\abc.mp3.mp3 type mpegvideo alias song1", 
     NULL, 0, 0);  

if(me == 0)
  {
  me =  mciSendString("play song1 wait", NULL, 0, 0);
  mciSendString("close song1", NULL, 0, 0);
  }
}
  
  
