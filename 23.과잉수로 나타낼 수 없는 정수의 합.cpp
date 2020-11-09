#include<stdio.h>
#include<stdlib.h> // malloc
#include<stdbool.h> // bool
#define max 28123
bool num[max + 1];

int abudant(int n) // 완전수 판별 함수
{
	int i, sum = 0;

	for (i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			sum += i;
		}
	}
	if (sum > n)
		return n;
	else
		return 0;
}

int main()
{
	int size = 0, i, j, sum = 0;

	for (i = 1; i <= max; i++)  // 1~28123 까지의 값에 true 대입, 마지막까지 true인 값만 더해주기.
		num[i] = true;

	for (i = 12; i < max; i++)
	{
		if (abudant(i) != 0)
			size++;
	}

	int* array = (int*)malloc(sizeof(int) * size + 1); // 완전수 대입 해줄 배열 동적 할당
	int n = 0;

	for (i = 12; i < max; i++) // array에 완전수 대입
	{
		if (abudant(i) != 0)
			array[n++] = abudant(i);
	}

	for (i = 0; i < size; i++)
	{
		for (j = i; array[i] + array[j] <= max; j++)
		{
			num[array[i] + array[j]] = false; // 완전수의 합으로 표현되는 수는 false 로 표현
		}
	}

	sum = 0;

	for (i = 1; i <= max; i++)
	{
		if (num[i] == true) // true로 표현되는 수만 모두 더함
			sum += i;
	}

	printf("sum = %d", sum);
	free(array); // 메모리 해제
	return 0;
}