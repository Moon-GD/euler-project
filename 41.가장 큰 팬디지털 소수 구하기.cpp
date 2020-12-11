#include<stdio.h>
#include<string.h> // sprintf
#include<math.h> // log10, sqrt

int isPandigital(int i) // 팬디지털 여부
{
	char num[10];
	sprintf_s(num, "%d", i); // 각 자리 비교를 위해 문자열로 저장

	int ciper = (int)log10(i) + 1; // i의 자릿수

	for (int x = 0; x < ciper; x++)
	{
		for (int y = x + 1; y < ciper; y++)
		{
			if (num[y] > '0' + ciper) // 1~n 팬디지털 수인데, n을 넘어서는 수가 나오면 제외
				return 0;
			if (num[y] == '0') // 0이 들어가면 제외
				return 0;
			if (num[x] == num[y]) // 중복이 발생하면 제외
				return 0;
		}
	}
	return 1;
}

int isPrime(int i) // 소수 판별
{
	for (int j = 2; j <= sqrt(i); j++)
	{
		if (i % j == 0)
			return 0;
	}
	return 1;
}

int main()
{
	// 1~8, 1~9 팬디지털 수는 모두 3의 배수이기 때문에 고려 X
	// 1~7 팬지디털수부터 고려

	int i = 7654321;

	while (1)
	{
		if (isPandigital(i)) // 팬디지털 여부
		{
			if (isPrime(i)) // 소수 여부
			{
				printf("답은 %d", i);
				break;
			}
		}
		i--;
	}

	return 0;
}