#include<stdio.h>

int isComposite(int f)
{
	int i;
	for (i = 2; i < f; i++)
	{
		if (f % i == 0)
			return 1;
	}
	return 0;
}

int main()
{
	int a, b, n;
	int max_n = 0, max_a = 0, max_b = 0;

	for (a = -1000; a <= 1000; a++)
	{
		for (b = -1000; b <= 1000; b++)
		{
			for (n = 0;; n++)
			{
				int f = n * n + a * n + b;
				if (f <= 1)
					break;
				if (isComposite(f))
				{
					break;
				}
			}
			if (n > max_n)
			{
				max_n = n;
				max_a = a;
				max_b = b;
			}
		}
	}

	printf("a = %d, b= %d, n은 연속해서 %d개가 소수 입니다.", max_a, max_b, max_n);

	return 0;
}