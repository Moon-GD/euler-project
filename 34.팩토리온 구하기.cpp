#include<stdio.h>
#include<math.h> //factorial
#define MAX 100000

int factorial(int i) // 팩토리얼 함수
{
	if (i == 0)
		return 1;
	if (i < 0)
		return 0;
	return  i * factorial(i - 1);
}

int find(int i) // 각 자리의 팩토리얼의 합이 자기 자신이 되면 1을, 아니면 0을 반환하는 함수
{
	int sum = 0;
	int x = i;

	while (x != 0)
	{
		sum += factorial(x % 10);
		x = x / 10;
	}

	if (i == sum)
		return 1;
	else
		return 0;
}


int main()
{
	int sum = 0;
	for (int i = 10; i <= MAX; i++)
	{
		if (find(i))
			sum += i;
	}

	printf("합은 %d", sum);

	return 0;
}