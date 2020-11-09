#include<stdio.h>
//특정 범위의 숫자들로 나누어 떨어지는 수를 찾는 것은 최소공배수를 찾는 것과 같다.
int main()
{
	int i = 1, j, sol;

	while (1)
	{
		for (j = 1; j <= 20; j++)
		{
			if (i % j != 0) // i를 j로 나누어 떨어지지 않으면 i값 증가, j는 1로 다시 초기화
			{
				i++;
				j = 1;
			}
			if (j == 20) // j가 1~20의 범위일 때 i가 모두 나누어 떨어진다면 sol에 대입하고 루프 탈출
			{
				sol = i;
				goto exit;
			}
		}
	}
exit:
	printf("solution = %d", sol);

	return 0;
}