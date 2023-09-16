//  Implementacija reda preko ulančane liste

#include <stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}NODE;
    void Insert(int);
    int Delete();
    void Display();
    NODE *front,*rear;

