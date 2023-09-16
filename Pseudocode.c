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