#include<stdio.h>
#include<stdlib.h>

//Ispitivanje da li je stek pun

#define SIZE 5 /* Size of Stack */

int s[SIZE],top=-1; /* Global declarations */

int Sfull(){ /* Function toCheck Stack Full */
    if(top == SIZE-1){
        return 1;
    }
return 0;
}

// Ispitivanje da li je stek prazan

int Sempty(){ /* Function to Check Stack Empty */
    if(top == -1){
        return 1;
    }
return 0;
}

// Push

void push(int elem){ /* Function for PUSH operation */
    if( Sfull()) {
        printf("\n\nOverflow!!!!\n\n");
    }
    else {
        ++top;
        s[top]=elem;
    }
}

// Pop

int pop(){ /* Function for POP operation */
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

// Prikazivanje (štampanje) elemenata

display(){ /* Function to display status of Stack */
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

// Main funkcija

main(){ /* Main Program */
    int opn,elem;
    do{
        clrscr();
        printf("\n ### Stack Operations ### \n\n");
        printf("\n Press 1-Push, 2-Pop,3-Display,4-Exit\n");
        printf("\n Your option ? ");
        scanf("%d",&opn);
    }
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

// Dva steka preko jednog niza

// StackFull

#define SIZE 10/* Size of Stack */

int s[SIZE],top[3]={0,-1,SIZE};

int Sfull(){ /*Function to Check Stack Full */
    if(top[1] == top[2]-1){
        return 1;
    }
    return 0;
}

// StackEmpty

int Sempty(stno){ /* Function to Check Stack Empty */
    switch(stno){
        case 1: 
            if(top[1] == -1){
                return 1;
            }
            else{
                return 0;
            }
        case 2:
            if(top[2] == SIZE){
                return 1;
            }
            else{
                return 0;
            }
        }
}