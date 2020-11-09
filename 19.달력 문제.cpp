#include<stdio.h>

int flag(int year) // 윤달 판별 함수
{
	int index = 0;
	if (year % 4 == 0)
	{
		index = 1;
		if (year % 100 == 0)
		{
			index = 0;
			if (year % 400)
			{
				index = 1;
			}
		}
	}
	return index;
}

int main()
{
	int This_year = 1900, This_month = 1;
	int year, month;
	int day[2][12] = { { 31,28,31,30,31,30,31,31,30,31,30,31 }, { 31,29,31,30,31,30,31,31,30,31,30,31 } };
	int sum = 334; //1900년 11월 31일까지 일 수
	int index = 0;
	int cnt = 0;

	for (year = 1901; year <= 2000; year++)
	{
		index = flag(year);
		for (month = 0; month < 12; month++)
		{
			if (month == 0) { sum += day[flag(year - 1)][11]; }
			else { sum += day[index][month - 1]; }

			if (sum % 7 == 6) { cnt++; } // 1900년 1월 1일이 월요일이므로 sum % 7 이 6일 때 해당 월 1일이 일요일이 된다. 
		}
	}
	printf("cnt = %d", cnt);
	return 0;
}