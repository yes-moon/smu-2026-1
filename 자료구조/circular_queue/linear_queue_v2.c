#define _CRT_SECURE_NO_WARNINGS   // ← 이게 핵심! 반드시 맨 위에!
#include <stdio.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = 0;
int rear = 0;

int queue_full() {
    if ((rear + 1) % MAX_SIZE == front)
        return 1;
    return 0;
}

int queue_empty() {
    if (front == rear)
        return 1;
    return 0;
}

void enqueue(int x) {
    if (queue_full()) {
        printf("Queue full!\n");
    }
    else {
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = x;
    }
}

int dequeue() {
    if (queue_empty()) {
        printf("Queue empty!\n");
        return -1;
    }
    else {
        front = (front + 1) % MAX_SIZE;
        int temp = queue[front];
        return temp;
    }
}

void print_queue() {
    int i;                                      // ← 변수 선언을 위로 올림
    printf("queue = ");
    i = (front + 1) % MAX_SIZE;
    while (i != (rear + 1) % MAX_SIZE) {
        printf(" %d", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf(" (front=%d, rear=%d)\n", front, rear);
}

int main() {
    int x;
    int cmd = 0;
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
            if (v != -1)
                printf("Dequeued: %d\n", v);
            print_queue();
            break;
        case 3:
            print_queue();
            break;
        }
    }
    return 0;
}