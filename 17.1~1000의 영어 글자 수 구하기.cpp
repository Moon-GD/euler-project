#include<stdio.h>
#include<string.h>

int main()
{
	char num[10][10] = { "","one", "two", "three", "four", "five", "six", "seven","eight","nine" };
	char tenth[10][10] = { "ten", "eleven", "twelve", "thirteen", "fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
	char tenth2[10][10] = { "twenty","thirty","forty", "fifty","sixty", "seventy","eighty", "ninety" };
	char hundred[15] = "hundred";

	int i, cnt = 0;

	for (i = 1; i <= 1000; i++)
	{
		if (i < 100)
		{
			if (i < 10)
			{
				printf("%s\n", num[i]);
				cnt += strlen(num[i]);
			}
			else if (10 <= i && i <= 19)
			{
				printf("%s\n", tenth[i % 10]);
				cnt += strlen(tenth[i % 10]);
			}
			else
			{
				printf("%s %s\n", tenth2[i / 10 - 2], num[i % 10]);
				cnt += strlen(tenth2[i / 10 - 2]);
				cnt += strlen(num[i % 10]);
			}
		}

		if (i >= 100 && i != 1000)
		{
			printf("%s %s ", num[i / 100], hundred);
			cnt += strlen(num[i / 100]);
			cnt += 7;
			if (i % 100 != 0)
			{
				printf("and ");
				cnt += 3;
			}
			if (i % 100 < 10)
			{
				printf("%s\n", num[i % 100]);
				cnt += strlen(num[i % 100]);
			}
			else if (10 <= i % 100 && i % 100 <= 19)
			{
				printf("%s\n", tenth[i % 10]);
				cnt += strlen(tenth[i % 10]);
			}
			else
			{
				printf("%s %s\n", tenth2[(i % 100) / 10 - 2], num[i % 10]);
				cnt += strlen(tenth2[(i % 100) / 10 - 2]);
				cnt += strlen(num[i % 10]);
			}
		}
		if (i == 1000)
		{
			printf("one thousand\n");
			cnt += 11;
		}
	}

	printf("사용된 문자 수 : %d", cnt);

	return 0;
}