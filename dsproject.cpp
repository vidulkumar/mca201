    /*

     * C++ Program to Implement Circular Doubly Linked List

     */

    #include<iostream>
    #include<cstdio>
   #include<cstdlib>
   #include<windows.h>
   #include<fstream>
    using namespace std;
    /*
     * Node Declaration
     */
    struct node
    {
        string track_name;
        struct node *next;
        struct node *prev;
    }*start, *last,*curr;
    int counter = 0;
    /*
     * Class Declaration
     */
    class playlist
    {
        public:
            node *create_node(string);
            void insert_last(string);
            void delete_pos();
            bool search(string file_name);
            void search();
            void shuffle();
            void nowplaying();
            void previous();
            void next();
            void display();
            void reverse();
            void sort();
            void updateplaylist();
            void saveplaylist();
            void initplaylist();
            playlist()
            {
                start = NULL;
                last = NULL;
            }
    };

    /*
     * Main: Contains Menu
     */
    int main()
    {
        int choice;
        playlist cdl;

         int ctr=-2;
        ofstream file;
      file.open ("example.txt",ios::in|ios::trunc);
      WIN32_FIND_DATA data;
      HANDLE hFind=FindFirstFile("G:\\Aashiqui 2 (2013)\\songs\\*",&data);

      if(hFind!=INVALID_HANDLE_VALUE)
     {
        do{     ++ctr;
                if(ctr>=1)
                file<<data.cFileName<<endl;
        }while(FindNextFile(hFind,&data));
     }
    file.close();
    cdl.initplaylist();
        while (1)
        {
            cout<<"\n-------------------------------"<<endl;
            cout<<"Operations on Doubly Circular linked list"<<endl;
            cout<<"\n-------------------------------"<<endl;
            cout<<"1.Now playing"<<endl;
            cout<<"2.Play Next "<<endl;
            cout<<"3.Play Previous"<<endl;
            cout<<"4.Update playlist"<<endl;
            cout<<"5.Delete at Position"<<endl;
            cout<<"6.Shuffle Playlist"<<endl;
            cout<<"7.Search song"<<endl;
            cout<<"8.Sort"<<endl;
            cout<<"9.Display List"<<endl;
            cout<<"10.Reverse List"<<endl;
            cout<<"11.(save file and )Exit"<<endl;
            cout<<"Enter your choice : ";
            cin>>choice;
            switch(choice)
            { case 1: cdl.nowplaying();
                      break;
            case 2:cdl.next();
                    break;
            case 3:cdl.previous() ;
                    break;
            case 4: cdl.updateplaylist();
                    break;
            case 5:
                    cdl.delete_pos();
                    break;
            case 6:
               cdl.shuffle();
               break;
            case 7:
                    cdl.search();
                  break;
            case 8:
                cdl.sort();
                break;
            case 9:
                cdl.display();
                break;
            case 10:
                cdl.reverse();
                break;
            case 11:
                cdl.saveplaylist();
                exit(1);
            default:
                cout<<"Wrong choice"<<endl;
            }
        }
        return 0;
    }

    /*
     *MEMORY ALLOCATED FOR NODE DYNAMICALLY
     */
    node* playlist::create_node(string file_name)
    {
        counter++;
        struct node *temp;
        temp = new(struct node);
        temp->track_name = file_name;
        temp->next = NULL;
        temp->prev = NULL;
        return temp;
    }

    /*
     *INSERTS ELEMNET AT LAST
     */
    void playlist::insert_last(string file_name)
    {

        //cout<<endl<<"Enter the song to be inserted: ";
        //cin>>file_name;
        if(!search(file_name)){
        struct node *temp;
        temp = create_node(file_name);
        if (start == last && start == NULL)
        {
            cout<<"song inserted in empty list"<<endl;
            start = last = temp;
            start->next = last->next = NULL;
            start->prev = last->prev = NULL;
        }
        else
        {   //cout<<"\n case2 executed ";
            last->next = temp;
            temp->prev = last;
            last = temp;
            start->prev = last;
            last->next = start;
        }
        }
    }
    /*
     *INSERTS song AT POSITION
     */void playlist::updateplaylist()
     {           int ctr2=1,songno,tracker=0;
         string line;
                 //string line;
                       cout<<"\n songs in folder are : ";
                        ifstream myfile ("example.txt");
                         if (myfile.is_open())
                         {
                          while ( getline (myfile,line) )
                          {
                          cout <<ctr2++<<". "<< line << '\n';
                           }
                           myfile.close();
                           }
                           cout<<"\n-------------------------\n";
                           myfile.open("example.txt");
                         do {
                            tracker=0;
                            cout<<"Enter number of song you want to add to playlist(zero to stop adding :) : ";
                              cin>>songno;
                              myfile.seekg(0,ios::beg);
                              if (songno<ctr2&&songno>0)
                            {while ( tracker!=songno )
                            {
                                 getline (myfile,line);
                                 tracker++;
                               };
                            insert_last(line);}
                           }   while(songno!=0);
     }


    /*
     * Delete Node at Particular Position
     */
    void playlist::delete_pos()
    {
        int pos, i;
        node *ptr, *s;
        if (start == last && start == NULL)
        {
            cout<<"List is empty, nothing to delete"<<endl;
            return;
        }
       cout<<endl<<"Enter the postion of song to be deleted: ";
       cin>>pos;
        if (counter < pos)
        {
            cout<<"Position out of range"<<endl;
            return;
        }
        s = start;
        if(pos == 1)
        {
            counter--;
            last->next = s->next;
            s->next->prev = last;
            start = s->next;
            free(s);
            cout<<"song Deleted"<<endl;
            return;
        }
        for (i = 0;i < pos - 1;i++ )
        {
            s = s->next;
            ptr = s->prev;
        }
        ptr->next = s->next;
        s->next->prev = ptr;
        if (pos == counter)
        {
            last = ptr;
        }
        counter--;
        free(s);
        cout<<"song Deleted"<<endl;
    }

    /*
     * Search song in the list
     */
    bool playlist::search(string file_name)
    {   //string file_name;
        int pos = 0,  i;
        bool flag = false;
        struct node *s;
        if (start == last && start == NULL)
        {
            //cout<<"The List is empty, nothing to search"<<endl;
            return false;
        }
       // cout<<endl<<"Enter the file_name to be searched: ";
        //cin>>file_name;
        s = start;
        for (i = 0;i < counter;i++)
        {
            pos++;
            if (s->track_name == file_name)
            {
              //  cout<<"song "<<file_name<<" found at position: "<<pos<<endl;

                flag = true;
                return true;
            }
            s = s->next;

        }

       if (!flag)
          {

            //cout<<"song not found in the list"<<endl;
            return false;
       }
    }

    void playlist::search()
    {   string file_name;
        int pos = 0,  i;
        bool flag = false;
        struct node *s;
        if (start == last && start == NULL)
        {
            cout<<"The List is empty, nothing to search"<<endl;
            return;
        }
        cout<<endl<<"Enter the file_name to be searched: ";
        cin>>file_name;
        s = start;
        for (i = 0;i < counter;i++)
        {
            pos++;
            if (s->track_name == file_name)
            {
                cout<<"song "<<file_name<<" found at position: "<<pos<<endl;

                flag = true;
          //      return true;
            }
            s = s->next;

        }

       if (!flag)
          {

            cout<<"song not found in the list"<<endl;
        //    return false;
       }
    }
    /*
     * Sorting Doubly Circular Link List
     */
    void playlist::sort()
    {
        struct node *temp, *s;
        int  i;
        string file_name;
        if (start == last && start == NULL)
        {
            cout<<"The List is empty, nothing to sort"<<endl;
            return;
        }
        s = start;
        for (i = 0;i < counter;i++)
        {
            temp = s->next;
            while (temp != start)
            {
                if (s->track_name > temp->track_name)
                {
                    file_name = s->track_name;
                    s->track_name = temp->track_name;
                    temp->track_name = file_name;
                }
                temp = temp->next;
            }
            s = s->next;
        }
    }
    /*

    * Display songs of the List
     */
   void playlist::display()
    {
        int i;
      struct node *s;
       if (start == last && start == NULL)
        {
           cout<<"The List is empty, nothing to display"<<endl;
          return;
        }
        s = start;
        for (i = 0;i < counter-1;i++)
         {  cout<<i+1<<". ";
            cout<<s->track_name<<"\n";
            s = s->next;
        }
        cout<<i+1<<". "<<s->track_name<<endl;
    }
    /*
     * Reverse Doubly Circular Linked List
     */
    void playlist::reverse()
    {
        if (start == last && start == NULL)
        {
            cout<<"The List is empty, nothing to reverse"<<endl;
            return;
        }
        struct node *p1, *p2;
        p1 = start;
        p2 = p1->next;
        p1->next = NULL;
        p1->prev = p2;
        while (p2 != start)
        {
            p2->prev = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p2->prev;
        }
        last = start;
        start = p1;
        cout<<"List Reversed"<<endl;
    }

void playlist::saveplaylist()
{     ofstream filep;
      filep.open ("playlist.txt",ios::in|ios::trunc);
      int i;
      struct node *s;
        s = start;
        for (i = 0;i < counter-1;i++)
         {  cout<<" . ";
            filep<<s->track_name<<"\n";
            s = s->next;
        }
        cout<<" . ";
        filep<<s->track_name<<endl;
    filep.close();
}
void playlist::initplaylist()
{
         string line;

                       cout<<"\n ----loading playlist from file ----: \n";
                        ifstream myfile ("playlist.txt",ios::in);
                         if (myfile.is_open())
                         {
                          while ( getline (myfile,line) )
                          {
                          insert_last(line);
                          cout<<"..";
                           };
                           myfile.close();
                           }
              if (start == last && start == NULL)
        {   curr =NULL;
            return;
        }
        else
        {
            curr=start;
        }


}
void playlist::shuffle()
{
    int x=rand()%counter;
    int y= rand()%counter;
    struct node *node1,*node2,*temp;
    node1=start;
    node2=last;
    for(int i=0;i<counter/2;i++)
    {

   x=rand();
    y= rand();
    while(!x==0)
    {   node1=node1->next;
        x--;
    };
    while(!y==0)
    {
        node2=node2->prev;
        y--;
    };

    temp=node1;


//struct node* temp;
  temp = node1->next;
  node1->next = node2->next;
  node2->next = temp;
  //if (node1->next != NULL)
    node1->next->prev = node1;
  //if (node2->next != NULL)
    node2->next->prev = node2;
  temp = node1->prev;
  node1->prev = node2->prev;
  node2->prev = temp;
  //if (node1->prev != NULL)
    node1->prev->next = node1;
  node2->prev->next = node2;
    }
}
void playlist::nowplaying()
{
    if(curr!=NULL)
        cout<<endl<<"Now Playing---------- "<<curr->track_name<<"---------\n";
    else
        cout<<endl<<"NO file loaded into playlist ";

}
void playlist::next()
{
    curr=curr->next;
    nowplaying();
}
void playlist::previous()
{
    curr=curr->prev;
    nowplaying();

}
