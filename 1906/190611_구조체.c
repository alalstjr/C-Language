#include <stdio.h>

// typedef Ȱ���� ����ü �����ϱ�
typedef struct Student
{
	char name[10];
	int year;
	char job[15];
} Student;

int main(void)
{
	Student* s = malloc(sizeof(Student));
	strcpy(s -> name, "jjunpro");
	strcpy(s -> job, "���α׷���");
	s->year = 4;
		
	printf("�̸� : %s \n", s->name);
	printf("�⵵ : %d \n", s->year);
	printf("���� : %s \n", s->job);

	system("pause");
	return 0;
}