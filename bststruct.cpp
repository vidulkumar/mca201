//: WAP to implement Binary Search Tree ( perform insert ,delete and display operations)

#include<iostream>

using namespace std;

struct B_root{ int data;
              B_root *left;
			  B_root *right;
			  } ;


void ins(B_root* &root,int ele)
    {
       B_root* newroot = new B_root;
       newroot->left=NULL;
       newroot->right=NULL;
       newroot->data=ele;
	    if (root==NULL)
	       { cout<<"\nelement inserted";
		   root=newroot;
	       return;
	       }
	    else
		 if (ele > root->data )
		   {
		    ins(root->right,ele);
		   }
		 else
           if (ele <  root->data)
		   {
		   ins(root->left,ele);

		   }
		   //cout<<"element inserted";
		  return;
	};
B_root* find_max(B_root *root)
{
    while(root->right)
    {
        root=root->right;
    };
    return root;
};
void del(B_root* &root,int ele )
{   B_root* temp= new B_root;
    if (root==NULL)
        cout<<"\ndata not found";
    else if(ele > root->data)
         del(root->right,ele);
    else if(ele <root->data)
         del(root->left,ele);
    else
    { // cout<<"\nroot deleted is :"<<root->data;

       if(root->left==NULL)
          root=root->right;
       else if(root->right==NULL)
          root=root->left;
       else if(root->left&&root->right)
           {
            temp=find_max(root->left);
            root->data= temp->data;
            del(root->left,root->data);
            //delete temp;
         }
    }
};

void preorder(B_root *root)
{ if(node==NULL)
     return;
  cout<<root->data;
  if(root->left)
    preorder(root->left);
  if(root->right)
    preorder(root->right);
};

void postorder(B_root *root)
{ if(node==NULL)
     return;
  if(root->left)
    preorder(root->left);
  if(root->right)
    preorder(root->right);
    cout<<root->data;
};

void inorder(B_root *root)
{ if(node==NULL)
     return;
  if(root->left)
    preorder(root->left);
 cout<<root->data;
  if(root->right)
    preorder(root->right);
};
void display(B_root *node,int level=1)
{   if(node==NULL)
     return;

    if(node->right)
    display(node->right,level+2);
    cout<<"\n";
    --level;
    for(int i=1;i<level;i++)
        cout<<"   ";
    cout<<node->data;
    if(node->left)
    display(node->left,level+3);
    return;
}

int main()
{  B_root *root=NULL;
   int ch,ele;
   do{
   cout<<"\n-----------BST____MENU-------------";
   cout<<"\n1. Insert an element      " ;
   cout<<"\n2. Delete an element      " ;
   cout<<"\n3. Display Tree           " ;
   cout<<"\n4. Print tree in Preorder " ;
   cout<<"\n5. Print tree in Postorder" ;
   cout<<"\n6. Print tree in Inorder  " ;
   cout<<"\n0. Quit                   " ;
   cout<<"\nEnter your choice : ";
   cin>>ch;
   switch(ch)
   {
   case 1 : cout<<"\n Enter element you want to insert : ";
            cin>>ele;
            ins(root,ele);
            break;
   case 2 : cout<<"\n Enter element you want to delete : ";
            cin>>ele;
            del(root,ele);
            break;
   case 3 : cout<<"\n  ";
            display(root);
            break;
   case 4 : cout<<"\n Preorder : ";
            preorder(root);
            break;
   case 5 : cout<<"\n Postorder : ";
            postorder(root);
            break;
   case 6 : cout<<"\n Inorder : ";
            inorder(root);
            break;
   default : if(ch!=0)
              cout<<"\n No Such Option ";

   }
   }while(ch!=0);


}
