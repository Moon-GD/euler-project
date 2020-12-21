#include<stdio.h>
#include<math.h>

int isPentagon(int i) {
	for (int j = 1; j < i; j++)
	{
		if (j * (3 * j - 1) / 2 == i)
			return 1;
	}
	return 0;
}

int main()
{
	int K, X, Y;
	for (K = 5;; K += 6)
	{
		for (X = 5; X < K; X += 6)
		{
			for (Y = X + 6; X * X + Y * Y <= 2 * K * K; Y += 6)
			{
				if (X * X + Y * Y == 2 * K * K)
				{
					int J = (int)sqrt(1.0 * K * K - 1.0 * X * X + 1);
					if (isPentagon((K * K - X * X) / 24))
					{
						printf("%d\n", (X * X - 1) / 24);
						return 0;
					}
				}
			}
		}
	}
	return 0;
}