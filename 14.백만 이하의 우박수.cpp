#include<stdio.h>

int main()
{
	unsigned int i, temp, cnt = 0, max_i = 0, max = 0;

	for (i = 2; i <= 1000000; i++)
	{
		temp = i, cnt = 0;
		while (1)
		{
			if (temp % 2 == 0)
			{
				temp /= 2;
				cnt++;
			}
			if (temp % 2 == 1 && temp != 1)
			{
				temp = 3 * temp + 1;
				cnt++;
			}

			if (temp == 1) { break; }
		}
		printf("%d   %d\n", i, cnt);

		if (cnt > max)
		{
			max = cnt;
			max_i = i;
		}
	}
	return 0;
}