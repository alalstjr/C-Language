#include <stdio.h>

// typedef 활용한 구조체 정의하기
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
	strcpy(s -> job, "프로그래머");
	s->year = 4;
		
	printf("이름 : %s \n", s->name);
	printf("년도 : %d \n", s->year);
	printf("직업 : %s \n", s->job);

	system("pause");
	return 0;
}