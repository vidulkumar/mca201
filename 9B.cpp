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

    in.read((char*)&x.EmpNo,sizeof(x.EmpNo));
    //out<<"|";
    in.read((char*)&x.EmpName,sizeof(x.EmpName));
    //out<<"|";
    in.read((char*)&x.Department,sizeof(x.Department));
    //out<<"\n";
   cout<<x.EmpNo<<" "<<x.EmpName<<" "<<x.Department;
}
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
    out.write((char*)&x.EmpNo,sizeof(x.EmpNo));
    out<<" ";
    out.write((char*)&x.EmpName,sizeof(x.EmpName));
    out<<" ";
    out.write((char*)&x.Department,sizeof(x.Department));
    out<<" ";
    out.close();
}

int main()
{
  readrec();
  writerec();
  readrec();
  writerec();


return 0;
}
