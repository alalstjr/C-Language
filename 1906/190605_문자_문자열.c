#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	// char a = 65;
	// char a = getchar();
	int a;
	char c;
	scanf("%d", &a);
	printf("%d\n", a);
	
	int temp;
	// �� �ھ� �޾Ƽ� ������ ��(EOF ���Ϸ� �Է��� ���� ���)�̰ų� 
	// ���� ���ڸ� ������ �Է��� ���߹Ƿ� �׻� �Է� ���۸� ����ݴϴ�.
	// temp �� �Է¹��� ���� �־ EOF�� Enter(�ٹٲ�) �� ���Ͽ� ������ �´ٸ� �׳� �Ѿ���� �մϴ�.
	while ((temp = getchar()) != EOF && temp != '\n') {}

	scanf("%c", &c);
	printf("%c\n", c);

	// ������ ������ �����
	char a_1[100];
	gets_s(a_1, sizeof(a_1));
	printf("%s\n", a_1);

	// strlen() ���ڿ��� ���̸� ��ȯ�ϴ� �Լ�
	char a_2[20] = "JJun Pro";
	printf("%d\n", strlen(a_2));

	// strcmp() ���ڿ� 1�� ���ڿ� 2���� ���������� �տ� ������ -1, �ڿ� ������ 1 �� ��ȯ
	char a_3[20] = "JJun Pro";
	char a_4[20] = "Blog Page";
	printf("%d\n", strcmp(a_3, a_4));

	// strcpy() ���ڿ��� �����մϴ�.
	char a_5[20] = "JJun Pro";
	char a_6[20] = "Blog Page";
	strcpy(a_5, a_6);
	printf("����� ���ڿ�: %s\n", a_5);

	// strcat() �ڿ� �ִ� ���ڿ��� �տ� �ִ� ���ڿ��� ��Ĩ�ϴ�.
	char a_7[30] = "JJun Pro";
	char a_8[20] = "Blog Page";
	strcpy(a_7, a_8);
	printf("����� ���ڿ�: %s\n", a_7);

	char a_9[20] = "JJun Pro Blog";
	char a_10[20] = "Pro";
	strstr(a_9, a_10);
	printf("ã�� ���ڿ�: %s\n", a_9);

	system("pause");
	return 0;
}