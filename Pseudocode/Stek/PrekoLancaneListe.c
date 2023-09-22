#include <stdio.h>
#include <stdlib.h>

// Implementacija preko lančane liste

typedef struct node{
    int data;
    struct node *link;
}NODE;

void Push(int);
    int pop();
    void Display();
NODE *top=NULL;

// Operacija Push (dodavanje elementa)

void Push(int info){
    NODE *temp;
    temp=(NODE *)malloc(sizeof(NODE));
    if( temp == NULL){
        printf(" Out of Memory !! Overflow !!!");
    }
    else{
        temp->data=info;
        temp->link=top;
        top=temp;
        printf(" Node has been inserted at Top(Front) Successfully !!");
    }
}

// Operacija Pop (uklanjanje elementa)

int Pop(){
    int info;
    NODE *t;
    if( top == NULL){
        printf(" Underflow!!!");
        return -1;
    }
    else{
        t=top;
        info=top->data;
        top=top->link;
        t->link=NULL;
        free(t);
        return(info);
    }
}

// Prikaz (štampanje) elemenata

void Display(){
    NODE *t;
    if( top == NULL){
        printf("Empty Stack\n");
    }
    else{
        t=top;
        printf("Top->");
    }
    while(t){
    printf("[%d]->",t->data);
    t=t->link;
    }
}