/*
Objective: to push elements on stack and then popping them out to print in reverse order
User inputs : size- size of stack, num - to be used multiple times to push  elements on stack

*/

#include<iostream>
#include<stack>
using namespace std;

int main()
{

int num, size;
stack <int> s;
cout<<"Enter size of the stack ";
cin>>size;
cout<<"ENTER ELEMENTS IN STACK : ";
for(int i=0;i<size;i++)
{
    cin>>num;
    s.push(num);
  
}
cout<<"Elements in stack are : ";

while(s.empty()!=true) 
 {   cout<<s.top()<<" ";
     s.pop(); 
  }



}
