#include<stdio.h>
#include<math.h>

int main()
{
	double i, sum = 0, sum2 = 0;

	for (i = 1; i <= 100; i++)
	{
		sum += pow(i,2);
		sum2 += i;
	}
	printf("제곱의 합은 : %.lf, 합의 제곱은 %.lf\n", sum, pow(sum2,2));
	printf("둘의 차이는 %.lf 입니다.", pow(sum2,2) - sum);

	return 0;
}