#include<stdio.h>
int rightAngle[1000 + 1] = { 0 };

int main()
{
	int a, b, c; // 삼각형의 각 변
	for (a = 1; a <= 998; a++)
	{
		for (b = a; b <= 998; b++)
		{
			for (c = b; c <= 998; c++)
			{
				if (a + b + c > 1000) // 둘레가 1000 이상일 경우는 제외
					continue;
				if (c * c == a * a + b * b) // 피타고라스의 정리를 만족시키면 해당 둘레의 배열에 +1 해준다
				{
					rightAngle[a + b + c]++;
				}
			}
		}
	}
	int max = 0, max_circumference = 0;
	// max = 직각삼각형의 최대 개수, max_circumference = 직각삼각형의 개수를 최대로 가지는 둘레의 길이

	for (int i = 1; i < 1000; i++)
	{
		if (rightAngle[i] > max)
		{
			max = rightAngle[i];
			max_circumference = i;
		}
	}

	printf("답은 : %d", max_circumference);

	return 0;
}