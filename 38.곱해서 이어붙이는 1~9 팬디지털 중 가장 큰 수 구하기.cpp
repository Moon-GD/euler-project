#include<stdio.h>
#include<math.h> // log10, pow
#define MAX 1000000000 // 10자리 수
int isPandigital(long long sum) // 1~9 팬디지털 여부
{
	int ciper = (int)log10((double)sum) + 1;

	if (ciper != 9)
		return 0;

	int array[9] = { 0 }; // 초기화
	for (int i = 0; i < 9; i++) // 배열에 대입
	{
		array[i] = sum % 10;
		sum = (long long)(sum / 10);
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (array[i] == array[j])
				return 0;
			if (array[i] == 0)
				return 0;
		}
	}

	return 1;
}

int main()
{
	long long max = 0;

	for (int i = 1; i <= 9999; i++) // i가 다섯 자리 이상일 경우에, 곱해서 이어붙이면 1~9팬디지털이 될 수가 없다.
	{
		long long sum = 0;
		for (int j = 1; sum < MAX && j <= 9; j++)
		{
			if (isPandigital(sum))
			{
				break;
			}
			int temp = i * j;
			int sum_ciper = (int)log10(temp) + 1;
			sum = sum * (int)pow(10, (double)sum_ciper) + temp; // 곱해서 이어붙이기
		}
		if (isPandigital(sum)) // 팬 디지털 수일 때,
		{
			if (sum > max) // 이전의 최댓값보다 크다면 최댓값 갱신
			{
				max = sum;
			}
		}
	}
	printf("답은 : %lld", max);

	return 0;
}