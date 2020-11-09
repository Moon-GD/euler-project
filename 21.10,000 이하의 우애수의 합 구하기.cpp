#include<stdio.h>

int main()
{
	int i = 2, j;
	int d = 0, temp = 0, sum = 0;

	while (1)
	{
		temp = 0, d = 0;
		i++;
		for (j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				d += j;
			}
		}

		for (j = 1; j < d; j++)
		{
			if (d % j == 0)
			{
				temp += j;
			}
		}
		if (temp == i && i != d) // 서로 다른 두 정수이기 때문
		{
			sum += i;
		}

		if (i > 10000) { break; }
	}
	printf("sum = %d", sum);

	return 0;
}