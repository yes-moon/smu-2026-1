#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 100

int list[MAX_SIZE];
int top = -1;

void get(int i) {
    int count = 1;
    printf("결과: %d, 반복된 횟수: %d\n", list[i], count);
}

void insert(int i, int x) {
    int count = 0;
    for (int j = top; j >= i; j--) {
        list[j + 1] = list[j];
        count++;
    }
    list[i] = x;
    top++;
    printf("반복된 횟수: %d\n", count);
}

void delete(int i) {
    int count = 0;
    printf("결과: %d, ", list[i]);
    for (int j = i; j < top; j++) {
        list[j] = list[j + 1];
        count++;
    }
    top--;
    printf("반복된 횟수: %d\n", count);
}

void update(int i, int x) {
    int count = 1;
    list[i] = x;
    printf("반복된 횟수: %d\n", count);
}

void size() {
    int count = 1;
    printf("결과: %d, 반복된 횟수: %d\n", top + 1, count);
}

void traverse() {
    int i;
    for (i = 0; i <= top; i++) {
        printf("%d\t", list[i]);
    }
    printf("\n반복된 횟수: %d\n", i);
}

void search(int x) {
    int i;
    for (i = 0; i <= top; i++) {
        if (list[i] == x) {
            printf("결과: %d, 반복된 횟수: %d\n", i, i + 1);
            return;
        }
    }
    printf("결과: -1, 반복된 횟수: %d\n", i);
}

int main() {
    int x;
    int cmd = 0;
    int i;

    while (cmd != 8) {
        printf("Input a command - 1. Get, 2. Insert, 3. Delete, 4. Update, 5. Size, 6. Traverse, 7. Search, 8. Exit: ");
        scanf("%d", &cmd);

        switch (cmd) {
        case 1:
            printf("Enter an index: ");
            scanf("%d", &i);
            get(i);
            break;
        case 2:
            printf("Enter an integer: ");
            scanf("%d", &x);
            printf("Enter an index: ");
            scanf("%d", &i);
            insert(i, x);
            break;
        case 3:
            printf("Enter an index: ");
            scanf("%d", &i);
            delete(i);
            break;
        case 4:
            printf("Enter an integer: ");
            scanf("%d", &x);
            printf("Enter an index: ");
            scanf("%d", &i);
            update(i, x);
            break;
        case 5:
            size();
            break;
        case 6:
            traverse();
            break;
        case 7:
            printf("Enter an integer: ");
            scanf("%d", &x);
            search(x);
            break;
        case 8:
            break;
        }
    }
    return 0;
}
