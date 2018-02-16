#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

int preced(char c) 
  {
    /*
       objective : to return the precedence of the operator  passed
       return value: integer value from 1 to 3
       parameters passed : a  operatorof character type
   */
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
  cout<<"\nenter expression \n ";
  cin>>str;
 cout<<"\n expression you entered : ";
 for(int i=0;i<strlen(str);i++)
  {  cout<<str[i]; }
     cout<<endl;

 for( int i=0;i<strlen(str);i++) // for all charcters in the expression
  { 
    if ((str[i]!='(')&&(str[i]!=')')&&(str[i]!='^')&&(str[i]!='*')&&(str[i]!='/')&&(str[i]!='+')&&(str[i]!='-')) 
        {cout<<str[i];} //if it is not (,),^,*,/,+,- print it 
   else
       { 
       
         if(str[i]=='(')
            {s.push(str[i]);} // if it is not '(' push it on o stack
        else
         if(str[i]==')')//if it is equal to ')' pop until '('
           {  
             while(s.top()!='(')
             {cout<<s.top(); s.pop();};
              s.pop();
             
          }
        else
          if(!s.empty()&&s.top()!='(') // if it is a operator push it if it's precedence greater than operator om top
             {  if (preced(str[i])>preced(s.top()))
                    {s.push(str[i]);
                            }
                else{     
                      //otherwise pop the top operator
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
{  
   cout<<s.top(); s.pop();
  };
 cout<<endl; 
 return 0;
}








