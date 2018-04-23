#include<iostream>
#include<fstream>
#include<cstdio>

using namespace std;

int main()
{   char ch,line[10];
    int choice;
    int pos;
    
	fstream st("test.txt",ios::in|ios::out);

	
	st<<"abcdefghijklmnopqrstuvxyz";
    
    
    
	   do{
   
    cout<<"\n-----------menu--------------";
   cout<<"\n1. see current position of get pointer";
     cout<<"\n2. see current position of put pointer";
    cout<<"\n3. give position of put pointer wrt beg";
    cout<<"\n4. give position of get pointer wrt beg";
	cout<<"\nenter your choice ";
    cin>>choice;
    switch(choice)
    {

    case 1: cout<<endl<<st.tellp();
            break;
    case 2: cout<<endl<<st.tellg();
            break;
    case 3: cout<<"\nenter positon you want : ";
            cin>>pos;
		    st.seekp(pos,ios::beg);
			cout<<"\nenter your input at the position ";
			cin>>line;
            st<<line;
            break;
    case 4: cout<<"\nenter positon you want : ";
            cin>>pos;
		    st.seekg(pos,ios::beg);
			while(!st.eof())
		    {   
		         st.get(ch);
		         cout << ch;
		    
		      };
            break;
    default : if(choice!=0)
             cout<<"no such option";
    };
    }while(choice!=0);
    /*st.seekg(10,ios::beg);
	while(!st.eof())
    {   
         st.get(ch);
         cout << ch;
    
      };
	cout<<st.tellp();
	  */
	   	
}
