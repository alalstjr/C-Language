# C 언어 1강

## C 언어 기초 프로그래밍

C 언어는 현재 사용되는 대부분의 <em>프로그래밍 언어의 기반</em>이며 <em>빠른 속도</em>의 언어 입니다.

## C 언어 Hello 코딩

{
1.  #include <stdio.h>

3.  int main(void)
    {
        printf("Hello World");
2.      return 0;
    }
}

1. 은 라이브 러리를 추가하는 부분으로 
ex) printf 같은 기능을 사용하기 위해서 stdio.h 라는 기본 라이브 러리를 불러와야 한다.

2. return 이란것은 하나의 함수가 종료될때 반환 해주는 지정된 약속 값
위에서 return 0 을 해주는 이유는 main 함수가 int 이기 때문에 프로그램의 반환값으로
정수값을 반환해 줘야 한다. C언어에서 약속한 체계

3. void 란 매개변수 특정한 함수를 실행할때 처리할 어떠한 값들을 받아 오는것

# C 언어 2강

## C 언어 변수

### Variables(변수), Constants(상수)
프로그래밍에는 변수 설정이 필수 이다.
변수란 프로그램이 실행되는 동안 언제든지 저장된 값이 변경될 수 있는 공간을 의미한다.
상수란 한번 정해지면 값을 변경할 필요가 없는 데이터를 의미한다.

ex) 자신의 방은 메모리이며, 방의 가구들은 변수, 장판이나 전구 같은것을 상수라 비유

{
    int main(void)
    {
        int x;
        x = 5;
        // printf("%d", x);
1.      printf("변수 x의 메모리 크기는 %d 입니다.", sizeof(x));
        return 0;
    }
}

1. %d 란 이자리에는 int 형의 값이 들어간다는 뜻으로
ex) ("%d", x) x 라는 값이 %d 에 들어갑니다.
sizeof 란 메모리 크기를 알려주는 기본 함수
C언어에서 변수가 int 라면 메모리값은 4바이트를 출력한다.


//////////////
{
    int main(void) 
    {
        int x = 50;
1.      float y = 123456789.123456789;
3.      double z = 123456789.123456789;
        printf("x = %d\n", x);
2.      printf("y = %f.2\n", y);
        printf("z = %f.2\n", z);
        return 0;
    }
}

1. float 이라는 실수 변수를 생성 담았습니다.
2. %d 가 int 형 저장소라면 %f 는 실수를 담는 저장소 입니다. 
%.2f 소수점은 해당 자리까지만 출력하라는 뜻
결과를 확인해보면 y = 123456792.00 기존 y 변수와는 다른 값이 출력됩니다.
이는 float 데이터형은 4byte 의 협소한 저장 공간이라 나머지는 지워지고 해당 영역만 저장된 것입니다.

3. 4byte 이상의 자료를 저장하기 위한 저장소 double 8byte를 저장할 수 있다.

//////////////
#Overflow 개념

{
    #include <limits.h>
    int main(void)
    {
1.      int x = INT_MAX;
    	printf("int형의 최대값 x는 %d 입니다. \n", x);
2.  	printf("x + 1은 %d 입니다.", x + 1);
        return 0;
    }
}

1. int 형이 가질 수 있는 최대값 INT_MAX 를 사용하기 위해서는 limits.h 라이브 러리를 불러와야 한다.
2. 만약에 최대값에서 1 을 더하면 -2147483648 으로 최소값으로 건너띄어 출력됩니다.

///////////////
# 간단한 사칙연산

{
    int main(void)
    {
        int x = 10;
        int y = 20;
        printf("x = %d 입니다.\n", x);
        printf("y = %d 입니다.\n", y);
        printf("x + y = %d 입니다.\n", x + y);
        printf("x - y = %d 입니다.\n", x - y);
        printf("x * y = %d 입니다.\n", x * y);
        printf("x / y = %d 입니다.\n", x / y);
        return 0;
    }
}

## C 언어 자료형
                Primitive => char, int, float, double, void
Data Type =     Derivied  => Array, Pointer, Function
                User defined => enum, Structure, Union

사용자 정의 자료형(User defined), 파생 자료형(Derivied), 흔히 말하는 자료형은 원시 자료형(Primitive)

C언어에서 문자를 표현할때는 char 자료형을 숫자는 int, float, double 를 사용한다.
void 는 자료형 자체가 없다는 의미하며
C언어에서는 문자열을 저장하는 string 자료형이 없고 char 자료형만을 사용하기 때문에 연속적으로 char 을 사용한다.

자료형 /데이터 타입
                        
Variables Data Type = Interger, Character, Float, Double

/////////////// 상수
{
    #include <stdio.h>
1.  #define MONTHS 12

    int main(void)
    {
        double monthSalary = 1000.5;
        printf("$ %.2f", monthSalary * MONTHS);
        return 0;
    }
}

1. C언어에서의 상수 선언 #define 을 작성후 변수를 작성한다.

/////////////// 문자
{
    #include <stdio.h>

    int main(void)
    {
1.      char x = 'A';
2.      printf("%c", x);
        char y = 65;
        printf("%c\n", y);
        char z = 'B';
        printf("%d", z);
        return 0;
    }
}

1. C언어의 char 은 내부적으로는 숫자를 이용한다.
예시로 char x 값을 65 숫자로 넣어 출력하면 'A' 가 출력되는 것을 확인할 수 있다. 
이를 아스킥 코드라고 한다.
2. 문자열의 출력은 %c 로 포함한다.
위 결과를 확인해 보면 A, A, 66 으로 출력된다.

/////////////// 형 변경
{
    #include <stdio.h>

    int main(void)
    {
        int x = 100;
        printf("10진수로 출력 : %d \n", x);
        printf("8진수로 출력 : %o", x);
        // 1 2 3 4 5 6 7 10 11 12 ... 
        printf("16진수로 출력 : %x", x);
        return 0;
    }
}

8진수란
1234567 한다음에 우리가 아는 숫자인 8을 표현하기 위해서 다시 10으로 되는 진법
