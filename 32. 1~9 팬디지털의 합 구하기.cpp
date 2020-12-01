#include<stdio.h>
#include<math.h> // pow, log10
int C[30] = {}; // a * b = c 에서 c값을 저장할 배열선언
int cnt = 0; // C배열의 인덱스

int Overrap(int N) // 팬디지털(pandigital) 판별 함수
{
	int ciper = (int) log10(N) + 1;
	int num[10] = {};
	int i = 0;
	while (N > 0)
	{
		num[i++] = N % 10;
		N /= 10;
	}

	for (int i = 0; i < ciper; i++) //각 숫자가 하나씩 쓰였는지 판별
	{
		if (num[i] == 0) // 0이 포함되면 제외
			return 0;
		for (int j = i + 1; j < ciper; j++)
		{
			if (num[i] == num[j]) // 중복되는 수가 있으면 제외
				return 0;
		}
	}

	return 1;
}

int Double(int c) // 중복 판별 함수
{
	for (int k = 0; k < cnt; k++)
	{
		if (C[k] == c)
		{
			C[k] = 0;
			cnt--;
			return 0; // 이전의 c의 값과 중복되면 0을 반환
		}
	}
	return 1;
}

int main()
{
	int a, b, c, sum = 0;
	int max_b, min_b;
	for (a = 1; a <= 99; a++)
	{
		if (a < 10)
		{
			min_b = 1000;
			max_b = 9999;
		}
		else
		{
			min_b = 100;
			max_b = 999;
		}
		for (b = min_b; b <= max_b; b++)
		{
			c = a * b;
			if (c > 10000) // 1~9 팬디지털에서 c는 다섯자리의 수가 되는 것이 불가능
				continue;
			int N = 0; // N = a|b|c을 의미. 즉, a=1 b=23 c=456 일 때, N = 123456
			if (a < 10)
				N = a * (int) pow(10, 8) + b * (int) pow(10, 4) + c;
			else
				N = a * (int) pow(10, 7) + b * (int) pow(10, 4) + c;

			if (Overrap(N))
			{
				cnt++;
				C[cnt] = c;
				if (Double(c))
				{
					//출력 결과가 궁금하시면 아래 주석을 해제하세요.
					// printf("%4d * %4d= %4d, N = %10d\n", a, b, c, N);
					sum += c;
				}
			}

		}
	}

	printf("정답은 %d", sum);

	return 0;
}