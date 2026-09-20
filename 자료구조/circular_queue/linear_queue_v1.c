#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int queue_full() {
    if (rear >= MAX_SIZE - 1)
        return 1;
    return 0;
}

int queue_empty() {
    if (front == -1 && rear == -1)
        return 1;
    return 0;
}

void enqueue(int x) {
    if (queue_full()) {
        if (front > 0) {
            int i, j = 0;
            for (i = front; i <= rear; i++, j++) {
                queue[j] = queue[i];
            }
            rear = j - 1;
            front = 0;
        }
        else {
            printf("Queue full!\n");  
            return;
        }
    }
    if (queue_empty()) {
        front = 0;
        rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = x;
}

int dequeue() {
    if (queue_empty()) {
        printf("Queue empty\n");
        return -1;
    }
    int temp = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front++;
    }
    return temp;
}

void print_queue() {
    printf("queue = ");
    if (queue_empty()) {          
        printf("(empty)");
    }
    else {
        int i;
        for (i = front; i <= rear; i++)
            printf(" %d", queue[i]);
    }
    printf("\nfront = %d, rear = %d\n", front, rear);
}

int main() {
    int cmd = 0;
    int x;
    int v;

    while (cmd != 4) {
        printf("Input a command - 1. Enqueue, 2. Dequeue, 3. Print, 4. Exit: ");
        scanf("%d", &cmd);

        switch (cmd) {
        case 1:
            printf("Enter an integer: ");
            scanf("%d", &x);
            enqueue(x);
            print_queue();
            break;
        case 2:
            v = dequeue();
            if (v != -1) printf("Dequeued: %d\n", v);
            print_queue();
            break;
        case 3:
            print_queue();
            break;
        }
    }
}