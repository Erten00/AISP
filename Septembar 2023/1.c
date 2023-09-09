#include <stdio.h>
#include <stdlib.h>

// Struktura za čvor dvostruko ulančane liste
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Funkcija za inicijalizaciju prazne liste
struct Node* initializeList() {
    return NULL;
}

// Funkcija za dodavanje elementa na kraj liste
void appendToList(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Funkcija za prikazivanje liste od početka prema kraju
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Funkcija za inverziju liste
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }

    *head = prev;
}

int main() {
    struct Node* list = initializeList();

    // Dodavanje elemenata u listu
    appendToList(&list, 1);
    appendToList(&list, 2);
    appendToList(&list, 3);
    appendToList(&list, 4);

    printf("Originalna lista: ");
    displayList(list);

    // Inverzija liste
    reverseList(&list);

    printf("Inverzna lista: ");
    displayList(list);

    return 0;
}
