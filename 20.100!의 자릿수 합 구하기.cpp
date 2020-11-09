#include<stdio.h>
#include<string.h>
char num[300] = "1";
int temp[300] = { 1 };

int main()
{
	int i, j, flag = 0; // flag 는 이전 자릿 수가 다음 자릿 수에 영향을 주는 경우 해당 변화량만큼 다음 자릿 수에 더해 준다.
	int sum = 0; // 각 자릿 수의 합을 저장할 변수

	for (i = 2; i <= 100; i++) // 팩토리얼 계산
	{
		for (j = 0; j < 300; j++)
		{
			if ('0' <= num[j] && num[j] <= '9')
			{
				temp[j] = (num[j] - '0') * i + flag;
			}
			else { break; }

			num[j] = (temp[j] % 10) % 10 + '0';
			flag = 0;

			if (temp[j] >= 10)
			{
				if ('9' < num[j + 1] || num[j + 1] < '0')
				{
					num[j + 1] = '0';
				}
				flag = temp[j] / 10;
			}
		}
	}
	for (i = 0; i < 300; i++) // 구해진 수의 각 자리 합 구하기
	{
		if ('0' <= num[i] && num[i] <= '9')
		{
			sum += num[i] - '0';
		}
		else { break; }
	}
	printf("sum = %d\n", sum);

	return 0;
}
/* 100!의 값이 너무 크다보니 메모리 초과를 걱정하며 문자형 배열로 문제를 해결하였다.
하지만, 정수형 배열로도 "끊어주기만 잘한다면" 풀어줄 수 있음을 알게 되었다.
#include <stdio.h>
#include <math.h>

int main()
{
	int x[40] = { 1,0 }, check = pow(10, 5), sum = 0;
	int factorial = 100;

	for (int i = 1; i <= factorial; i++)
		for (int j = 38; j >= 0; j--)
		{
			x[j] *= i;
			if (x[j] > check)
			{
				x[j + 1] += (int)(x[j] / check);
				x[j] %= check;
			}
		}

	for (int i = 0; i < 40; i++)
		while (1)
		{
			sum += x[i] % 10;
			x[i] = (int)(x[i] / 10);
			if (x[i] == 0)
				break;
		}

	printf("%d", sum);

	return 0;
}
*/