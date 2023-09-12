/*
1. (15 poena) 
U programskom jeziku C napisati program u kom se pomoću odgovarajućih funkcija vrši inicijalizacija, dodavanje elemenata u dvostruko ulančanu listu, brisanje elemenata i njihov prikaz.
Elementi su tipa int. Kreirati rekurzivnu funkciju za nalaženje minimalnog elementa liste i funkciju za sortiranje elemenata lančane liste koja koristi funkciju min. 
Demonstrirati rad programa.
*/

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

// Funkcija za brisanje elementa iz liste
void deleteFromList(struct Node** head, int data) {
    if (*head == NULL) {
        printf("Lista je prazna.\n");
        return;
    }

    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            printf("Element %d je obrisan iz liste.\n", data);
            return;
        }
        current = current->next;
    }
    printf("Element %d nije pronađen u listi.\n", data);
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

// Rekurzivna funkcija za nalaženje minimalnog elementa u listi
int findMin(struct Node* head) {
    if (head == NULL) {
        printf("Lista je prazna.\n");
        return -1;
    }

    int min = head->data;
    int temp = findMin(head->next);

    if (temp < min)
        min = temp;

    return min;
}

// Funkcija za sortiranje liste koristeći funkciju findMin
void sortList(struct Node** head) {
    if (*head == NULL) {
        printf("Lista je prazna.\n");
        return;
    }

    struct Node* sortedList = NULL;
    while (*head != NULL) {
        int min = findMin(*head);
        deleteFromList(head, min);
        appendToList(&sortedList, min);
    }

    *head = sortedList;
}

int main() {
    struct Node* list = initializeList();

    appendToList(&list, 3);
    appendToList(&list, 1);
    appendToList(&list, 4);
    appendToList(&list, 2);

    printf("Originalna lista: ");
    displayList(list);

    int min = findMin(list);
    printf("Minimalni element u listi: %d\n", min);

    sortList(&list);

    printf("Sortirana lista: ");
    displayList(list);

    return 0;
}
