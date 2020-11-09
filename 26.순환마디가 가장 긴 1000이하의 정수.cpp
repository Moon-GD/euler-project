#include<stdio.h>
#include<math.h>
#define max 9999999999999999 // 9가 16개
long long nine[10] = { 0 };

int divide(int i) // 소인수 중 2와 5의 배수를 모두 제거
{
	while (i % 5 == 0)
		i /= 5;
	while (i % 2 == 0)
		i /= 2;
	return i;
}

int main()
{
	int i;
	int goal_i = 0, goal = 0;
	for (i = 1; i <= 1000; i++)
	{
		int j = 0, cnt = 1;
		nine[j] = { 0 };
		while (1)
		{
			nine[j] = nine[j] * 10 + 9;

			while (j != 0)
			{
				int temp = nine[j] % i;
				j--;
				nine[j] += temp;
			}

			if (nine[j] % divide(i) == 0)
			{
				if (goal < cnt)
				{
					goal = cnt;
					goal_i = i;
				}
				break;
			}
			else
				cnt++;
			if (nine[j] >= max)
				nine[++j] = 0;
		}
		printf("%d %d\n", i, cnt); // 각 숫자별 순환마디 개수 출력
	}

	printf("%d일때 %d", goal_i, goal); // 정답 도출

	return 0;
}