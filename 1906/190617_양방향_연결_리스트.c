#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

// Head와 Tail 을 모두 가지고있어서 
// 앞뒤로 모두 접근이 가능하다는 특징을 가지고 있습니다.
Node *head, *tail;

void insert(int data) {
	// Node를 할당합니다.
	Node* node = (Node*)malloc(sizeof(Node));
	// data 값을 초기화 합니다.
	node->data = data;
	// cur 값을 활용하여 Node가 들어갈 위치를 정할 수 있도록 합니다.
	Node* cur;
	cur = head->next; // 첫번째 원소

	/*
	첫번째 원소부터 하나씩 데이터를 확인하면서 사용자가 넣고자 하는 data보다
	현재 가리키는 포인터(cur)의 data가 더 작을때 계속해서 오른쪽으로 전진합니다.
	tail아닌경우 마지막 원소까지만 실행합니다.
	*/
	while (cur->data < data && cur != tail)
	{
		// 다음 Node를 가리키는 값을 cur에 넣습니다.
		cur = cur->next;// (뒤쪽 Node)
	}

	// 삽이 원소의 위치에서 앞쪽Node의 prev 위치를 잡아줍니다.
	Node* prev = cur->prev; // (앞쪽 Node)
	
	// 1. 삽입할 위치에서 앞쪽의 Node의 next가 삽입할 Node를 가리키도록 합니다.
	// 2. 삽입할 Node가 앞쪽의 Node를 가르킵니다.
	prev->next = node;
	node->prev = prev;

	// 3. 다음에는 뒤쪽의 Node가 삽입할 Node를 가리키도록 합니다.
	// 4. 삽입할 Node가 뒤쪽의 Node를 가리키도록 합니다.
	cur->prev = node;
	node->next = cur;
}

void removeFront() {
	// 1. Head의 next가 삭제할 원소의 다음 prev를 가리키도록 합니다.
	Node* node = head->next; // 첫번째 원소
	head->next = node->next;

	// 2. 삭제할 원소의 다음 Node의 prev가 Head의 next를 가르킵니다.
	Node* next = node->next;
	next->prev = head;
	free(node);
}

void show() {
	Node* cur = head->next; // 첫번째 원소

	// cur이 마지막 원소까지 실행
	while (cur != tail) {
		printf("%d", cur->data);
		// 출력후 다음 Node를 가리킴
		cur = cur->next;
	}
}

int main(void) {
	// head와 tail 메모리 할당을 해주어서 사용 가능하도록 합니다.
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	// 시작과 끝을 확인하기 위해서 head와 tail사용
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
	insert(2);
	insert(1);
	insert(3);
	insert(9);
	insert(7);
	removeFront();
	show();
	system("pause");
	return 0;
}