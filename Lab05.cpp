//WAP to implement templated QUEUE class

#include<iostream>
#include<cstdlib>
# define SIZE 10
using namespace std;
template <class T>
class queue{
              T *data;
              int front;
              int rear;
              
              public:
                  queue()
                  { front= -1 ;
                    rear = front;
                    data = new T[SIZE]; 
                    };
                  ~queue()
                  {
                  delete data;
                  };
                  T first();
                  T last();
                  bool isFull();
                  bool isEmpty();
                  int size();
                  void printq();
                  void enq(T ele);
                  T    dq();

            };
template<class T>            
T queue<T>::first()
  { if (front==-1)
       return NULL;
    else   
    return data[front];
     } ;
template<class T>
T queue<T>::last()
  { if (front==-1)
       return NULL;
    else 
       return data[rear];   
  };     
template<class T>
int queue<T>::size()
  {   if (front==-1)
         return 0;
      else    
       return rear-front+1;
  };
template<class T>  
bool queue<T>::isFull()
  { if (size()==SIZE)
      return true;
    else 
      return false;  
   };   
template<class T>   
bool queue<T>::isEmpty()
  { if (size()==0)
      return true;
    else 
      return false;  
  };   
template<class T>  
void queue<T>::enq(T ele)
   { if (front==-1)
       {
         front=0;
         rear=front;
         data[front]=ele;
         return;
          }
      else if(isFull())
         {
         cout<<"queue is Full";
            return;
           } else 
              { data[++rear]=ele;
                return;
                } 
   } ;
template<class T>   
T queue<T>::dq()  
  { if (isEmpty())
      {
        cout<<"queue is empty ";
        return NULL;       
       }
    else
      {
        return data[front++];
      }  
     } ; 
template<class T>     
void queue<T>::printq()                
      { if (isEmpty())
         {
         cout<<"queue is empty";
         return ;
          }
         else
         {
         for(int i=front;front<=rear;front++)
          {
          cout<<data[i]<<" ";
           }
         } 
        return; 
      } ;     
int main()
{
  queue <char> q;
  char ele;
  char ch;
 do { 
           cout<<"\n---------------Menu-------------------\n";
           cout<<"1. Enqueue  \n";
           cout<<"2. Dequeue  \n";
           cout<<"3. check size  \n";
           cout<<"4. check front element  \n";
           cout<<"5. check last element";
           cout<<"6. print queue \n";
           cout<<"-----press e to exit ---- : ";
           cin>>ch;
           switch(ch)
             { 
               case '1' : 
                          cout<<"enter element : ";
                          cin>>ele; 
                          q.enq(ele);
                          break;
              case '2' :  q.dq();
                          break;
              case '3' :  ele=q.size();
                          cout<<ele;
                          break;
              case '4' :  ele=q.first();
                          cout<<ele;
                          break;
              case '5'   :  ele=q.last();
                          cout<<ele;
                          break;            
              case '6' :  q.printq();
                          break;
              default :   if (ch!='e')
                           cout<<"no such option ";
                          break;

                };       

}while(ch!='e');


}
