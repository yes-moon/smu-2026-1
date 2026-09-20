#include <stdio.h>
#define MAX_SIZE 5

//전역 변수
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int queue_full() {
	if (rear - front == MAX_SIZE - 1)
		return 1;
	return 0;
}

int queue_empty() {
	if (front == -1 && rear == -1) {
		return 1;
	}
	return 0;
}

void post_process() { //프론트가 리어보다 커지면 초기화하는 방식, 중요함!
	if (front > rear) {
		front = -1;
		rear = -1;
	}

	if (rear == MAX_SIZE - 1) {//리어가 맨뒤까지 올라가있는 상태면
		for (int i = front; i <= rear;i++) {
			queue[i - front] = queue[i];
		}
		rear = rear - front;
		front = 0;
	}
}

void enqueue(int x) {
	if (!queue_full()) { //큐가 풀이 아니면
		rear++;
		queue[rear] = x;
		if (front == -1) front++;

		post_process();
	}

	else {
		printf("Queue full! Cannot enqueue.\n");
	}
}

int dequeue() {
	if (!queue_empty()) {
		int temp = queue[front];
		front++;

		post_process();
		return temp;
	}
	else {
		printf("Queue empty! Cannot dequeue.\n");
		return 0;
	}
}

void print_queue() {
	if (queue_empty()) {
		printf("Queue empty! ");
	}
	else {
		for (int i = front; i <= rear; i++) {
			printf(" %d", queue[i]);
		}
	}
	printf(" (front=%d, rear=%d)\n", front, rear);
}

int main() {
	int x, tmp;
	int cmd = 0;
	
	while (cmd != 4) {
		printf("Input a Command - 1. Enqueue, 2. Dequeue, 3. Print, 4. Exit: ");
		scanf("%d", &cmd);

		switch (cmd) {
			
		case 1:
			printf("Enter an integer: ");
			scanf("%d", &x);
			enqueue(x);
			print_queue();
			break;
		case 2:
			tmp = dequeue();
			printf("Dequeued %d\n", tmp);
			print_queue();
			break;
		case 3:
				print_queue();
				break;
		}
	}
}