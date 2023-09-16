// Jednostruke povezane liste

typedef struct node{
    int data;
    struct node *next;
    }NODE;
NODE *first=NULL,*last=NULL,*temp=NULL;

int isEmpty(){
    if(first==NULL)
    return 1;

    else{
        return 0;
    } 
}

// Kreiranje elemenata

void crate(int elem){
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data = elem;
    temp->next = NULL;
    if(first=NULL){
        first=temp;
        last=temp;
    }
    else{
        last->next=temp
        last = temp;
    }
}

// Dodavanje elementa posle zadatog elementa

void insert_after(NODE *pom,int elem){
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data = elem;
    temp->next = pom->next;
    pom->next = temp;
    if (pom==last){
        last=temp;
    } 
}

//Dodavanje elementa pre zadatog elementa

void insert_before(NODE *pom,int elem){
    temp=(struct node*)malloc(sizeof(struct node));
    temp->next = pom->next;
    temp->data = pom->data;
    pom->data = elem;
    pom->next = temp;
    if (pom==last){
        temp=last;
    }
}

// Brisanje nakon zadatog elementa

void delete_after(NODE *pom){
    temp=pom->next;
    pom->next=temp->next;
    temp->next=NULL;
    free(temp);
}

// Brisanje zadatog čvora

void delete_actual(NODE *pom){
    if ((pom==first)&(first==last)){
        first=last=NULL;
        free(pom);
    }
    temp=pom->next;
    pom->next=temp->next;
    pom->data=temp->data;
    free(temp);
}

// Brisanje elementa na zadatoj poziciji vrednosti

void delete_on_position(int pos){
    int count = 1;
    NODE *p,*q;
    p=first;
    q=NULL;
    if (pos==1)
    {
        first=p->next;
        free(p);
        return;
    }
    while (pos!=count)
    {
        q=p;
        p=p->next;
        count++;
    }
    delete_after(q);
}

// Brisanje elementa na zadatoj vrednosti

void delete_by_value(int value){
    NODE *p, *q;
    p=first;
    q=NULL;
    while(p!=NULL){
        if(value==p->data){
            brake;
        }
        else{
            q=p;
            p=p->next;
        }
        if((p==first)&(first==last)){
            first=last=NULL;
            free(p);
            printf("Lista je sada prazna");
        }
        else if(p==last){
            q->next=NULL;
            free(p);
            last=q;
        }
        else{
            q->next=p->next;
            free(p);
        }
    }
}

// Prikaz elementa

void display(){
    temp=first;
    prinf("First->")
    while (temp!=NULL){
        //printf("%d %d" --> ",temp->data,temp->next");
        printf("%d", temp->data);
        temp=temp->next;
    }
    printf("NULL")
}

// Invertovanje liste

NODE *invertuj(NODE *first){
    NODE *p,*q,*r;
    p=first;
    q-NULL;
    while (p!=NULL){
     r=q;
     q=p;
     p=p->next;
     q->next=r; 
    }
    first=q;
    return first;
}

// Konkatenacija dve liste

NODE *concat(NODE *list1,NODE *list2){
    NODE *p;
    if (list1==NULL)
    {
        return list2;
    }
    else if (list2==NULL)
    {
        return list1;
    }
    p=list1;
    while (p->next!=NULL)
    {
        p=p->next
    }
    p->next=list2;
    return list1;
}

// Dvostruko povezana lista
//       Struktura elementa

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
    struct Node* head; //pok. na 1. elem.

// Kreiranje novog elementa

struct Node* GetNewNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Dodavanje elementa na početku liste

void InsertAtHead(int x) {
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

// Dodavanje elementa na kraju liste

void InsertAtTail(int x) {
    struct Node* temp = head;
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    // Go To last Node
    temp->next = newNode;
    newNode->prev = temp;
}

// Prikaz elemenata

// Standardno

void Print() {
    struct Node* temp = head;
    printf("Forward:");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
        }
    printf("\n");
}

// Inverzno

void ReversePrint() {
    struct Node* temp = head;
    if(temp == NULL){
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next; 
    }
    printf("Reverse: ");
    while(temp != NULL) {
    printf("%d ",temp->data);
    temp = temp->prev;
    }
    printf("\n");

}

// Kružno povezana lista

// Struktura elementa

typedef struct NODE{
    int info;
    struct NODE *next;
} NODE;
NODE *front=NULL,*rear=NULL,*temp;

// Kreiranje elementa

void create(){ 
    NODE *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the node value : ");
    scanf("%d",&newnode->info); newnode->next=NULL;
    if(rear==NULL){
        front=rear=newnode;
    }
    else { 
        rear->next=newnode; rear=newnode;
    }
    rear->next=front;
}

// Brisanje elemenata

void del(){ 
    temp=front;
    if(front==NULL){
        printf("\nUnderflow :");
    }
    else {
        if(front==rear){
            printf("\n%d",front->info);
            front=rear=NULL; 
        }
        else{
            printf("\n%d",front->info);
            front=front->next;
         rear->next=front;
        }
        temp->next=NULL;
        free(temp);
    }
}