#include <stdio.h>

int main(void) {
	// 포인터 선언
	int a = 5;
	int *b = &a;
	printf("%d\n", *b);

	// 포인터 주소값 확인
	int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int i;

	for (i = 0; i < 10; i++) 
	{
		printf("%d\n", &c[i]);
	}

	// 다중 포인터
	int d = 5;
	int *e = &d;
	int **f = &e;
	printf("%d\n", **f);

	// 배열과 포인터
	int g[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *h = g;
	printf("%d\n", h[2]);

	system("pause");
	return 0;
}