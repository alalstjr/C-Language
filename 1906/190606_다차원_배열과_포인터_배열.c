#include <stdio.h>

int main(void) 
{
	// ������ �迭
	int a[2][3][3] = { 
		{
			{1, 2, 3}, {4, 5, 6}, {7, 8, 9}
		},
		{
			{1, 2, 3}, {4, 5, 6}, {7, 8, 9}
		}
	};

	int i, j, k;
	for (i = 0; i < 2; i++) 
	{
		for (j = 0; j < 3; j++) 
		{
			for (k = 0; k < 3; k++) 
			{
				printf("%d", a[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	int arr[5] = { 1, 2, 3, 4, 5 };
	int *c = &arr;

	printf("%d\n", c[2]);

	// �ڷ����� ũ�⸸ŭ ����
	int a_1[5] = { 1, 2, 3, 4, 5 };
	for (i = 0; i < 5; i++)
	{
		printf("%d\n", a_1 + i);
		printf("%d\n", *(a_1 + i));
	}

	// 2���� �迭 ������ ó��
	int as[2][5] = {
		{1, 2, 3, 4, 5}, 
		{6, 7, 8, 9, 10}
	};
	int(*p)[5] = as[1];
	for (i = 0; i < 5; i++) 
	{
		printf("%d", p[0][i]);
	}

	system("pause");
	return 0;
}