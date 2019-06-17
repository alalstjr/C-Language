#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

// Head�� Tail �� ��� �������־ 
// �յڷ� ��� ������ �����ϴٴ� Ư¡�� ������ �ֽ��ϴ�.
Node *head, *tail;

void insert(int data) {
	// Node�� �Ҵ��մϴ�.
	Node* node = (Node*)malloc(sizeof(Node));
	// data ���� �ʱ�ȭ �մϴ�.
	node->data = data;
	// cur ���� Ȱ���Ͽ� Node�� �� ��ġ�� ���� �� �ֵ��� �մϴ�.
	Node* cur;
	cur = head->next; // ù��° ����

	/*
	ù��° ���Һ��� �ϳ��� �����͸� Ȯ���ϸ鼭 ����ڰ� �ְ��� �ϴ� data����
	���� ����Ű�� ������(cur)�� data�� �� ������ ����ؼ� ���������� �����մϴ�.
	tail�ƴѰ�� ������ ���ұ����� �����մϴ�.
	*/
	while (cur->data < data && cur != tail)
	{
		// ���� Node�� ����Ű�� ���� cur�� �ֽ��ϴ�.
		cur = cur->next;// (���� Node)
	}

	// ���� ������ ��ġ���� ����Node�� prev ��ġ�� ����ݴϴ�.
	Node* prev = cur->prev; // (���� Node)
	
	// 1. ������ ��ġ���� ������ Node�� next�� ������ Node�� ����Ű���� �մϴ�.
	// 2. ������ Node�� ������ Node�� ����ŵ�ϴ�.
	prev->next = node;
	node->prev = prev;

	// 3. �������� ������ Node�� ������ Node�� ����Ű���� �մϴ�.
	// 4. ������ Node�� ������ Node�� ����Ű���� �մϴ�.
	cur->prev = node;
	node->next = cur;
}

void removeFront() {
	// 1. Head�� next�� ������ ������ ���� prev�� ����Ű���� �մϴ�.
	Node* node = head->next; // ù��° ����
	head->next = node->next;

	// 2. ������ ������ ���� Node�� prev�� Head�� next�� ����ŵ�ϴ�.
	Node* next = node->next;
	next->prev = head;
	free(node);
}

void show() {
	Node* cur = head->next; // ù��° ����

	// cur�� ������ ���ұ��� ����
	while (cur != tail) {
		printf("%d", cur->data);
		// ����� ���� Node�� ����Ŵ
		cur = cur->next;
	}
}

int main(void) {
	// head�� tail �޸� �Ҵ��� ���־ ��� �����ϵ��� �մϴ�.
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	// ���۰� ���� Ȯ���ϱ� ���ؼ� head�� tail���
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