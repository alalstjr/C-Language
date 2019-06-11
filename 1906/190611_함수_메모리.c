#include <stdio.h>

// 함수포인터 예제 함수
void myFunction() 
{
	printf("my 함수\n");
}
void yourFunction()
{
	printf("your 함수\n");
}

// 함수 포인터를 반환하여 사용하기 함수
int add(int a, int b) 
{
	return a + b;
}
int(*process(char* a))(int, int)
{
	printf("%s\n", a);
	return add;
}

int main(void) 
{
	/*
	myFunction() 함수와 yourFunction() 함수 모두 void 형을 반환함으로 
	void 반환 자료형을 가지고있는 fp 포인터를 선언합니다.
	
	처음에는 fp포인터 함수가 myFunction() 을 가리키도록 하고
	다음 fp포인터 함수가 yourFunction() 를 가리키도록 합니다.
	*/
	void(*fp)() = myFunction;
	fp();

	fp = yourFunction;
	fp();

	printf("%d\n", process("5와 10을 더합니다.")(5, 10));

	system("pause");
	return 0;
}