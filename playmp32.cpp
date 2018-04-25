#include<iostream>
#include<windows.h>
#include<cstring>
using namespace std;
int main()
{
 MCIERROR a= mciSendString("open E:\\songs\\abcdef.mp3 type mpegvideo alias song1",NULL,0,0);
   if (a==0)
   {
       a=mciSendString("play song1 wait",NULL,0,0);
       mciSendString("close song1", NULL,0,0);
   }

}
