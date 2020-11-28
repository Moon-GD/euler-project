#define _CRT_SECURE_NO_WARNINGS // sprintf 경고 무시
#include<stdio.h> //sprintf
#include<string.h> // strrev, strcpy
#define MAX 1000000

int main()
{
	int i;
	int sum = 0;

	for (i = 1; i < MAX; i++)
	{
		char array[10];
		char temp[10] = {};
		sprintf(array, "%d", i); // 정수 i를 array에 문자열로 저장
		strcpy(temp, array); // temp에 array 복사

		if (strcmp(_strrev(array), temp) != 0) // 대칭수가 아니면 continue
		{
			continue;
		}

		char Two[30], Temp[30] = {}; // 2진수로 나타낼 배열과 임시 배열
		int x = i;
		int k = 0; // Two의 Index

		while (x > 0) // 2진법으로 나타내서 문자열로 저장
		{
			Two[k++] = '0' + x % 2;
			x /= 2;
		}

		Two[k] = NULL; // 쓰레기값 방지를 위해 널문자 대입
		strcpy(Temp, Two); //Temp에 Two 복사

		if (strcmp(Two, _strrev(Temp)) == 0) // 2진수도 대칭수이면 합산
		{
			sum += i;
		}
	}
	printf("합은 : %d", sum);

	return 0;
}