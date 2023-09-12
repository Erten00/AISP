/*
4. (15 poena)
U programskom jeziku C napisati program za rad sa stablom implementiranim preko lančane liste čiji svaki element ima maksimum tri potomka, levi, desni, i srednji.  
Napraviti funkcije za stampanje stabla i ispitivanje da li je stablo kompletno.
Demonstrirati rad programa.
*/

#include <stdio.h>
#include <stdlib.h>

// Struktura za čvor stabla
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* middle;
    struct TreeNode* right;
};

// Funkcija za kreiranje novog čvora stabla
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->middle = NULL;
    newNode->right = NULL;
    return newNode;
}

// Funkcija za ispitivanje da li je stablo kompletno
int isCompleteTree(struct TreeNode* root) {
    if (root == NULL) {
        return 1; // Prazno stablo smatramo kompletnim
    }
    
    // Rekurzivna provera za levo podstablo i srednje podstablo
    int leftComplete = isCompleteTree(root->left);
    int middleComplete = isCompleteTree(root->middle);
    
    // Ako je levo podstablo ili srednje podstablo nekompletno, stablo nije kompletno
    if (!leftComplete || !middleComplete) {
        return 0;
    }
    
    // Rekurzivna provera za desno podstablo
    return isCompleteTree(root->right);
}

// Funkcija za ispisivanje stabla
void printTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    printf("%d -> ", root->data);
    printTree(root->left);
    printTree(root->middle);
    printTree(root->right);
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->middle = createNode(3);
    root->right = createNode(4);
    
    root->left->left = createNode(5);
    root->left->middle = createNode(6);
    
    root->middle->left = createNode(7);
    
    printf("Stablo:\n");
    printTree(root);
    printf("\n");
    
    if (isCompleteTree(root)) {
        printf("Stablo je kompletno.\n");
    } else {
        printf("Stablo nije kompletno.\n");
    }
    
    return 0;
}