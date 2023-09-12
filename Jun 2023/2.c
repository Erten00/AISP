/*
2. (10 poena)
Napisati program u programskom jeziku C koji ima metode za rad sa redom koji je implementiran preko niza.
Operacije dodavanja, brisanja i prikaza odraditi preko potprograma.
U glavnom programu ubaciti 4 elemenata ('1','2','3','4'), prikazati red, izbrisati dva elementa pa ponovo ubaciti jedan ('5') i ponovo prikazati red.
Napisati šta je rezultat programa.
*/

#include <stdio.h>

#define MAX_SIZE 100

struct Queue {
    char items[MAX_SIZE];
    int front;
    int rear;
};

// Funkcija za inicijalizaciju reda
void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Funkcija za proveru da li je red prazan
int isEmpty(struct Queue *q) {
    return q->front == -1;
}

// Funkcija za proveru da li je red pun
int isFull(struct Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

// Funkcija za dodavanje elementa u red
void enqueue(struct Queue *q, char item) {
    if (isFull(q)) {
        printf("Red je pun. Element '%c' nije dodat.\n", item);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = item;
}

// Funkcija za uklanjanje elementa iz reda
char dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Red je prazan.\n");
        return '\0';
    }
    char item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// Funkcija za prikaz reda
void displayQueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Red je prazan.\n");
        return;
    }
    printf("Red: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%c ", q->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initializeQueue(&q);

    enqueue(&q, '1');
    enqueue(&q, '2');
    enqueue(&q, '3');
    enqueue(&q, '4');

    printf("Red nakon dodavanja 4 elementa: ");
    displayQueue(&q);

    printf("Uklanjanje dva elementa iz reda: ");
    printf("%c ", dequeue(&q));
    printf("%c ", dequeue(&q));
    printf("\n");

    enqueue(&q, '5');

    printf("Red nakon dodavanja elementa '5': ");
    displayQueue(&q);

    return 0;
}
