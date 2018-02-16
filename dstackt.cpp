#include <iostream>
#include <cstdlib>
#define MAXSIZE 100  // or const int MAXSIZE=100;

using namespace std;

template <typename T>
class stack
	/*
	objective: Create a class for implementing Stack using array
	input parameters: none
	output value: none
	description:  class definition
	approach: Class defines data member and member function of the stack class
	*/
     {
	T *arr;					// for dynamic array 
	int top;
	int capacity;					// checks size defined by user
public:
	stack(int size = MAXSIZE) // constructor to create array dynamically
             {top =-1;
              capacity=size; 
              arr= new T [MAXSIZE];  
              };			
	~stack()      					// destructor to delete dynamically created array
	{
           delete arr;

           }
        void push(T ele)
             { if (top==capacity)
                 cout<<"error ";
               else 
                   top++;
                   arr[top] =ele;
            
              };
	T pop()
             {  if (top ==-1) {
                   	cout<<"Under flow ";
                	return 0 ;}
                T ele;
                ele=arr[top];
cout<<" popped "<<ele;
                top=top-1;
                return ele; 
              
              };
	T peek()
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
{ stack <char> s;
 
  if(s.isEmpty())
     cout<<"\nstack is empty ";
  s.push('a');
  cout<<"\ntop element is "<<s.peek();
  s.push('b');
  cout<<"\ntop element is "<<s.peek();
  s.pop();
  cout<<"\nafter popping top element is "<<s.peek();
  s.pop();
  cout<<endl;
  return 0;
}
