// Dvostruko povezana lista

//       Struktura elementa

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