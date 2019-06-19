#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
#define INF 9999999

/******************************
	�迭�� Ȱ���� Stack ����
*******************************/

int stack[SIZE];
int top = -1; // ������ �ֻ��(�Ա�)�� �ǹ��ϴ� ����

int push(int data) {
	if (top == SIZE - 1) {;
		printf("���� �����÷ο찡 �߻��Ͽ����ϴ�. \n");
		return;
	}

	// top�� 1�� ���Ѱ��� index�� ���� �ֽ��ϴ�.
	stack[++top] = data;
}

int pop() {
	// ���Ұ� �ϳ��� �� ���� �ʴ� ���¶��
	if (top == -1) {
		printf("���� ����÷ο찡 �߻��Ͽ����ϴ�. \n");
		return -INF;
	}

	// ���� top�� ����Ű�� �ִ� ���Ұ��� ��ȯ�մϴ�.
	return stack[top--];
}

int show() {
	printf("---������ �ֻ��---\n");
	for (int i = top; i >= 0; i--) {
		printf("%d\n", stack[i]);
	}
	printf("---������ ���ϴ�---\n");
}

/******************************
	���Ḯ��Ʈ�� Ȱ���� Stack ����
*******************************/

typedef struct {
	int data;
	struct Node *next;
} Node;

typedef struct {
	Node *top;
} Stack;

void push(Stack *stack, int data) {
	// �ϳ��� Node ������ �Ҵ��մϴ�.
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;

	node->next = stack->top;
	stack->top = node;
	// ���� node�� top�� �ٲ��ݴϴ�.
	// �׻� ���� �������� ���� top �̱� �����Դϴ�.
}

void pop(Stack *stack) {
	if (stack->top == NULL) {
		printf("���� ����÷ο찡 �߻��Ͽ����ϴ�. \n");
		return -INF;
	}

	// ������ Node�� ���� �ֻ�� Node�� ���� ��� ��ƵӴϴ�.
	Node *node = stack->top;
	// data�� ����
	int data = node->data;

	// �ι�° Node�� �ֻ��(top)�� �� �ֵ��� �մϴ�.
	stack->top = node->next;
	
	// ������ ���� �������� node�� �Ҵ� �����մϴ�.
	free(node);

	return data;
}

void show(Stack *stack) {
	Node *cur = stack->top;
	printf("---������ �ֻ��---\n");
	while (cur != NULL)
	{
		print("%d\n", cur->data);
		cur = cur->next;
	}
	printf("---������ ���ϴ�---\n");
}

int main(void) {
	push(1);
	push(2);
	push(3);
	pop();
	push(4);
	push(5);
	show();

	Stack s;
	// stack �� ����÷ο쳪 show�� �ݸ��� üũ�� �� �ֽ��ϴ�.
	s.top = NULL;
	// stack �� ������ ���� �޵��� �Ǿ������Ƿ� �޸� �ּ�(&)�� �־���մϴ�.
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	pop(&s);
	push(&s, 4);
	push(&s, 5);
	show(&s);

	system("pause");
	return 0;
}
