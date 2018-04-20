//WAP to write and read values using variables in/from file.
#include<iostream>
#include<fstream>
using namespace std;
int main()
{  float val;
   int ch;
    ofstream ostream("check.txt",ios::in|ios::trunc);
    ifstream instream("check.txt",ios::out);
    if(!ostream.is_open())
    {
        cout<<"file cannot be opened";
    }
    do
    {


    cout<<"\n-----------menu--------------";
    cout<<"\n1. write in to file";
    cout<<"\n2. read from  file ";
    cout<<"\n press 0 to exit ";
    cout<<"\nenter your choice ";
    cin>>ch;
    switch(ch)
    {

    case 1: cout<<"enter value you want to enter : ";
            cin>>val;
            ostream<<val;
            break;
    case 2: instream>>val;
            cout<<val;
            break;
    default : if(ch!=0)
             cout<<"no such option";
    };
    }while(ch!=0);

    ostream.close();
    instream.close();

}
