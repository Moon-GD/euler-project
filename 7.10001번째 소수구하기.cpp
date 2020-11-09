#include<stdio.h>

int main()
{
	int i=2, j, prime, cnt = 0; // 3부터 소수를 찾기 시작하니 2가 제외된다. 즉, 10,000번째 소수를 찾으면 되는 것이다.
	while (1)
	{
		i++, j = 2;
		while (i > j)
		{
			if (i % j == 0)
			{
				break;
			}
			if (j == i - 1)
			{
				prime = i;
				cnt++;
				if (cnt == 10000) // 
				{
					goto exit;
				}
			}
			j++;
		}
	}
exit:
	printf("%d번째 소수는 %d입니다.", cnt+1, prime);
	return 0;
}