#include <stdio.h>

// 전역변수 a
int a = 5;

void changeValue() 
{
	// 전역변수 a 를 10으로 수정
	a = 10;
}

void process() 
{
	// 프로그램이 실행됨과 동시에 변수 a가 메모리 상에 적재가 됩니다.
	static int a = 5;
	// process() 함수를 불러올 때마다 a에 1 씩 더하도록 합니다.
	a = a + 1;
	printf("정적 변수 %d\n", a);
}

void add(int a, int b) 
{
	a = a + b;
}
void add2(int *a, int b) 
{
	(*a) = (*a) + b;
}

int main(void) 
{
	printf("전역변수 %d\n", a);
	changeValue();
	printf("전역변수 %d\n", a);

	// 지역변수 예제
	int b = 5;
	if (1) 
	{
		int b = 3;
	}
	printf("지역변수 %d\n", b);

	// 정젹변수 예제
	process();
	process();
	process();

	// 레지스터 변수 예제
	register int a = 10, i;
	for (i = 0; i < a; i++) 
	{
		printf("레지스터 변수 %d\n", i);
	}

	// 함수의 값의 참조 매개변수가 처리될 때
	int c = 7;
	add(c, 10);
	printf("값의 참조 %d\n", c);

	// 함수의 참조의 전달방식 매개변수가 처리될 때
	add2(&c, 10);
	printf("참조의 전달 %d\n", c);

	system("pause");
	return 0;
}