#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

struct node {
     int data;
     struct node *next;
};

// function f() for this question
void f(struct node *P) {
     if(P != NULL) 
          f(P->next);
     
     if(P != NULL)  // without this line segmentation fault
     printf(" %d\n",P->data);
}


// helper function
void print_elem(struct node *P) {
     
     while(P != NULL) {
          printf(" %d -> ",P->data);
          P = P->next;
     }

     if(!P) printf("NULL\n");
}
void deallocate_list_memory(struct node* P);

int main() {
     srand(time(NULL));
     
     int i=0;
     struct node *head;
     head = NULL;
     
     // inserting 10 random data items between 0 to 9 including 
     
     struct node *temp = NULL; // helper node pointer
     
     for(i=0;i<N;i++) {
          struct node *new_node = (struct node*)malloc(sizeof(struct node));
          
          // first create a node with data
          int val = rand()%10;
          new_node->data = val;
          new_node->next = NULL;

          // now link the newly created node with
          // exisiting chain (list)
          
          // if list is empty 
          if(temp == NULL) {
               head = new_node;  // set the parent node pointer first
               temp = new_node; // set the helper node pointer
               printf(" %d is inserted \n",val);
          }
          
          // if list not empty
          else {
               temp->next = new_node;
               temp = new_node;
               printf(" %d is inserted \n",val);
          }
     }

     printf("\n printing the inserted elements\n\n");
     print_elem(head);
     
     
     // For this question call f()

     printf("\n\n output of given function in the question\n");
     f(head);
     deallocate_list_memory(head);
     return 0;
}


// imp to deallocate
void deallocate_list_memory(struct node* P) {
     struct node *temp;
     while(P != NULL) {
          temp = P;
          P = P->next;
          free(temp);
     }
}
