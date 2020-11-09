#include<stdio.h>

int factorial(int n) //팩토리얼
{
	int product = 1;
	while (n)
		product *= n--;

	return product;
}

void change_position(char* num, int q)
{
	int i;
	char temp = '0';

	for (i = q; i + 1 < 10; i++)
	{
		temp = num[i];
		num[i] = num[i + 1];
		num[i + 1] = temp;
	}
}

int main()
{
	char num[10 + 1] = "0123456789";
	int target = 1000000 - 1; // 변환 전 선언된 배열 자체가 첫번째 순열이므로 구하려는 순서에서 1을 빼준다.
	int size = 9; // 자릿수
	int q; // quotient(몫)
	while (size)
	{
		q = target / factorial(size);
		target %= factorial(size);
		if (q == 0)
			change_position(num, 0);
		else
			change_position(num, q);
		size--;
		if (size == 0)
			change_position(num, 0);
	}
	for (int i = 0; i < 10; i++)
		printf("%c", num[i]);
	return 0;
}