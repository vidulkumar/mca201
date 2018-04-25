#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
    WIN32_FIND_DATA data;
    HANDLE hFind=FindFirstFile("E:\\songs\\*",&data);
    if(hFind!=INVALID_HANDLE_VALUE)
    {
        do{
                cout<<data.cFileName<<endl;

        }while(FindNextFile(hFind,&data));
    }
}
