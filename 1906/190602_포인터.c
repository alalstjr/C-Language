#include <stdio.h>

int main(void) {
	// ������ ����
	int a = 5;
	int *b = &a;
	printf("%d\n", *b);

	// ������ �ּҰ� Ȯ��
	int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int i;

	for (i = 0; i < 10; i++) 
	{
		printf("%d\n", &c[i]);
	}

	// ���� ������
	int d = 5;
	int *e = &d;
	int **f = &e;
	printf("%d\n", **f);

	// �迭�� ������
	int g[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *h = g;
	printf("%d\n", h[2]);

	system("pause");
	return 0;
}