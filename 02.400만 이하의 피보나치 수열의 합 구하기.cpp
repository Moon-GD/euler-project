#include<stdio.h>

int main()
{
	int a = 1, b = 2, c = 3;
	int s = 2;

	while (c <= 4000000)
	{
		if (c % 2 == 0)
		{
			s += c;
		}
		a = b;
		b = c;
		c = a + b;
	}

	printf("sum = %d", s);

	return 0;
}