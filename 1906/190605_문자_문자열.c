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
	// 한 자씩 받아서 파일의 끝(EOF 파일로 입력을 받을 경우)이거나 
	// 개행 문자를 만나면 입력을 멈추므로 항상 입력 버퍼를 비워줍니다.
	// temp 에 입력받은 값을 넣어서 EOF와 Enter(줄바꿈) 를 비교하여 조건이 맞다면 그냥 넘어가도록 합니다.
	while ((temp = getchar()) != EOF && temp != '\n') {}

	scanf("%c", &c);
	printf("%c\n", c);

	// 공백을 포함한 입출력
	char a_1[100];
	gets_s(a_1, sizeof(a_1));
	printf("%s\n", a_1);

	// strlen() 문자열의 길이를 반환하는 함수
	char a_2[20] = "JJun Pro";
	printf("%d\n", strlen(a_2));

	// strcmp() 문자열 1이 문자열 2보다 사전적으로 앞에 있으면 -1, 뒤에 있으면 1 을 반환
	char a_3[20] = "JJun Pro";
	char a_4[20] = "Blog Page";
	printf("%d\n", strcmp(a_3, a_4));

	// strcpy() 문자열을 복사합니다.
	char a_5[20] = "JJun Pro";
	char a_6[20] = "Blog Page";
	strcpy(a_5, a_6);
	printf("복사된 문자열: %s\n", a_5);

	// strcat() 뒤에 있는 문자열을 앞에 있는 문자열에 합칩니다.
	char a_7[30] = "JJun Pro";
	char a_8[20] = "Blog Page";
	strcpy(a_7, a_8);
	printf("복사된 문자열: %s\n", a_7);

	char a_9[20] = "JJun Pro Blog";
	char a_10[20] = "Pro";
	strstr(a_9, a_10);
	printf("찾은 문자열: %s\n", a_9);

	system("pause");
	return 0;
}