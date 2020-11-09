#include<stdio.h>
#include<string.h>
char num[1000] = "1";

int main()
{
	int i = 0, cnt, temp = 0;
	int flag = 0;
	int n;
	printf("몇 번 시행할까요? :"); scanf_s("%d", &n);

	for (cnt = 1; cnt <= n; cnt++)
	{
		i = 0;
		while ('0' <= num[i] && num[i] <= '9')
		{
			if (flag == 0) // 이전 자릿 수에서 영향을 주지 않았다. (ex) 4-> 8 )	
			{
				temp = (num[i] - '0') * 2;
			}
			if (flag == 1) // 이전 자릿 수에서 영향을 주었다.(ex)16->32)
			{
				temp = (num[i] - '0') * 2 + 1;
			}
			if (flag == 2) // 이전 자릿 수에서 영향을 주어 현재의 자릿수가 생겼다.(ex)8->16 or 512->1024)
			{
				temp = num[i] - '0';
			}

			if (temp < 10) // 다음 자릿 수에 영향을 주지 않는다.
			{
				num[i] = '0' + temp;
				flag = 0;
			}
			else // temp >= 10 // 다음 자릿 수에 영향을 준다.
			{
				num[i] = '0' + temp % 10;
				flag = 1;
				if (num[i + 1] < '0' || num[i + 1]>'9') { flag = 2; num[i + 1] = '1'; }
			}
			i++;
		}
	}
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		if (num[i] >= '0' && num[i] <= '9')
			sum += num[i] - '0';
	}
	printf("2^%d = %s\n", n, _strrev(num));
	printf("자릿 수의 합 = %d", sum);

	return 0;
}