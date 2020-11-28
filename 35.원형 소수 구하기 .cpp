#include<stdio.h>
#include<math.h> // sqrt
#define MAX 1000000
int Prime(int i) // 소수이면 1을, 아니면 0을 반환
{
	for (int j = 2; j <= sqrt(i); j++)
	{
		if (i % j == 0)
			return 0;
	}
	return 1;
}

int Rotation(int i) // 순환
{
	int temp = 0;
	temp = i % 10;
	i /= 10;
	return (i + temp * pow(10, (int)log10(i) + 1));
}

int main()
{
	int cnt = 0, i, flag = 1;
	for (i = 2; i <= MAX; i++)
	{
		flag = 1;
		if (Prime(i))
		{
			int ciper = (int)log10(i) + 1;
			int temp = i;
			for (int j = 1; j < ciper; j++)
			{
				temp = Rotation(temp);
				if (!Prime(temp))
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				cnt++;
		}
	}

	printf("cnt = %d", cnt);

	return 0;
}