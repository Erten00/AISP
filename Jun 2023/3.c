/*
3. (10 poena)
Napisati program u jeziku C kojim se u heš tabelu dužine 20 upisuje 10 studenata pri čemu je podatak broj indeksa.
Za upis koristiti podprogram. Za rešavanje kolizije koristiti linearno heširanje.
*/

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 20

// Struktura za studenta
struct Student {
    int index;
    char name[50];
};

// Struktura za čvor u heš tabeli
struct HashNode {
    struct Student student;
    struct HashNode* next;
};

// Funkcija za kreiranje novog čvora u heš tabeli
struct HashNode* createNode(int index, const char* name) {
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->student.index = index;
    strncpy(newNode->student.name, name, sizeof(newNode->student.name));
    newNode->next = NULL;
    return newNode;
}

// Funkcija za heširanje ključa
int hash(int index) {
    return index % TABLE_SIZE;
}

// Funkcija za upisivanje studenta u heš tabelu
void insert(struct HashNode* table[], int index, const char* name) {
    int key = hash(index);
    struct HashNode* newNode = createNode(index, name);

    if (table[key] == NULL) {
        table[key] = newNode;
    } else {
        // Linearno heširanje za rešavanje kolizija
        while (table[key]->next != NULL) {
            key = (key + 1) % TABLE_SIZE;
        }
        table[key]->next = newNode;
    }
}

// Funkcija za prikazivanje sadržaja heš tabele
void displayHashTable(struct HashNode* table[]) {
    printf("Heš tabela:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d: ", i);
        struct HashNode* current = table[i];
        while (current != NULL) {
            printf("(%d, %s) -> ", current->student.index, current->student.name);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct HashNode* hashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Upisivanje 10 studenata u heš tabelu
    insert(hashTable, 101, "Student1");
    insert(hashTable, 102, "Student2");
    insert(hashTable, 103, "Student3");
    insert(hashTable, 104, "Student4");
    insert(hashTable, 105, "Student5");
    insert(hashTable, 106, "Student6");
    insert(hashTable, 107, "Student7");
    insert(hashTable, 108, "Student8");
    insert(hashTable, 109, "Student9");
    insert(hashTable, 110, "Student10");

    // Prikazivanje sadržaja heš tabele
    displayHashTable(hashTable);

    return 0;
}