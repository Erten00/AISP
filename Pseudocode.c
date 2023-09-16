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