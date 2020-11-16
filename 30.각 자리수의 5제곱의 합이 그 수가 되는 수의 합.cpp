#include<stdio.h>
#include<math.h> // pow
#define max 354294

int square(int num)
{
	int i, temp = 0;
	int result = 0;
	int x = num;
	for (i = 6; 0 <= i; i--)
	{
		temp = x / (int)pow(10, i);
		result += (int)pow(temp, 5);
		x -= (temp * (int)pow(10, i));
	}
	if (result == num)
		return 1;
	else
		return 0;
}


int main()
{
	int num, sum = 0;

	for (num = 10; num <= max; num++)
	{
		if (square(num))
			sum += num;
	}

	printf("%d", sum);
	return 0;
}