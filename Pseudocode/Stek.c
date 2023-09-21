#include<stdio.h>
#include<stdlib.h>

//Implementacija preko niza


#define SIZE 5 /* Size of Stack */

int s[SIZE],top=-1; /* Global declarations */

/* Function toCheck Stack Full */

int Sfull(){
    if(top == SIZE-1){
        return 1;
    }
return 0;
}

/* Function to Check Stack Empty */

int Sempty(){
    if(top == -1){
        return 1;
    }
return 0;
}

/* Function for PUSH operation */

void push(int elem){ 
    if( Sfull()) {
        printf("\n\nOverflow!!!!\n\n");
    }
    else {
        ++top;
        s[top]=elem;
    }
}

/* Function for POP operation */

int pop(){
    int elem;
    if(Sempty()){
        printf("\n\nUnderflow!!!!\n\n");
        return(-1);
    }
    else{
        elem=s[top];
        top--;
        return(elem); 
    }
}

/* Function to display status of Stack */

display(){
    int i;
    if(Sempty()){
        printf(" \nEmpty Stack\n");
    } 
    else{
        for(i=0;i<=top;i++){
            printf("%d\n",s[i]);
            printf("^Top");
        }
    }
}

/* Main Program */

main(){
    int opn,elem;
    clrscr();
    printf("\n ### Stack Operations ### \n\n");
    printf("\n Press 1-Push, 2-Pop,3-Display,4-Exit\n");
    printf("\n Your option ? ");
    scanf("%d",&opn);
    switch(opn){
        case 1: printf("\n\nRead the element to be pushed ?");
            scanf("%d",&elem);
            push(elem); break;
        case 2: elem=pop();
        if( elem != -1){
            printf("\n\nPopped Element is %d \n",elem);
        }
    }
}

//
// Implementacija preko lančane liste
//

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