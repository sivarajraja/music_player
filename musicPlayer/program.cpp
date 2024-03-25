#include<bits/stdc++.h>
#define ll long long

using namespace std;

class playlist{             // define the structure of playlist
    public:
    string song_name;
    playlist *prev;
    playlist *next;

};

string temp_name;

playlist *head = NULL;
playlist *current = NULL;

void add_music(){

    cout<<endl;
    cout<<"\tENTER MUSIC NAME :";
    cin>>temp_name;

    playlist *new_node = new playlist;
    new_node->song_name = temp_name;

    if(head == NULL){
        new_node->prev = new_node->next = new_node;
        head = current = new_node;
        return;
    }

    else{

        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
        current = new_node;
    }

}

void delete_music(){

    if(head == NULL){
        cout<<endl;
        cout<<"\tEMPTY PLAYLIST"<<endl;
        return;
    }

    cout<<endl;
    cout<<"\tENTER MUSIC NAME TO DELETE :";
    cin>>temp_name;

    playlist *temp = head->next;

    if(head->song_name == temp_name){       //head node is a deleting node

        head->next->prev = head->prev;
        head->prev->next = head->next;

        if(head != head->next){
        head = head->next;
        }
        else{
            head = NULL;
        }
        cout<<endl;
        cout<<"\tMUSIC DELETED"<<endl;
        return;
    }

    else{

    while(temp!=head){
        if(temp->song_name == temp_name){

            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;

            if(current == temp){
                current = temp->prev;
            }
            cout<<endl;
            cout<<"\tMUSIC DELETED"<<endl;
            return;
        }
        temp = temp->next;
    }
    }
    cout<<endl;
    cout<<"\t***MUSIC NOT FOUND ***"<<endl;
}

void show_playlist(){

    if(head == NULL){
        cout<<endl;
        cout<<"\tEMPTY PLAYLIST"<<endl;
        return;
    }

    playlist *temp = head;
    int count = 1;

    cout<<endl;
    cout<<"\tSONGS IN PLAYLIST"<<endl;
    cout<<endl;

    do
    {
        cout<<"\t"<<count<<". "<<temp->song_name<<endl;
        temp = temp->next;
        count++;

    } while(temp!=head);

}

void next_song(){

    if(head == NULL){
        cout<<endl;
        cout<<"\tEMPTY PLAYLIST"<<endl;
        return;
    }

    current = current->next;
    playlist *temp = current;

    cout<<endl;
    cout<<"\tPLAYING "<<temp->song_name<<endl;
}

void prev_song(){

    if(head == NULL){
        cout<<endl;
        cout<<"\tEMPTY PLAYLIST"<<endl;
        return;
    }

    current = current->prev;
    playlist *temp = current;

    cout<<endl;
    cout<<"\tPLAYING "<<temp->song_name<<endl;
}

void first_song(){

    if(head == NULL){
        cout<<endl;
        cout<<"\tEMPTY PLAYLIST"<<endl;
        return;
    }

    playlist *temp = head;

    cout<<endl;
    cout<<"\tPLAYING "<<temp->song_name<<endl;
}

void last_song(){

    if(head == NULL){
        cout<<endl;
        cout<<"\tEMPTY PLAYLIST"<<endl;
        return;
    }

    playlist *temp = head->prev;

    cout<<endl;
    cout<<"\tPLAYING "<<temp->song_name<<endl;
}

void specific_song(){

    if(head == NULL){
        cout<<endl;
        cout<<"\tEMPTY PLAYLIST"<<endl ;
        return;
    }
    
    cout<<"\tENTER MUSIC NAME TO PLAY :";
    cin>>temp_name;

    playlist *temp = head;

    do
    {
        if(temp->song_name == temp_name){
            cout<<endl;
            cout<<"\tPLAYING "<<temp_name<<endl;
            return;
        }
        temp = temp->next;

    } while(temp!=head);

    cout<<endl;
    cout<<"\tMUSIC NOT FOUND\n\tENTER CORRECT MUSIC NAME :";
}

int main(){

    int choice;
    
    cycle:

        cout<<endl;
        cout<<"\t---- MENU FOR PLAYLIST ----"<<endl;
        cout<<endl;
        cout<<"\t1. ADD MUSIC TO PLAYLIST"<<endl;
        cout<<"\t2. REMOVE MUSIC FROM PLAYLIST"<<endl;
        cout<<"\t3. SHOW PLAYLIST"<<endl;
        cout<<"\t4. PLAY NEXT MUSIC"<<endl;
        cout<<"\t5. PLAY PREVIOUS MUSIC"<<endl;
        cout<<"\t6. PLAY FIRST MUSIC"<<endl;
        cout<<"\t7. PLAY LAST MUSIC"<<endl;
        cout<<"\t8. PLAY SPECIFIC MUSIC"<<endl;
        cout<<"\t9. TO EXIT"<<endl;
        cout<<endl;

        cout<<"\tPLEASE ENTER YOUR CHOICE :";
        cin>>choice;

        switch (choice)
        {
              case 1:
                add_music();
                break;

              case 2:
                delete_music();
                break;

              case 3:
                show_playlist();
                break;

              case 4:
                next_song();
                break;

              case 5:
                prev_song();
                break;

              case 6:
                first_song();
                break;

              case 7:
                last_song();
                break;

              case 8:
                specific_song();
                break;

              case 9:
                exit(0);
                break;
        }

    goto cycle;    

    return 0;
}
