#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#include <ctype.h>
// APS105 Lab 9
//
// This is a program written to maintain a personal music library,
// using a linked list to hold the songs in the library.


//

//NOTE:
// #includes, struct definition, MAX_LENGTH, and support functions will be added for you
// Do not add them here
//

// Declarations of linked list functions
//
// DECLARE YOUR LINKED-LIST FUNCTIONS HERE
//
typedef struct node1{
    char *songname;
    char *artist;
    char *genre;
    struct node1 *next;
}Node1;

typedef struct node2{
    Node1 *head;
}linklist;




Node1 *search(linklist *file, char *songname){
    Node1 *po=file->head;
    while(po!=NULL){
        if(strcmp(po->songname,songname)==0){
            return po;
        }
        po=po->next;
    }
    return NULL;
}

bool emp(linklist *file){
    if(file->head==NULL){
        return true;
    }
    return false;
}

Node1 *new(char *songname, char *artist, char *genre){
    
    Node1 *newnode=(Node1*)malloc(sizeof(Node1));
    if(newnode!=NULL){
        newnode->songname=(char*)malloc(sizeof(char)*(strlen(songname)+1));
        newnode->artist=(char*)malloc(sizeof(char)*(strlen(artist)+1));
        newnode->genre=(char*)malloc(sizeof(char)*(strlen(genre)+1));
        strcpy(newnode->songname,songname);
        strcpy(newnode->artist,artist);
        strcpy(newnode->genre,genre);
        newnode->next=NULL;
        return newnode;
    }
    return NULL;
}





bool delet(linklist *file, char *songname) {
  if (emp(file) == true) {
    // There is nothing to do in an empty list.
    return false;
  }

  if (strcmp(file->head->songname,songname)==0){
    // The first node matches the value.

    Node1 *temp = file->head->next;
    free(file->head->songname);
    free(file->head->artist);
    free(file->head->genre);
    free(file->head);
    file->head=temp;
    return true;
  }
  
  Node1 *current=file->head;
  while(current->next != NULL && strcmp(current->next->songname,songname) !=0) {
    current = current->next;
  }


  if (current->next != NULL) {
  
    // current does not point to the last node.
    Node1 *temp = current->next; // temp is the node we must delete.
    current->next = temp->next; // Update n so that temp is no longer linked.
    
    free(temp->songname);
    free(temp->artist);
    free(temp->genre);
    free(temp);

    return true;
  }

    if(strcmp(file->head->songname,songname)==0){
        return false;
    }
  // Search for a node that matches the value, but maintain a pointer to the
  // node just before it.
  

  return false;
}
void deletall(linklist *file){
   while(emp(file)==false){
        Node1 *newhead=file->head->next;
        printf("\nDeleting a song with name '%s' from the music library.\n",file->head->songname);

        free(file->head->songname);
        free(file->head->artist);
        free(file->head->genre);
        free(file->head);
        file->head=newhead;

    }  
    if(emp(file)==true){
        return;
    }
}


void printlib(linklist *file){
    Node1    *po=file->head;
    while(po!=NULL){
        printf("\n%s\n",po->songname);
        printf("%s\n",po->artist);
        printf("%s\n",po->genre);
        //printf("\n");
        po=po->next;
    }

}

bool insertst(linklist *file,char *songname, char *artist, char *genre){
    Node1 *ply=new(songname,artist,genre);
    if(ply==NULL){
        return false;
    }
    else{
        ply->next=file->head;
        file->head=ply;
        return true;
    }
}

bool insert(linklist *list, char *songname, char *artist, char *genre){
    if(emp(list)){
        return(insertst(list,songname,artist,genre));
    }
    
    if(strcmp(songname,list->head->songname)<0){
        return(insertst(list,songname,artist,genre));
    }
    Node1 *po=list->head;
    while(po->next!=NULL&&strcmp(songname,po->next->songname)>0){
        po=po->next;
    }
    Node1 *ne=new(songname,artist,genre);
    if(ne==NULL){
        return false;
    }
    ne->next=po->next;
    po->next=ne;

    return true;

}

//const int  MAX_LENGTH=1024;
int main(void) {
  // Declare the head of the linked list.
    linklist lib;
    lib.head=NULL;
  //   ADD YOUR STATEMENT(S) HERE

  // Announce the start of the program
  printf("Personal Music Library.\n\n");
  printf("%s", "Commands are I (insert), D (delete), S (search by song name),\n"
               "P (print), Q (quit).\n");

  char response;
  
  char input[MAX_LENGTH + 1];
  do {
    inputStringFromUser("\nCommand", input, MAX_LENGTH);

    // Response is the first character entered by user.
    // Convert to uppercase to simplify later comparisons.
    response = toupper(input[0]);

    if (response == 'I') {
      // Insert a song into the linked list.
      // Maintain the list in alphabetical order by song na me.
      //   ADD STATEMENT(S) HERE
        char *songname = (char*)malloc(MAX_LENGTH+1 * sizeof(char));
        char *artist = (char*)malloc(MAX_LENGTH+1 * sizeof(char));
        char *genre = (char*)malloc(MAX_LENGTH+1 * sizeof(char));

      // USE THE FOLLOWING STRINGS WHEN PROMPTING FOR DATA:
        char *promptName = "Song name" ;
        char *promptArtist =  "Artist" ;
        char *promptGenre = "Genre" ;

        inputStringFromUser(promptName, songname, MAX_LENGTH);
        inputStringFromUser(promptArtist, artist, MAX_LENGTH);
        inputStringFromUser(promptGenre, genre, MAX_LENGTH);

        if(search(&lib,songname)!=NULL){
            printf("\nA song with the name '%s' is already in the music library.\n",songname);
            printf("No new song entered.\n");
            
        }
        else{
            insert(&lib,songname,artist,genre);

        }
        free(songname);
        free(artist);
        free(genre);


    } else if (response == 'D') {
      // Delete a song from the list.

      char *prompt = "\nEnter the name of the song to be deleted";
      char *songname=(char*)malloc(MAX_LENGTH+1 * sizeof(char));
      inputStringFromUser(prompt,songname, MAX_LENGTH);
      
      
        if(delet(&lib,songname)){
           
            printf("\nDeleting a song with name '%s' from the music library.\n",songname);
                
        }
      
      else{
        printf("\nThe song name '%s' was not found in the music library.\n",songname);
      }
      
      free(songname);
    

      //   ADD STATEMENT(S) HERE

    } else if (response == 'S') {
      // Search for a song by its name.

      char *prompt = "\nEnter the name of the song to search for";
      char *songname=(char*)malloc(MAX_LENGTH+1 * sizeof(char));
      inputStringFromUser(prompt, songname, MAX_LENGTH);
      
      Node1 *print=search(&lib,songname);
      if(search(&lib,songname)!=NULL){
          printf("\nThe song name '%s' was found in the music library.\n\n",songname);
          printf("%s\n",print->songname);
          printf("%s\n",print->artist);
          printf("%s\n",print->genre);

      }
      else if(search(&lib,songname)==NULL){
          printf("\nThe song name '%s' was not found in the music library.\n",songname);

      }
      free(songname);
        
      //   ADD STATEMENT(S) HERE

    } else if (response == 'P') {
      // Print the music lif(linklist*file)
      if(emp(&lib)==true){
          printf("\nThe music library is empty.\n");
      }
      else if(emp(&lib)==false){
          printf("\nMy Personal Music Library: \n");
          printlib(&lib);

      }
      //   ADD STATEMENT(S) HERE

    } else if (response == 'Q') {
      ; // do nothing, we'll catch this below
    } else {
      // do this if no command matched ...
      printf("\nInvalid command.\n");
    }
  } while (response != 'Q');

  // Delete the entire linked list.
  deletall(&lib);
  // ADD STATEMENT(S) HERE
  // Print the linked list to confirm deletion.
  if(emp(&lib)==true){
        printf("\nThe music library is empty.\n");
    }
}
