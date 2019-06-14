#include <stdio.h>
#include <stdlib.h>
#define INF 10000

// �迭 ����� ����Ʈ {
int arr[INF];
int count = 0;

// �迭�� �޺κп� ���Ҹ� �߰��ϴ� �Լ�
void addBack(int data) {
	arr[count] = data;
	count++;
}

// �迭�� �պκп� ���Ҹ� �߰��ϴ� �Լ�
void addFirst(int data) {
	for (int i = count; i >= 1; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = data;
	count++;
}

// �迭�� Ư���κ� ���Ҹ� �����ϴ� �Լ�
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
// } �迭 ����� ����Ʈ

// ���� ����Ʈ {
typedef struct {
	int data;
	struct Node *next;

} Node;

// Node �� �׻� ������ ������ ���� �Ҵ��� �̿��Ͽ� ������ ����ϴ�.
Node *head;

// � ��ġ���� root�� �˷��ݴϴ�.
void addFront(Node *root, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	// �ϳ��� Node�� �������� �Ҵ���� ��
	node->data = data;
	// �ش� data���� ���Ӱ� ���� data���� �־��־� �ʱ�ȭ ���ݴϴ�.
	node->next = root->next;
	// root �� ����Ű�� ���� ���� next �� �Ҵ�
	root->next = node;
}

void removeFront(Node *root) {
	Node *front = root->next;
	root->next = front->next;
	free(front);
}

// ��ü ���Ҹ� �ϳ��� ��ó���� �޸� ������ ���ݴϴ�.
void freeAll() {
	Node *cur = head->next;
	while (cur != NULL)
	{
		Node *next = cur->next;
		// ���� ���Ҹ� �����Ŀ�
		free(cur);
		// ���� ����Ű�� ���Ҹ� �Ҵ� ���� ���ݴϴ�.
		cur = next;
		// cur �����͸� ���� Node�� ����Ų�� �ٽ� Ȯ���մϴ�.
	}
}

// ��� ���Ҹ� ����ϴ� �Լ�
void showAll(Node *root) {
	Node *cur = head->next;
	while (cur != NULL)
	{
		printf("%d �߷�", cur->data);
		cur = cur->next;
	}
}
// } ���� ����Ʈ

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

	// �ϳ��� �����͸� ������ ���� ��ü�� ���� Ȯ��
	Node *cur = head->next;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
		// ���� ���Ҹ� cur �� null �� ��涧���� ��� ����ϴ� ���
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