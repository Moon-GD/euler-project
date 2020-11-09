#include<stdio.h>
#include<math.h>

int main()
{
	int a=1, b=1, c=1; // a, b, c 값 초기화
	
	for (c = 3; b < c; c++)
	{
		for (b = 2; b < c; b++)
		{
			for (a = 1; a < b; a++)
			{
					if (pow(a, 2) + pow(b, 2)==pow(c,2))
					{
						if (a + b + c == 1000)
						{
							printf("%d * %d * %d = %d",a,b,c,a*b*c);
							goto EXIT;
						}
					}
			}
		}
	}
EXIT:
	return 0;
}