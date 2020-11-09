#include<stdio.h>

int main()
{
	int i = 1;
	int j, k, num = 0, count = 0;

	while (1)
	{
		num = 0, count = 0, i++;
		for (j = 1; j <= i; j++)
		{
			num += j;
		}

		for (k = 1; k * k <= num; k++)
		{
			if (num % k == 0)
			{
				count++;
				if (k * k < num) { count++; }
				if (count >= 500)
				{
					printf("약수가 500개 이상인 삼각수 = %d", num);
					goto EXIT;
				}
			}
		}
	}
EXIT:
	return 0;
}
/* 배수를 활용하여 약수 개수를 구하는 방법.. 지림
for (int i = 1; i <= 10000000; i++) {
	for (int j = 1; j <= 10000000 / i; j++) {
		count[i * j]++;
	}
}
*/