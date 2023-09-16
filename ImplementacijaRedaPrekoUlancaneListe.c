//  Implementacija reda preko ulančane liste

#include <stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}NODE;
    void Insert(int);
    int Delete();
    void Display();
    NODE *front,*rear;

// Operacija Enqueue (dodavanje elementa)

void Insert(int info){
    NODE *temp;
    temp=(NODE *)malloc(sizeof(NODE));
    if( temp == NULL){
        printf(" Out of Memory !!Overflow !!!");
    }
    else{
        temp->data=info;
        temp->link=NULL;
        if(front == NULL) { 
            front = rear =temp; 
        } /* First Node? */
        else{ 
            rear->link=temp; rear = temp;
        } /* Insert End */
            printf(" Node has beeninserted at End Successfully !!");
    }
}

// Operacija Dequeue (uklanjanje elementa)

int Delete()
{
    int info;
    NODE *t;
    if( front ==  NULL) { printf(" Underflow!!!"); return -1; }
    else
    {
        t=front;
        info=front->data;
        if(front == rear) rear=NULL;
        front=front->link;
        t->link=NULL;
        free(t);
        return(info);
    }
}

// Prikaz (štampanje) elemenata

void Display()
{
    NODE *t;
    if( front == NULL) printf("Empty Queue\n");
    else
    {
        t=front;
        printf("Front->");
        while(t)
        {
            printf("[%d]->",t->data);
            t=t->link;
        }
        printf("Rear\n");
    }
}