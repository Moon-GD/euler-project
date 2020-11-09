#include<stdio.h>
#define grid 20
#include<stdlib.h>
int main()
{
	char arr[grid + 1][grid * 2 +1] = {
"0802229738150040007504050778521250779108",
"4949994017811857608717409843694804566200",
"8149317355791429937140675388300349133665",
"5270952304601142692468560132567137023691",
"2231167151676389419236542240402866331380",
"2447326099034502447533537836842035171250",
"3298812864236710263840675954706618386470",
"6726206802621220956394396308409166499421",
"2455580566739926971778789683148834896372",
"2136230975007644204535140061339734313395",
"7817532822753167159403800462161409535692",
"1639054296353147555888240017542436298557",
"8656004835718907054444374460215851541758",
"1980816805944769287392138652177704895540",
"0452088397359916079757321626267933279866",
"8836688757622072034633674655123263935369",
"0442167338253911249472180846293240627636",
"2069364172302388346299698267598574043616",
"2073352978319001743149714886811623570554",
"0170547183515469169233486143520189196748"
	};
	int num[grid * grid+ 2];
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 40; j+=2)
		{
			num[1+20*i+j/2] = (arr[i][j] - '0') * 10 + (arr[i][j + 1]-'0');
		}
	}
	int row_product=1, column_product=1, cross_product=1;
	int row_max = 0, flag=0;

	for (i = 1; i < grid * grid + 1; i++) // 가로 최댓값 구하기
	{
		row_product *= num[i];
		flag++;
		if (flag % 4 == 0)
		{
			if (row_max < row_product) { row_max = row_product; }
			row_product = 1;
		}
	}

	int column_max = 0;
	for (j = 1; j <= 5; j++)
	{
		for (i = 1; i <= 20; i++)
		{
			column_product = num[80 * j + i] * num[80 * j + i + 10] * num[80 * j + i + 20] * num[80 * j + i + 30];
			if (column_max < column_product) { column_max = column_product; }
		}
	}
	int cross_max = 0;
	for (j = 0; j < 5; j++)
	{
		for (i = 1; i <= 17; i++)
		{
			cross_product = num[80 * j + i] * num[80 * j + i + 21] * num[80 * j + i + 42] * num[80 * j + i + 63];
			if (cross_max < cross_product) { cross_max = cross_product; }
		}
	}
	int cross_max2 = 0;
	for (j = 0; j < 5; j++)
	{
		for (i = 1; i <= 17; i++)
		{
			cross_product = num[80 * j + i+3] * num[80 * j + i + 22] * num[80 * j + i + 41] * num[80 * j + i + 60];
			if (cross_max2 < cross_product) { cross_max2 = cross_product; }
		}
	}
	printf("%d %d %d %d", row_max, column_max, cross_max, cross_max2);

	return 0;
}
/*
개선 사항 : 주어진 격자에 띄어쓰기가 되어있었으니 atoi 함수로 입력받으면 한결 편했을 것이다.
*/