#include <stdio.h>

// �Լ������� ���� �Լ�
void myFunction() 
{
	printf("my �Լ�\n");
}
void yourFunction()
{
	printf("your �Լ�\n");
}

// �Լ� �����͸� ��ȯ�Ͽ� ����ϱ� �Լ�
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
	myFunction() �Լ��� yourFunction() �Լ� ��� void ���� ��ȯ������ 
	void ��ȯ �ڷ����� �������ִ� fp �����͸� �����մϴ�.
	
	ó������ fp������ �Լ��� myFunction() �� ����Ű���� �ϰ�
	���� fp������ �Լ��� yourFunction() �� ����Ű���� �մϴ�.
	*/
	void(*fp)() = myFunction;
	fp();

	fp = yourFunction;
	fp();

	printf("%d\n", process("5�� 10�� ���մϴ�.")(5, 10));

	system("pause");
	return 0;
}