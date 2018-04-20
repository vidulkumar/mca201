//Lab 09_B: WAP to write and read object using read and write function.
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Employee{
        int EmpNo;
        char EmpName[20];
        char Department[10];
       };

void readrec()
{   Employee x;
    ifstream in("record.txt",ios::in|ios::app);
    if(!in.is_open())
    {
      cerr<<"file can't be opened";
    }
    //in.read((char*)&x,sizeof(Employee));
    cout<<"empno|           |empname|        |department|\n";
    in.read((char*)&x,sizeof(x));
    while(!in.eof())
    {
	
   cout<<x.EmpNo<<" "<<x.EmpName<<" "<<x.Department<<"\n";
   in.read((char*)&x,sizeof(x));
    };
};
void writerec()
{   Employee x;
    ofstream out("record.txt",ios::in|ios::app);
    if(!out.is_open())
    {
      cerr<<"file can't be opened";
    }

    cout<<"\nenter employee number : ";
    cin>>x.EmpNo;
    cout<<"\nenter employee name   : ";
    cin>>x.EmpName;
    cout<<"\nenter employee Department : ";
    cin>>x.Department;
    out.write((char*)&x,sizeof(x));
    //out<<" ";
    //out.write((char*)&x.EmpName,sizeof(x.EmpName));
    //out<<" ";
    //out.write((char*)&x.Department,sizeof(x.Department));
    //out<<" ";
    out.close();
}

int main()
{   int ch;
   
   do{
   
    cout<<"\n-----------menu--------------";
    cout<<"\n1. write in to file";
    cout<<"\n2. read all records from  file ";
    cout<<"\n press 0 to exit ";
    cout<<"\nenter your choice ";
    cin>>ch;
    switch(ch)
    {

    case 1: writerec();
            break;
    case 2: readrec();
            break;
    default : if(ch!=0)
             cout<<"no such option";
    };
    }while(ch!=0);


return 0;
}
