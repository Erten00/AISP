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
        last=temp;
    }
}

//