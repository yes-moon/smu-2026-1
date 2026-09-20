#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 10

//전역 배열 설정
int arr[MAX_SIZE];
int length = 0;

int size() { //그냥 배열 사이즈 출력하는 함수
	return length;
}

void get(int i) {
	if (i < 0 || i >= length) {
		printf("Invalid index.\n");
		return; //여기서 종료하고 나가라 아니면 밑에 프린트문까지 가버림
	}
	printf("Element at index %d = %d", i, arr[i]);
}

void traverse() { //리스트를 전부 훑어서 출력해주는 함수
	if (length == 0) {
		printf("List is empty.\n"); //리스트 비면이고
		return;
	}
	printf("List: ");
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int search(int x) { //x의 인덱스를 알려주는 함수
	for (int i = 0; i < length; i++) {
		if (arr[i] == x) {
			return i; // 찾는 값인 인덱스 i를 반환
		}
	}
	return -1; //찾는 값이 없어 오류를 나타내는 -1 반환
}

void update(int i, int x) { //intx로 int i를 업데이트
	if (i < 0 || i >= length) {
		printf("Invalid index.\n");
		return;
	}

	arr[i] = x;
	printf("Updated index %d to %d.", i, x);
}

void insert(int i, int x) { //x를 index i 자리에 넣기
	if (length >= MAX_SIZE) {
		printf("List is Full.\n");
		return;
	}
	if (i < 0 || i > length) { // i == length 이면 맨 뒤에 추가
		printf("Invalid index.\n");
		return;
	}

	for (int j = length; j > i; j--) {
		arr[j] = arr[j - 1]; //j-1에 있는 애들을 j로 하나씩 당기기
	}
	arr[i] = x; //인덱스 i에 x를 저장해라
	length++; //넣고 길이 늘려주기

	printf("Inserted %d at %d.\n", x, i);
}

void delete(int x) { //자자 이제 삭제 함수 먼저 생각해보면 뒤에있는걸 앞으로 당겨야겠지? 어어
	int idx = search(x);

	if (idx == -1) {//search(0에서 -1을 뱉은건 오류값이니까 그걸 오류라고 띄우는 함수를 만들어줘야지 안그러냐?
		printf("Value %d not found.\n", x);
		return;
	}

	for (int i = idx; i < length - 1; i++) {
		arr[i] = arr[i + 1]; // length가 8일때는 인덱스 7까지 숫자가 있고, 한 번씩 두자리 땡겨오는거니까 뺄려는 수가 있는 인덱스에서 i++만 [i+1]로 돼도 인덱스 7까지 도달
	}

	length--; //뺐으니 반복문 끝나고 한 칸 줄여주기

	printf("Deleted %d from index %d", x, idx);
}

int main() {
	int choice, i, x;

	while (1) { //항상 실행
		printf("\n==== Array List Menu ====\n");
		printf("1. Size\n");
		printf("2. Get\n");
		printf("3. Traverse\n");
		printf("4. Search\n");
		printf("5. Update\n");
		printf("6. Insert\n");
		printf("7. Delete\n");
		printf("8. Exit\n");
		printf("Select: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Size: %d\n", size());
			break;
		case 2:
			printf("Index: "); scanf("%d", &i);
			get(i);
			break;
		case 3:
			traverse();
			break;
		case 4:
			printf("Value: "); scanf("%d", &x);
			printf("Index of %d: %d\n", x, search(x));
			break;
		case 5:
			printf("Index: "); scanf("%d", &i);
			printf("New value: "); scanf("%d", &x);
			update(i, x);
			break;
		case 6:
			printf("Index: "); scanf("%d", &i);
			printf("Value: "); scanf("%d", &x);
			insert(i, x);
			break;
		case 7:
			printf("Value: "); scanf("%d", &x);
			delete(x);
			break;
		case 8:
			return 0;
		default:
			printf("Invalid choice\n");
		}
	}
}





