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

	// �Ȱ��� �ڵ�
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


	// �����͸� ����� ���
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
	// ��(0)�� ���� ������ 0���� ���� ������ ����ϹǷ� �̻��� ���ڰ� ��µȴ�.

	//char str[] = "Hello";
	// �̷� ��Ÿ���� �ڵ��� ���������� �˾ƾ� �Ѵ�.

	//const char* a;
	//char* const a;
	// ���� ������

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
	// ���׳� ������ �ܰ�!!! 5~10�� �� ���ڿ�&������ ���� �� ����
}