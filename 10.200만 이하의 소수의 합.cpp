#include<stdio.h>
#include<stdbool.h> // bool
#include<stdlib.h> // 배열이 크니 힙 영역 메모리를 떼오기 위함 //함수 끝나면 메모리 해제 꼭 해줄 것!
#define MAX 2000000

int main()
{
	bool* prime = (bool*)malloc(sizeof(bool) * (MAX + 1));
	double sum = 0;
	int i, j;

	for (i = 2; i < MAX; i++) // 모든 prime 값에 true 대입
	{
		prime[i] = true;
	}

	for (i = 2; i < MAX; i++)
	{
		if (prime[i] == true) // prime[i]이 true 이면 i의 배수가 되는 모든 prime값을 false로 바꿈
		{
			for (j = i + i; j < MAX; j += i)
			{
				prime[j] = false;
			}
		}
	}

	for (i = 2; i < MAX; i++)
	{
		if (prime[i] == true) // prime이 true이면, 즉, 어떤 수의 배수도 아닌 수(소수)를 모두 더해줌.
		{
			sum += (double)(i);
		}
	}
	free(prime);
	printf("합은 : %.lf", sum);
	return 0;
}