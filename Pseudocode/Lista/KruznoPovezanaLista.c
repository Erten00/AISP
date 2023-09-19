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
    newnode = (NODE *)malloc(sizeof(NODE));
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