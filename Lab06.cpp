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
	
	bool empty() const; 					// is list empty?
    {
      if(head==NULL)
        return true;
      else
        return false;  
    };
    
	const string& front() const; 			// get front element
	void addFront(const string& e); 		// add to front of list
	void addBack(const string& e); 			// add to back of list
	void removeFront();			 			// remove from front 
	void removeEnd();						// remove from end
	void print(); 							// prints the SLL
	
};

const string& SLinkedList :: front() const; 			// get front element
   {return head;};
void SLinkedList :: addFront(const string& e); 		// add to front of list
   {SNode newnod= new SNode;
     newnod->elem=e;
     newnod->next=head;
     head=temp;
     };
void SLinkedList :: addBack(const string& e); 			// add to back of list
    { SNode temp= new SNode;
      SNode newnod= new SNode;
      newnod->elem=e;
      newnod->next=NULL;
      temp=head;
      while(temp!=NULL)
      {temp=temp->next;};
      
    
    
    };
void SLinkedList :: removeFront();			 			// remove from front 
void SLinkedList :: removeEnd();						// remove from end
void SLinkedList :: print(); 							// prints the SLL

