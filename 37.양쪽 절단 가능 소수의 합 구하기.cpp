#include<stdio.h>
#include<math.h>
int isPrime(int i) // 소수 판별
{
	if (i == 1 || i == 0)
		return 0;

	for (int j = 2; j <= sqrt(i); j++)
	{
		if (i % j == 0)
			return 0;
	}
	return 1;
}

int Left(int i) // 왼쪽 자르기
{
	int ciper = (int)log10(i) + 1;
	int temp = i / (int)pow(10, (double)ciper - 1);
	return i - temp * (int)pow(10, (double)ciper - 1);
}

int Right(int i) // 오른쪽 자르기
{
	return (int)(i / 10);
}

int main()
{
	int cnt = 0, sum = 0;

	for (int i = 10; cnt < 11; i++)
	{
		int flag = 1;
		if (isPrime(i))
		{
			int ciper = (int)log10(i);
			int x = i, y = i;
			for (int j = 1; j <= ciper; j++)
			{
				x = Left(x);
				y = Right(y);
				if (x < 0 || y < 0)
				{
					flag = 0;
					break;
				}
				if (!(isPrime(x) && isPrime(y)))
				{
					flag = 0;
					break;
				}
			}

			if (flag == 1)
			{
				printf("%d\n", i);
				cnt++, sum += i;
			}
		}
	}
	printf("답은 %d", sum);

	return 0;
}