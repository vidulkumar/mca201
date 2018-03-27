// WAP to implement Stack using SLL-----------------------------------------------------------
#include<iostream>
#include<string>

using namespace std;

class SNode { 
	/*   			
	objective: Create a class for a Node for Single Linked list
	input parameters: none
	output value: none
	description: SNode class defines the node structure 
	approach: Class defines data item is names element with datatype string 
			and link is named next pf snode type
	*/
	private:
	  string elem; 
	  SNode* next; 
	friend class SLinkedList; // provides SLinkedList access to SNode
};


class SLinkedList { 
	/*   			
	objective: Create a Single LInked List class 
	input parameters: none
	output value: none
	side effects: Class SlinkedList defines Single Linked LIst class
	approach: Class definition
	*/
	private:
	SNode* head; 							// pointer to the head of list						
	public:
	SLinkedList()							// empty list constructor
	{
	  head=NULL;
	}
	~SLinkedList()							// destructor
	{
	  delete head;
	};
	
	bool empty() const 					// is list empty?
    {
      if(head==NULL)
        return true;
      else
        return false;  
    };
    
	const string& front() const; 			// get front element
	void addFront(const string& e) 		// add to front of list
	{ //SNode *temp= new SNode;
	 SNode *newnod= new SNode;
     newnod->elem=e;
     newnod->next=head;
     head=newnod;
     };
	
	void removeFront();			 			// remove from front 
	
	void print(); 							// prints the SLL
	
};

const string& SLinkedList :: front() const 			// get front element
   { if (head!=NULL)
    return head->elem;
	else
	return NULL;
	};
void SLinkedList :: removeFront()			 			// remove from front
{ SNode *temp= new SNode;
   if(head==NULL)
     return;
    else if(head->next==NULL)
	 {
	 	cout<<"deleted node is : "<<head->elem;
	 	head=NULL;
	  return;
	  }
	  else 
	  {
	  temp=head;
	  head=head->next;
	  cout<<"deleted node is : "<<temp->elem;
	  return;
      }
 }; 

void SLinkedList :: print() 							// prints the SLL
{ SNode *temp= new SNode;
  if(head!=NULL)
  {
  
   temp=head;
   while(temp->next!=NULL)
   {
   	 cout<<" "<<temp->elem;
   	 temp=temp->next;
   };
   if (temp!=NULL)
    cout<<" "<<temp->elem;
  }
};

int main()
{ SLinkedList sll;
  string ele;
  char ch;
 do { 
           cout<<"\n---------------Menu-------------------\n";
           cout<<"1. check if empty  \n";
           cout<<"2. print top   \n";
           cout<<"3. push   \n";
           cout<<"4. pop  \n";
           cout<<"5. print stack  \n";
           cout<<"-----press e to exit ---- : ";
           cin>>ch;
           switch(ch)
             { 
               case '1' : if(sll.empty())
                            cout<<"stack is empty";
                           else
						     cout<<"stack is not empty"; 
                          
                          break;
              case '2' :  if(!sll.empty())
			              cout<<"element on top is : "<<sll.front();
                          break;
              case '3' :  cout<<"enter string to be pushed : ";
                           cin>>ele;
                           sll.addFront(ele);
                          break;
              case '4' : sll.removeFront();
                          break;
              case '5' : sll.print();
                          break;            
              default :   if (ch!='e')
                           cout<<"no such option ";
                          break;

                };       

}while(ch!='e');


}

