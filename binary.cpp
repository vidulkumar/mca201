//: WAP to implement Binary Search Tree ( perform insert ,delete and display operations)

#include<iostream>

using namespace std;

struct bNode{ int data;
              bNode *left;
			  bNode *right; 
			  };
class BST { bNode *root=NULL; 
           public;
           void ins(bNode* root,int ele);
           int del();
           void disp();
            };
			
void BST :: ins(int ele)
    {  
       bNode newnode = new bNode;
       newnode->left=NULL;
       newnode->right=NULL;
	    if (root==head)
	       {
		   root=newnode;
	       return;
	       }
	    else
		 if (ele>root->data )
		   root=root->ight;
		 else (ele<root->data)
		   root=root->left;  
		   ins(*root,ele); 
		  return;
	};  						  

void BST :: del(bNode* root )

int main()
{
	cout<<"\"hello world";
	
}
