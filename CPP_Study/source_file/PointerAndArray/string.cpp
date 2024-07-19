#include <iostream>
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable:4996)

// [Hello0............................]
int StrLen(const char* str)
{
	int count = 0;

	while (str[count] != 0)
		count++;

	return count;
}

// [Hello0............................]
// [Hello0............................]
char* StrCpy(char* dest, char* src)
{
	char* ret = dest;
	int i = 0;

	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = 0;

	// 똑같은 코드
	//while (*src != 0)
	//{
	//	*dest = *src;
	//	*dest++;
	//	*src++;
	//}
	//*dest = 0;

	return ret;
}

// dest [Hello0............................]
// src [Hello0............................]
char* StrCat(char* dest, char* src)
{
	char* ret = dest;

	int len = StrLen(dest);
	
	int i = 0;
	while (src[i] != 0)
	{
		dest[len + i] = src[i];
		i++;
	}	

	dest[len + i] = 0;


	// 포인터를 사용한 방법
	//while (*dest != 0)
	//{
	//	*dest++;
	//}

	//while (*src != 0)
	//{
	//	*dest = *src;
	//	dest++;
	//	src++;
	//}
	return ret;
}

int main()
{
	//char str[] = { 'H','e','l','l','o','\0'};	
	// 널(0)을 넣지 않으면 0번을 만날 때까지 출력하므로 이상한 문자가 출력된다.

	//char str[] = "Hello";
	// 이런 스타일의 코딩은 구식이지만 알아야 한다.

	//const char* a;
	//char* const a;
	// 둘의 차이점

	//const char* ptr = "Hello";

	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	// [Hello0............................]
	char b[BUF_SIZE] = "World";

	int len = StrLen(a);
	std::cout << len << std::endl;

#pragma warniing(disable:4996)
	char c[BUF_SIZE];
	StrCpy(c, a);
	std::cout << c << std::endl;

	std::cout << StrCat(a, b) << std::endl;
	// 코테나 면접에 단골!!! 5~10분 내 문자열&포인터 묻기 딱 좋음
}