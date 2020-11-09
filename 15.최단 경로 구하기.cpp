#include<stdio.h>

double Way(int grid)
{
	int i;
	double way = 1;

	for (i = 2 * grid; 1 <= i; i--)
	{
		if (grid < i) { way *= i; }
		if (i <= grid) { way /= i; }

	}

	return way;
}

int main()
{
	int grid;

	printf("격자의 크기는? :"); scanf_s("%d", &grid);
	printf("%.lf 입니다.", Way(grid));

	return 0;
}
//개선사항 : 
// 1. 순열을 이용할 경우, 팩토리얼 함수가 라이브러리에 구현되있으니, 그것을 사용할 것
// 2. 경우의 수를 이용할 경우, 배열을 사용할 것