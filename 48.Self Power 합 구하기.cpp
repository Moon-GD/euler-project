#include<stdio.h>
#define MAX 10000000000


int main()
{
	long long i, sum = 0, temp = 1;
	for (i = 1; i <= 1000; i++)
	{
		temp = 1;
		for (int j = 1; j <= i; j++)
		{
			if (temp > MAX) {
				temp = temp % MAX;
			}
			temp *= i;
		}
		sum += temp;
		if (sum > MAX) {
			sum = sum % MAX;
		}
	}
	printf("%lld", sum);
	return 0;
}