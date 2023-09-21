#include <stdio.h>
#include <stdlib.h>

struct bin_tree
{
    int data;
    struct bin_tree * right, * left;
};
typedef struct bin_tree node;

// Binarno stablo – implementacija u C-u

struct node{
    int data;
    struct node * right, * left;
};

// Kreiranje novog čvora

struct node* newNode(int data){ // Alociranje memorije za novi čvor
    struct node* node = (struct node*)malloc(sizeof(struct node)); // Dodavanje data dela tom novomčvoru
    node->data = data; // incijalizacija desnog i levog potomka na NULL
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Obilasci //

// Inorder

void print_inorder(struct node * tree){
    if (tree){
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}

// Preorder

void print_preorder(struct node *tree){
    if (tree){
    printf("%d\n",tree->data);
    print_preorder(tree->left);
    print_preorder(tree->right);
    }
}

// Postorder

void print_postorder(struct node *tree){
    if (tree){
        print_postorder(tree->left);
        print_postorder(tree->right);
       printf("%d\n",tree->data);
    }
}

// Brisanje elemenata

void deltree(struct node * tree){
    if (tree){
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

// Main Funcion //

int main(){
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left =
    newNode(4);
    printf("preorder\n");
    print_preorder(root);
    printf("inorder\n");
    print_inorder(root);
    printf("postorder\n");
    print_postorder(root);
    printf("deletion");
    deltree(root->left);
    getchar();
    return 0;
}