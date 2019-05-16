#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 99999999

// 자료를 담는 노드
typedef struct Node{ 
	char data[100];
	struct Node *next; // 자신보다 한 발 빨리 들어간 녀석을 가리킨다
} Node;

// 노드를 담는 스택
typedef struct Stack{ 
	struct Node *top; // 가장 나중에 들어온 노드를 가리킨다. 이하 천장이라 표기함
} Stack;

// 스택에 data를 추가
void push(Stack *stack, char *data)
{
	Node *node = (Node*)malloc(sizeof(Node)); // 노드 생성
	strcpy(node->data, data); // 인자값 data를 복사(주소 복사가 아니라 자료 복사)하여 노드에 대입
	node->next = stack->top; // 노드의 next 주소값을 기존 스택이 가지고 있던 top으로 설정
	stack->top = node; // 스택 천장을 자신으로 함
}

// 스택 천장에서 char형 자료를 취득
char* getTop(Stack *stack)
{
	Node *top = stack->top;
	return top->data;
}

// 스택 천장에 해당되는 노드를 빼낸다. 이 때 노드가 가리키는 주소값은 필요가 없으므로 최종적으로 char만 취함
char* pop(Stack *stack)
{
	if (stack->top == NULL) // 들어간 노드가 없으면 없는 주소를 검색하게 되므로 오류 구문을 출력
	{
		printf("스택 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	Node *node = stack->top;
	char *data = (char*)malloc(sizeof(char) * 100); // 노드를 지워도 자료는 남아야 하기 때문에 자료를 위한 힙 공간을 확보한다
	strcpy(data, node->data);
	stack->top = node->next; // 스택 천장을 가리키는 주소를 자기보다 먼저 들어온 노드로 함
	free(node); // 메모리를! 해방하라!
	return data;
}

// 우선순위 도출. 숫자가 높을수록 우선순위가 높은것
int getPriority(char *i)
{
	// strcmp 는 검색하려는 문자와 동일할 경우 0(false)을 반환함. 여기서는 ! 를 넣었으므로, 동일한 경우에 false가 아닌 true 가 된다
	if (!strcmp(i, "(")) // 괄호 열기인 경우 우선순위 0
		return 0;
	if (!strcmp(i, "+") || !strcmp(i, "-")) // 덧뺄셈의 경우 우선순위 1
		return 1;
	if (!strcmp(i, "*") || !strcmp(i, "/")) // 곱나눗셈의 경우 덧뺄셈보다 먼저 계산해야하니 우선순위 2
		return 2;
	return 3; // 괄호 닫기나 숫자가 나오는 경우 우선순위 3
}

// 중위 표기법을 후위 표기법으로 변환, 그렇게 변환된 배열은 반환
// *stack = 계산용 스택, **s = 중위 표기법 문자열, size = 그런 문자열의 배열 크기
char* transition(Stack *stack, char **s, int size)
{
	char res[1000] = ""; // 후위 표기법 문자열. 배열 크기를 크게 잡는 이유는 strcmp, strcat 가 이상한 구역을 참조할 가능성이 있기 때문
	for (int i = 0; i < size; i++)
	{
		// s[i]가 사칙연산 +-*/ 인지 알아낸다. 
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/"))
		{
			// 스택이 비어있지 않고, 스택 천장의 우선순위가 s[i] 보다 높다면 반복한다
			// 처음엔 스택이 비어있기 때문에 해당사항 없음
			while (stack->top != NULL && getPriority(getTop(stack)) >= getPriority(s[i]))
			{
				strcat(res, pop(stack)); // 후위 표기법 문자열에 스택 천장값을 복사, 끝에다가 붙인다
				strcat(res, " "); // 토큰화를 위한 띄어쓰기
			}
			push(stack, s[i]); // 스택에 s[i]를 넣는다
		}
		// 사칙연산 검색이 안된 경우
		else if (!strcmp(s[i], "(") ) // ( 라면
			push(stack, s[i]); // 스택에 넣는다
		else if (!strcmp(s[i], ")")) // 만약 ) 라면
		{
			// 스택 천장이 ( 가 나올때까지 스택을 계속 뜯어낸다
			while (strcmp(getTop(stack), "(")) 
			{
				strcat(res, pop(stack)); // 뜯어서 나오는 숫자, 연산자들을 전부 후위 표기법 문자열에 넣는다
				strcat(res, " "); // 토큰화를 위한 공백
			}
			pop(stack); // 마지막으로 나오는 ( 는 연산에는 전혀 쓸모가 없으므로 그냥 지워버린다
			
		}
		else // 그냥 숫자인 경우에는 문자열에 바로 복붙한다
			strcat(res, s[i]);
		strcat(res, " "); // 조건문이 끝나면 무조건 토큰화를 위한 공백을 넣는다
	} 
	while (stack->top != NULL)
	{
		strcat(res, pop(stack));
		strcat(res, " ");
	}

	/*
	이렇게 하여 중위 표기법 문자열 s 가 " 5 + ( 5 * 4 + 3 ) "(결과로는 28이 나온다) 라고 할 때,
	숫자가 있으므로 res = "5 "
	+ 가 있으므로 스택 = { '+' }
	( 가 있으므로 스택 = { '+' '(' }
	숫자가 있으므로 res = "5 5 "
	* 가 나오는데 스택이 비어있지 않으므로 getPriority(getTop(stack)) >= getPriority(s[i]) 대조를 한다
		( 는 우선순위 0, * 는 우선순위 2 이므로 while문에 해당되지 않음
		스택 = { '+' '(' '*' }
	숫자가 있으므로 res = "5 5 4 "
	+ 가 나오는데 스택이 비어있지 않으므로 getPriority(getTop(stack)) >= getPriority(s[i]) 대조를 한다
		* 는 우선순위 2, + 는 우선순위 1 이므로 while문에 해당됨
			스택을 뜯어내 * 를 res에 대입
			res = "5 5 4 * "
			스택 = { '+' '(' }
		( 는 우선순위 0, + 는 우선순위 1 이므로 while문에 해당되지 않음. 고로 push
		스택 = { '+' '(' '+' }
	숫자가 있으므로 res = "5 5 4 * 3 "
	이제 ) 가 나왔으므로, ( 가 나올 때까지 스택을 전부 뜯는다(그와중에 '(' 와 ')' 는 res에 쓰지 않음)
		스택의 역순으로 res에 기록하기 때문에, ( 가 나올때까지 반복하면
		스택 = { '+' }
		res = "5 5 4 * 3 + "
	중위 표기법 문자열을 전부 검색했으므로 스택에 있는 연산자를 전부 빼면
	res = "5 5 4 * 3 + + "
	라고 표기가 가능해진다
	*/

	return res;
}

// 후위 표기법 문자열로 연산을 실행
void calculate(Stack *stack, char **s, int size)
{
	int x, y, z;
	for (int i = 0; i < size; i++)
	{
		// 사칙연산이 나온 경우에는 계산을 실행한다
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/"))
		{
			// atoi 는 문자(열)에서 정수만 빼오는 함수
			x = atoi(pop(stack)); // 스택의 천장값을 빼 x로 취한다
			y = atoi(pop(stack)); // 스택의 천장값을 또 빼서 y로 취한다
			// 아래로는 계산
			if (!strcmp(s[i], "+"))
				z = y + x;
			if (!strcmp(s[i], "-"))
				z = y - x;
			if (!strcmp(s[i], "*"))
				z = y * x;
			if (!strcmp(s[i], "/"))
				z = y / x;
			char buffer[100];
			// sprintf 는 원하는 다른 자료형의 변수를 문자(열)로 만드는 함수. printf와는 다르다 printf와는!
			sprintf(buffer, "%d", z); 
			push(stack, buffer); // 계산이 끝난 값을 스택에 넣는다
		}
		// 그렇지 않은 경우에는 100% 숫자이므로, 숫자를 스택에 넣는다
		else
		{
			push(stack, s[i]);
		}
	}

	/*
	이렇게 하여 후위 표기법 문자열 s 가 "5 5 4 * 3 + + " 라고 할 때,
	숫자가 있으므로 스택 = { '5' }
	숫자가 있으므로 스택 = { '5' '5' }
	숫자가 있으므로 스택 = { '5' '5' '4' }
	*가 있으므로
	  스택의 가장 나중 값인 5와 4를 곱함
	  스택 = { '5' '20' }
	숫자가 있으므로 스택 = { '5' '20' '3' }
	+가 있으므로
	  스택의 가장 나중 값인 20과 4를 더함
	  스택 = { '5' '23' }
	+가 있으므로
	  스택의 가장 나중 값인 5와 23을 더함
	  스택 = { '28' }
	의 연산이 가능
	*/
	printf("%s ", pop(stack)); //	마지막 while 문이 끝날 땐 무적권 하나의 스택만이 남으므로, 결과값을 출력해주면 끝
}

int main(void)
{
	// 스택 선언
	Stack stack;
	stack.top = NULL;
	// 문자열 선언
	//char a[100] = "( ( 3 + 4 ) * 5 ) - 5 * 7 * 5 - 5 * 10";
	char a[100] = "5 + ( 5 * 4 + 3 )";
	// 공백의 갯수 선언
	int size = 1;
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == ' ') size++; // 문자열에 공백이 나올 때마다 size가 늘어난다
	}
	// strtok는 두번째 인자값에 해당하는 문자가 나오기 전까지의 a로, a는 그만큼 잘려나간다
	char *ptr = strtok(a, " ");  // a를 한 번 쪼개, 그 문자를 ptr에 할당받음
	char **input = (char**)malloc(sizeof(char*) * size); // 최종 인풋값에 문자열 길이만큼의 메모리를 할당받는다. 포인터 배열에 주의
	for (int i = 0; i < size; i++)
		input[i] = (char*)malloc(sizeof(char) * 100); // 낭비 오져
	for (int i = 0; i < size; i++)
	{
		strcpy(input[i], ptr); // 포인터 배열 input의 i번 인덱스에 ptr의 주소를 할당받음
		ptr = strtok(NULL, " "); // a를 계속해서 쪼개, 그 문자를 ptr에 할당받음
		// 같은 strtok 인데 앞에서는 a를 쓰고 뒤에서는 NULL을 쓴 이유는, strtok 함수 자체가 인자값을 static으로 저장해 보유하고 있기 때문이다
		// NULL을 입력하면 strtok은 '첫번째 인자값이 NULL이네? 그럼 이전에 저장해뒀던 문자열 써야지 ㅎㅎ'을 시전하게끔 만들어져있음
	}
	/*
	이렇게 토크나이징을 시전하면
	{ '(', ' ', '(', ' ', '3', ' ', '+', ' ', '4', ' ', ')' ... }
	이랬던 문자열이
	{ '(', '(', '3', '+', '4', ')' ... } 이런 식으로 바뀜
	더불어 size 또한 이런 문자열의 크기와 똑같기 때문에, 최종적으로 쓰게 될 문자열이 완성된다
	*/
	char b[1000] = "";
	strcpy(b, transition(&stack, input, size));
	printf("후위 표기법: %s\n", b);
	system("pause");
	return 0;
}