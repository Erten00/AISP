#include <stdio.h>
#include <stdlib.h>

// Struktura za čvor binarnog stabla
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Funkcija za kreiranje novog čvora
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Funkcija za ispisivanje elemenata sa određenog nivoa stabla
void printLevel(struct Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

// Funkcija za ispisivanje elemenata sa određenog nivoa stabla
void printLevelOrder(struct Node* root, int level) {
    if (root == NULL)
        return;
    
    for (int i = 1; i <= level; i++) {
        printf("Nivo %d: ", i);
        printLevel(root, i);
        printf("\n");
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    printf("Ispisivanje elemenata sa određenog nivoa stabla:\n");
    int level = 2; // Nivo koji želimo ispisati
    printLevelOrder(root, level);

    return 0;
}