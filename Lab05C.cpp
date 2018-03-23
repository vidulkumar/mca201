// WAP to implement Queue using STL Stacks
#include<iostream>
#include<stack>
using namespace std;
class queue
         {
           int last;
           stack<int> s;
         public:
           void enq(int ele);
           void dq();
           int front();//returns element in front 
           bool isEmpty();
           int size();         
           int rear(); 
           void pq();
         };
 
bool queue::isEmpty()
     {
       return s.empty();
      };

int queue::size()
     {
       return s.size();
     };               
 
int queue::rear()
     {
      return last;
     };

int queue::front()
     {
     return s.top();     
     }; 
void queue::enq(int ele)
     { last=ele;
        int temp;
        int sz=s.size();
        stack <int> ts;
        for(int i=0;i<sz;i++)
          { temp=s.top();
            s.pop();
            ts.push(temp);
          }
         s.push(ele);
        for(int i=0;i<sz;i++)
          { temp=ts.top();
            ts.pop();
            s.push(temp);
          }

      }; 
void queue::dq()
     {
       s.pop();
     
     };      
void queue::pq()            
     {
      stack<int> st;
      st=s;
      int sz=st.size();
      for(int i=0;i<sz;i++)
      { cout<<" "<<st.top();
        st.pop();        
       }
            
     }; 
     
int main()
{ queue q;
  int ele;
  char ch;
  int size;
 do { 
           cout<<"\n---------------Menu-------------------\n";
           cout<<"1. enqueue  \n";
           cout<<"2. dequeue  \n";
           cout<<"3. check size  \n";
           cout<<"4. check front element  \n";
           cout<<"5. check rear element \n";
           cout<<"6. check if empty\n";
           cout<<"7. print queue  \n";
           cout<<"-----press e to exit ---- : ";
           cin>>ch;
           switch(ch)
             { 
               case '1' : 
                          cout<<"enter element : ";
                          cin>>ele; 
                          q.enq(ele);
                          break;
              case '2' :  cout<<"popped element is : "<<q.front();
                          q.dq();
                          break;
              case '3' :  size=q.size();
                          cout<<size;
                          break;
              case '4' :  ele=q.front();
                          cout<<ele;
                          break;
              case '5' :  ele=q.rear();
                          cout<<ele;
                          break;
              case '6' :  if(q.isEmpty())
                            cout<<"empty";
                          else
                          cout<<"not empty";
                          break;               
              case '7' :  q.pq();
                          break;            
              default :   if (ch!='e')
                           cout<<"no such option ";
                          break;

                };       

}while(ch!='e');


}     
     
             
              
