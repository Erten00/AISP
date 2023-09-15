/*
2. (20 poena)
Napisati program u jeziku C za predstavljanje reda korišćenjem dva steka.
U glavnom programu demonstirati rad funkcija.
*/

#include <stdio.h>
#include <stdlib.h>

// Struktura za stek
struct Stack {
    int capacity;
    int top;
    int* array;
};

// Funkcija za inicijalizaciju steka
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Funkcija za proveru da li je stek prazan
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Funkcija za proveru da li je stek pun
int isFull(struct Stack* stack) {
    return (stack->top == stack->capacity - 1);
}

// Funkcija za dodavanje elementa u stek
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stek je pun. Element %d nije dodat.\n", item);
        return;
    }
    stack->array[++stack->top] = item;
}

// Funkcija za uklanjanje elementa iz steka
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stek je prazan.\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Funkcija za dodavanje elementa u red
void enqueue(struct Stack* stack1, struct Stack* stack2, int item) {
    // Premestiti sve elemente iz stack1 u stack2
    while (!isEmpty(stack1)) {
        push(stack2, pop(stack1));
    }

    // Dodati novi element u stack1
    push(stack1, item);

    // Premestiti sve elemente iz stack2 nazad u stack1
    while (!isEmpty(stack2)) {
        push(stack1, pop(stack2));
    }
}

// Funkcija za uklanjanje elementa iz reda
int dequeue(struct Stack* stack1) {
    if (isEmpty(stack1)) {
        printf("Red je prazan.\n");
        return -1;
    }
    return pop(stack1);
}

int main() {
    struct Stack* stack1 = createStack(100); // Prvi stek za red
    struct Stack* stack2 = createStack(100); // Drugi stek za privremeno skladištenje

    enqueue(stack1, stack2, 1);
    enqueue(stack1, stack2, 2);
    enqueue(stack1, stack2, 3);

    printf("Element iz reda: %d\n", dequeue(stack1));
    printf("Element iz reda: %d\n", dequeue(stack1));

    enqueue(stack1, stack2, 4);
    
    printf("Element iz reda: %d\n", dequeue(stack1));
    printf("Element iz reda: %d\n", dequeue(stack1));

    return 0;
}