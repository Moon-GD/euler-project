#include<stdio.h>
// 가장 큰 대칭수를 찾는 문제이니 6자리 수인 경우만을 고려
int main()
{
	int a, b, c, n; // 대칭수를 만들어 주기 위한 변수들 (n = abccba)
	int i;
	for (a = 9; 0 <= a; a--)
	{
		for (b = 9; 0 <= b; b--)
		{
			for (c = 9; 0 <= c; c--)
			{
				n = a * 100001 + b * 10010 + c * 1100; // n을 대칭수로 만들어 줌.
				for (i = 999; 100 <= i; i--)
				{
					if (n % i == 0)
					{
						if (100 <= n / i && n / i <= 999) // n이 세자리 수로 나누어지고, 몫도 세자리 수일 경우 EXIT를 통하여 루프 탈출
						{
							printf("%d = %d * %d\n", n, i, n / i);
							goto EXIT;
						}
					}
				}
			}
		}
	}
	EXIT:
	return 0;
}