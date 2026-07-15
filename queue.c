#include <stdio.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int count;
} Queue;

void initQueue(Queue *q) { q->front = 0; q->rear = -1; q->count = 0; }
int isEmpty(Queue *q) { return q->count == 0; }
int isFull(Queue *q) { return q->count == MAX_SIZE; }

void enqueue(Queue *q, int value) {
    if (isFull(q)) { printf("Queue overflow!\n"); return; }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
    q->count++;
}

int dequeue(Queue *q) {
    int value;
    if (isEmpty(q)) { printf("Queue underflow!\n"); return -1; }
    value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->count--;
    return value;
}

int peek(Queue *q) {
    if (isEmpty(q)) { printf("Queue is empty!\n"); return -1; }
    return q->data[q->front];
}

void printQueue(Queue *q) {
    int i, idx;
    printf("Queue state (front -> rear): [ ");
    for (i = 0; i < q->count; i++) {
        idx = (q->front + i) % MAX_SIZE;
        printf("%d ", q->data[idx]);
    }
    printf("]\n");
}

int main(void) {
    Queue q;
    int removed;
    initQueue(&q);

    printf("Queue Demonstration\n");
    printf("--------------------\n");

    enqueue(&q, 10);
    printf("After enqueue(10): "); printQueue(&q);

    enqueue(&q, 20);
    printf("After enqueue(20): "); printQueue(&q);

    enqueue(&q, 30);
    printf("After enqueue(30): "); printQueue(&q);

    printf("Peek (front element): %d\n", peek(&q));

    removed = dequeue(&q);
    printf("After dequeue() -> removed %d: ", removed); printQueue(&q);

    enqueue(&q, 40);
    printf("After enqueue(40): "); printQueue(&q);

    removed = dequeue(&q);
    printf("After dequeue() -> removed %d: ", removed); printQueue(&q);

    return 0;
}

