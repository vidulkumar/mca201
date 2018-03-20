//program to implement circular queue
/*
Name-Vidul
class-mca sem 2
roll no - 42
*/
#include <iostream>

#include <cstdlib>


#define SIZE 5



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
    
        void pq(); //prints queue

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
               else if(rear==-1&&front==-1) //if queue is empty
                  {rear=0;front=0;arr[front]=ele;}
               else
                if(rear==SIZE-1&&front!=0)  //if rear has reached end of array but front is not zero
                  {
                    rear=0;
                    arr[rear]=ele;
                  }
               else
                   {
       
                   arr[++rear]=ele;}
                  return;
               };
bool queue::isEmpty()
              { 
                if(front==-1)
                 return true;
                else
                 return false; 
                };

int queue::size()
           {if (front ==-1) //if queue is empty
            {
            return 0;} 
            if (rear<front) // if rear has crossed end of array i.e. started from zero
             return SIZE-front+rear+1;
            else
            {count =rear-front+1;}
            return count;
            };
   
void queue::dequeue()
             { if(isEmpty())
                 { cout<<"Queue is empty "; 
                   return;
                  }
              else 
               if(front==rear) //if there is only single element
                 { 
                   cout<<"popped element is : "<<arr[front];
                   front=-1;
                   rear=front;  
                   return ;
                  }
               else if(front==SIZE-1&&size()>1) //if front has reached end of array but element queue contains more elements 
                   {
                     cout<<"popped element is : "<<arr[front];
                     front=0;
                     return;
                    }
               else
                  {  
                     cout<<"popped element is : "<<arr[front];
                     front=front+1;
                     
                     return;
                    }

              };

int queue::peek()
           { return arr[front];
             };


void queue::pq()
           { int flag=0;
             if( front==-1) //if queue is empty
               return;
            for(int i=front;flag!=1;i++)
               { i=i%SIZE;
                 cout<<arr[i]<<" ";
                 if (i==rear) // i has traced whole queue
                   flag=1;
            
                  }
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
           cout<<"4. check front element  \n";
           cout<<"5. print queue \n";
           cout<<"-----press e to exit ---- : ";
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
                          cout<<ele;
                          break;
              case '4' :  ele=q.peek();
                          cout<<ele;
                          break;
              case '5' :  q.pq();
                          break;
              default :   if (ch!='e')
                           cout<<"no such option ";
                          break;

                };       

         }while(ch!='e');
       
      return 0;
     
       }  


