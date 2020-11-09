#include<stdio.h>

int Prime(int i)									// 소수 판별 함수
{
	int j;
	for (j = 2; j < i; j++)
	{
		if (i % j == 0)
			return 0;								// 소수가 아니면 0을 반환
	}
	return 1;										// 소수이면 1을 반환
}

int main()
{
	long long n = 600851475143, i;

	for (i = 2; i <= n; i++)
	{
		if (n % i == 0)								 // i가 주어진 수의 약수일때
		{
			if (Prime(i) == 1)						 // 1을 반환받는다면 출력
				printf("%lld\n", i);
			n = n / i;								// n을 나누어 주어 계산 용량을 줄여줌.
		}
	}

	return 0;
}
// 71 839 1471 6857 이 출력되므로 가장 큰 소인수는 6857