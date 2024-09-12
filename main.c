#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    int length;
};

void enqueue(struct Queue* queue, const int data) {
    const auto newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->length == 0) {
        queue->front = newNode;
    } else {
        struct Node* temp = queue->front;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    queue->length++;
}

void dequeue(struct Queue* queue) {
    if (queue->length == 0) {
        printf("Queue is empty\n");
        return;
    } else {
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    queue->length--;
}

void display(struct Queue* queue) {
    if (queue->length == 0) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = queue->front;
        while (temp != NULL) {
            printf("[%d] -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void peek(struct Queue* queue) {
    if (queue->length == 0) {
        printf("Queue is empty\n");
    } else {
        printf("Peeking from front: %d\n", queue->front->data);
    }
}

int main(void)
{
    struct Queue queue;
    queue.length = 0;
    enqueue(&queue, 10);
    peek(&queue);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue,40);
    enqueue(&queue, 50);
    enqueue(&queue,60);
    enqueue(&queue,70);
    peek(&queue);
    display(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    display(&queue);
    peek(&queue);
    dequeue(&queue);
    display(&queue);
}
