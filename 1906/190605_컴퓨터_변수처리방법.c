#include <stdio.h>

// �������� a
int a = 5;

void changeValue() 
{
	// �������� a �� 10���� ����
	a = 10;
}

void process() 
{
	// ���α׷��� ����ʰ� ���ÿ� ���� a�� �޸� �� ���簡 �˴ϴ�.
	static int a = 5;
	// process() �Լ��� �ҷ��� ������ a�� 1 �� ���ϵ��� �մϴ�.
	a = a + 1;
	printf("���� ���� %d\n", a);
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
	printf("�������� %d\n", a);
	changeValue();
	printf("�������� %d\n", a);

	// �������� ����
	int b = 5;
	if (1) 
	{
		int b = 3;
	}
	printf("�������� %d\n", b);

	// �������� ����
	process();
	process();
	process();

	// �������� ���� ����
	register int a = 10, i;
	for (i = 0; i < a; i++) 
	{
		printf("�������� ���� %d\n", i);
	}

	// �Լ��� ���� ���� �Ű������� ó���� ��
	int c = 7;
	add(c, 10);
	printf("���� ���� %d\n", c);

	// �Լ��� ������ ���޹�� �Ű������� ó���� ��
	add2(&c, 10);
	printf("������ ���� %d\n", c);

	system("pause");
	return 0;
}