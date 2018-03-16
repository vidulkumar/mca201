#include <iostream>

#include <cstdlib>


#define SIZE 10



using namespace std;



class queue 
	/*   			

	objective: Create a class to implement Queue(circular) using dynamically created array 

	input parameters: none

	output value: none

	description:  Class definition

	approach: Class definition provides data member and member functions for the Queue class

	*/


{

	int *arr;			// array to store queue elements

	int capacity;			// maximum capacity of the Q

	int front;			// front points to front element in the Q

	int rear;			// rear points to last element in the Q

	int count;			// current size of the Q



public:

	queue(int size = SIZE)			// constructor
        { front=-1;
          rear=-1;
          arr= new int[SIZE];

           };

	~queue()
         {delete arr;
             }; 	

	void dequeue();

	void enqueue(int);

	int peek();  				// returns front element

	int size();				// returns current size of Q

	bool isEmpty();

	bool isFull();
    void pq();

};

bool queue::isFull()
             { 
               if(((rear==SIZE-1)&&(front==0))||(rear==front-1))
                return true;
               else 
                return false;

              };
     
void queue::enqueue(int ele)
             { if (isFull())
                {
                  cout<<"queue is full ";
                  return;
                 }
               else
                if(rear==SIZE-1&&front!=0)
                  {
                    rear=0;
                    arr[rear]=ele;
                  }
               else
                   arr[++rear]=ele;
                  return;
               };
bool queue::isEmpty()
              { 
                if(front=-1)
                 return true;
                else
                 return false; 
                };
   
void queue::dequeue()
             { if(isEmpty())
                 { cout<<"Queue is empty "; 
                   return;
                  }
              else 
               if(front==rear)
                 { cout<<"popped element is : "<<arr[front];
                   front=-1;
                   rear=front;  
                   return ;
                  }
               else if(front=SIZE-1)
                   { cout<<"popped element is : "<<arr[front];
                     front=0;
                     return;
                    }

              };

int queue::peek()
           { return arr[front];
             };

int queue::size()
           { count =rear-front+1;
            return count;
            };
void queue::pq()
           { for(int i=front;i<count;i=i%SIZE)
              cout<<arr[i]<<" ";
             
           }
int main()
    { 
      queue q;
      char ch; 
      int ele;  
      do { 
           cout<<"\n---------------Menu-------------------\n";
           cout<<"1. Enqueue  \n";
           cout<<"2. Dequeue  \n";
           cout<<"3. check size  \n";
           cout<<"4. check top element  \n";
           cout<<"5. print queue \n";
           cin>>ch;
           switch(ch)
             { 
               case '1' : 
                          cout<<"enter element : ";
                          cin>>ele; 
                          q.enqueue(ele);
                          break;
              case '2' :  q.dequeue();
                          break;
              case '3' :  ele=q.size();
                          break;
              case '4' :  ele=q.peek();
                          break;
              case '5' :  q.pq();
                          break;
              default :   break;

                };       

         }while(ch!='e');
       return 0;
     
       }  

