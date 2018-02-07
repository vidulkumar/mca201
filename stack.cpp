#include <iostream>
#include <cstdlib>
#define MAXSIZE 100  // or const int MAXSIZE=100;

using namespace std;


class stack
	/*
	objective: Create a class for implementing Stack using array
	input parameters: none
	output value: none
	description:  class definition
	approach: Class defines data member and member function of the stack class
	*/
     {
	int *arr;					// for dynamic array 
	int top;
	int capacity;					// checks size defined by user
public:
	stack(int size = MAXSIZE) // constructor to create array dynamically
             {top =-1;
              capacity=size; 
              arr= new int [MAXSIZE];  
              };			
	~stack()      					// destructor to delete dynamically created array
	{
           delete arr;

           }
        void push(int ele)
             { if (top==capacity)
                 cout<<"error ";
               else 
                   top++;
                   arr[top] =ele;
            
              };
	int pop()
             {  if (top ==-1) {
                   	cout<<"Under flow ";
                	return 0 ;}
                int ele;
                ele=arr[top];
cout<<" popped "<<ele;
                top=top-1;
                return ele; 
              
              };
	int peek()
            {
              return arr[top];

             };
	int size()	// Current size of stack
              {
                 return top;
               };				
	bool isEmpty()
              {if (top==-1)
                 return 1;
               };
	bool isFull()
              { if (top==capacity)
                 return 1;
               };

};

int main()
{ stack s;
int a =2;
  if(s.isEmpty())
     cout<<"\nstack is empty ";
  s.push(a);
  cout<<"\ntop element is "<<s.peek();
  s.push(3);
  cout<<"\ntop element is "<<s.peek();
  s.pop();

  return 0;
}


