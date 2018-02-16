#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int preced(char c)
  {
    if(c=='^')
      return 3;
    else 
       if(c=='*'||c=='/')
       return 2;
   else 
      return 1;
   }

int main()

{ char str[20]; int l;
  stack <char> s;
  cout<<"\n enter length of expression ";
  cin>>l;
  cout<<"\nenter expression \n ";
  for(int i=0;i<l;i++)
  {  cin>>str[i]; }
 cout<<"\n expression you entered : ";
 for(int i=0;i<l;i++)
  {  cout<<str[i]; }
cout<<endl;

 for( int i=0;i<l;i++)
  { //cout<<" main loop \n working on  "<<str[i];
  if ((str[i]!='(')&&(str[i]!=')')&&(str[i]!='^')&&(str[i]!='*')&&(str[i]!='/')&&(str[i]!='+')&&(str[i]!='-'))
       {cout<<str[i];}
 else
   { //cout<<" else part :";
       
      if(str[i]=='(')
       {s.push(str[i]);/*cout<<" pushed "<<str[i];*/}
      if(str[i]==')')
       {while(s.top()!='(')
           {cout<<s.top(); s.pop();};
         s.pop();
         s.pop(); 
         }
   else
    if(!s.empty()&&s.top()!='(') 
    {  if (preced(str[i])>preced(s.top()))
           {s.push(str[i]);// cout<<" pushed "<<str[i];
             }
       else{
            //while(!s.empty()||preced(str[i])<=preced(s.top()))
            {cout<<s.top(); s.pop();}
            s.push(str[i]);//cout<<" pushed "<<str[i];
           }    
     }
    else 
     {
      s.push(str[i]);//cout<<" pushed "<<str[i];
         }
   }
    

   }
while(!s.empty())
{cout<<s.top(); s.pop();};

return 0;
}








