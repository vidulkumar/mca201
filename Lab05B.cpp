//WAP to implement Stack using STL Queues
#include<iostream>
#include<queue>

using namespace std;

class stack 
           {   
             
             queue <int> q;
             
             public:
                
                bool isEmpty();
                void push(int ele);
                void pop();
                int top();
                int size(); 
                void printstack();
           };
bool stack::isEmpty()
       { return q.empty();
       
        };
                   
void stack::push(int ele)
        { int s;
          queue <int> tq;
          s=q.size();
          for(int i=0;i<s;i++)
          {  tq.push(q.front());
             q.pop();
          }
          q.push(ele);
          for(int i=0;i<s;i++)
          {  q.push(tq.front());
             tq.pop();
          }
        }; 
void stack::pop() 
        {  
          q.pop();
        
        };                          
int stack::top()
       {
         return q.front();
       };       
int stack::size()
      {
         return q.size();
      };
void stack::printstack()
      { int s;
         
          queue <int> tq;
          tq=q;
          s=q.size();
          for(int i=0;i<s;i++)
          {  cout<<tq.front()<<" ";
             tq.pop();
          }
        
      };         
      
int main()
{ stack s;
  int ele;
  char ch;
  int size;
 do { 
           cout<<"\n---------------Menu-------------------\n";
           cout<<"1. push  \n";
           cout<<"2. pop  \n";
           cout<<"3. check size  \n";
           cout<<"4. check top element  \n";
           cout<<"5. print stack  \n";
           cout<<"-----press e to exit ---- : ";
           cin>>ch;
           switch(ch)
             { 
               case '1' : 
                          cout<<"enter element : ";
                          cin>>ele; 
                          s.push(ele);
                          break;
              case '2' :  cout<<"popped element is : "<<s.top();
                          s.pop();
                          break;
              case '3' :  size=s.size();
                          cout<<size;
                          break;
              case '4' :  ele=s.top();
                          cout<<ele;
                          break;
              
              case '5' : s.printstack();
                          break;            
              default :   if (ch!='e')
                           cout<<"no such option ";
                          break;

                };       

}while(ch!='e');


}
      
          
