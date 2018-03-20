// check whether a string is palindrome or not
#include<iostream>
#include<stack>
#include<string>
#include<queue>
using namespace std;

int main()
{
  stack <char> s;
  queue <char> q;
  string str;
  int length; 
  cout<<"Enter the string you want to be checked : ";
  cin>>str;
  length=str.length();
  for (int i=0;i<length;i++)
   {
       s.push(str[i]);
       q.push(str[i]);    
     }
   int flag=1;
  for(int i=0;i<length&&flag==1;i++)
   {
      if(s.top()!=q.front())
      {
       cout<<"given string is not a plaindrome";
       flag=0;} 
     s.pop();
     q.pop();
     }
 if (flag==1)
  cout<<" given string is palindrome ";

 return 0;
 
 }

