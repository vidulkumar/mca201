#include<iostream>
#include<string>

using namespace std;

template <class T> class SLinkedList;
template <class T>
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
	  T elem; 
	  SNode<T>* next; 
	friend class SLinkedList<T>; // provides SLinkedList access to SNode
};

template <class T>
class SLinkedList { 
	/*   			
	objective: Create a Single LInked List class 
	input parameters: none
	output value: none
	side effects: Class SlinkedList defines Single Linked LIst class
	approach: Class definition
	*/
	private:
	SNode<T>* head;						// pointer to the head of list						
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
    
	const T& front() const; 			// get front element
	void addFront(const T& e) 		// add to front of list
	{ //SNode *temp= new SNode;
	 SNode<T> *newnod= new SNode<T>;
     newnod->elem=e;
     newnod->next=head;
     head=newnod;
     };
	void addBack(const T& e); 			// add to back of list
	void removeFront();			 			// remove from front 
	void removeEnd();						// remove from end
	void print(); 							// prints the SLL
	
};
template <class T>
const T& SLinkedList<T> :: front() const 			// get front element
   { if (head!=NULL)
    return head->elem;
	else
	return NULL;
	};
/*void SLinkedList :: addFront(const string& e); 		// add to front of list
   {SNode newnod= new SNode;
     newnod->elem=e;
     newnod->next=head;
     head=temp;
     };*/
template <class T>
void SLinkedList<T> :: addBack(const T& e) 			// add to back of list
    { SNode<T> *temp= new SNode<T>;
      SNode<T> *newnod= new SNode<T>;
      newnod->elem=e;
      newnod->next=NULL;
      if(head==NULL)
      { head=newnod;
	  }
	  else
	  {
	  
      temp=head;
      while(temp->next!=NULL)
      {temp=temp->next;};
      temp->next=newnod;
      }
    };
template <class T>
void SLinkedList<T> :: removeFront()			 			// remove from front
{ SNode<T> *temp= new SNode<T>;
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
template <class T> 
void SLinkedList<T> :: removeEnd()						// remove from end
{ SNode<T> *temp= new SNode<T>;
  if (head==NULL)
    return;
   else if (!head->next)
   {
   cout<<"deleted node is : "<<head->elem;
     head=NULL;
	 return;}
    else 
    temp=head;
  while(temp->next->next!=NULL)
    { temp=temp->next;
	  } ; 
	cout<<"deleted node is : "<<temp->next->elem;  
	temp->next=NULL;
};
template <class T>
void SLinkedList<T> :: print() 							// prints the SLL
{ SNode<T> *temp= new SNode<T>;
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
{ SLinkedList<string> sll;
  string ele;
  char ch;
 do { 
           cout<<"\n---------------Menu-------------------\n";
           cout<<"1. check if empty  \n";
           cout<<"2. print front   \n";
           cout<<"3. add front  \n";
           cout<<"4. add back  \n";
           cout<<"5. remove front  \n";
           cout<<"6. remove back  \n";
           cout<<"7. print sll  \n";
           cout<<"-----press e to exit ---- : ";
           cin>>ch;
           switch(ch)
             { 
               case '1' : if(sll.empty())
                            cout<<"linked list is empty";
                           else
						     cout<<"Linked list is not empty"; 
                          
                          break;
              case '2' :  if(!sll.empty())
			              cout<<"front element is : "<<sll.front();
                          break;
              case '3' :  cout<<"enter string to be added : ";
                           cin>>ele;
                           sll.addFront(ele);
                          break;
              case '4' :  cout<<"enter string to be added : ";
                          cin>>ele;
                          sll.addBack(ele);
                          break;
              case '5' : sll.removeFront();
                          break;
              case '6' : sll.removeEnd();
                          break;
              case '7' : sll.print();
                          break;            
              default :   if (ch!='e')
                           cout<<"no such option ";
                          break;

                };       

}while(ch!='e');


}


