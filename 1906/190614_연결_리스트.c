#include <stdio.h>
#include <stdlib.h>
#define INF 10000

// 배열 기반의 리스트 {
int arr[INF];
int count = 0;

// 배열의 뒷부분에 원소를 추가하는 함수
void addBack(int data) {
	arr[count] = data;
	count++;
}

// 배열의 앞부분에 원소를 추가하는 함수
void addFirst(int data) {
	for (int i = count; i >= 1; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = data;
	count++;
}

// 배열의 특정부분 원소를 삭제하는 함수
void removeAt(int index) {
	for (int i = index; i < count - 1; i++) {
		arr[i] = arr[i + 1];
	}
	count--;
}

void show() {
	for (int i = 0; i < count; i++) {
		printf("%d ", arr[i]);
	}
}
// } 배열 기반의 리스트

// 연결 리스트 {
typedef struct {
	int data;
	struct Node *next;

} Node;

// Node 는 항상 포인터 변수로 동적 할당을 이용하여 변수를 만듭니다.
Node *head;

// 어떤 위치인지 root로 알려줍니다.
void addFront(Node *root, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	// 하나의 Node를 동적으로 할당받은 후
	node->data = data;
	// 해당 data값을 새롭게 넣을 data값을 넣어주어 초기화 해줍니다.
	node->next = root->next;
	// root 가 가르키는 다음 값을 next 에 할당
	root->next = node;
}

void removeFront(Node *root) {
	Node *front = root->next;
	root->next = front->next;
	free(front);
}

// 전체 원소를 하나씩 거처가며 메모리 해제를 해줍니다.
void freeAll() {
	Node *cur = head->next;
	while (cur != NULL)
	{
		Node *next = cur->next;
		// 다음 원소를 저장후에
		free(cur);
		// 현재 가리키는 원소를 할당 해제 해줍니다.
		cur = next;
		// cur 포인터를 다음 Node를 가리킨후 다시 확인합니다.
	}
}

// 모든 원소를 출력하는 함수
void showAll(Node *root) {
	Node *cur = head->next;
	while (cur != NULL)
	{
		printf("%d 추력", cur->data);
		cur = cur->next;
	}
}
// } 연결 리스트

int main(void)
{
	addBack(1);
	addBack(4);
	addBack(7);
	addFirst(3);
	addFirst(2);
	show();

	head = (Node*)malloc(sizeof(Node));

	Node *node1 = (Node*)malloc(sizeof(Node));
	node1->data = 1;

	Node *node2 = (Node*)malloc(sizeof(Node));
	node2->data = 2;

	head->next = node1;
	node1->next = node2;
	node2->next = NULL;

	// 하나의 포인터를 별도로 만들어서 전체의 값을 확인
	Node *cur = head->next;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
		// 다음 원소를 cur 에 null 이 담길때까지 담아 출력하는 방식
	}

	addFront(head, 2);
	addFront(head, 4);
	addFront(head, 6);
	addFront(head, 8);
	addFront(head, 10);
	removeFront(head);
	showAll(head);
	freeAll(head);

	system("pause");
	return 0;
}