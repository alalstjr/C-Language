#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
#define INF 9999999

/******************************
	배열을 활용한 Stack 예제
*******************************/

int stack[SIZE];
int top = -1; // 스택의 최상단(입구)을 의미하는 변수

int push(int data) {
	if (top == SIZE - 1) {;
		printf("스택 오버플로우가 발생하였습니다. \n");
		return;
	}

	// top의 1을 더한값의 index에 값을 넣습니다.
	stack[++top] = data;
}

int pop() {
	// 원소가 하나도 들어가 있지 않는 상태라면
	if (top == -1) {
		printf("스택 언더플로우가 발생하였습니다. \n");
		return -INF;
	}

	// 현재 top이 가르키고 있는 원소값을 반환합니다.
	return stack[top--];
}

int show() {
	printf("---스택의 최상단---\n");
	for (int i = top; i >= 0; i--) {
		printf("%d\n", stack[i]);
	}
	printf("---스택의 최하단---\n");
}

/******************************
	연결리스트를 활용한 Stack 예제
*******************************/

typedef struct {
	int data;
	struct Node *next;
} Node;

typedef struct {
	Node *top;
} Stack;

void push(Stack *stack, int data) {
	// 하나의 Node 공간을 할당합니다.
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;

	node->next = stack->top;
	stack->top = node;
	// 현재 node로 top을 바꿔줍니다.
	// 항상 가장 마지막의 값이 top 이기 때문입니다.
}

void pop(Stack *stack) {
	if (stack->top == NULL) {
		printf("스택 언더플로우가 발생하였습니다. \n");
		return -INF;
	}

	// 기존의 Node에 현재 최상단 Node의 값을 잠시 담아둡니다.
	Node *node = stack->top;
	// data를 추출
	int data = node->data;

	// 두번째 Node가 최상단(top)될 수 있도록 합니다.
	stack->top = node->next;
	
	// 기존의 맨위 추출대상의 node는 할당 해제합니다.
	free(node);

	return data;
}

void show(Stack *stack) {
	Node *cur = stack->top;
	printf("---스택의 최상단---\n");
	while (cur != NULL)
	{
		print("%d\n", cur->data);
		cur = cur->next;
	}
	printf("---스택의 최하단---\n");
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
	// stack 의 언더플로우나 show의 반목문을 체크할 수 있습니다.
	s.top = NULL;
	// stack 의 포인터 값을 받도록 되어있으므로 메모리 주소(&)를 넣어야합니다.
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
