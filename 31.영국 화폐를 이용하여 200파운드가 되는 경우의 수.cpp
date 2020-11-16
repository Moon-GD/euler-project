#include <stdio.h> 

int coin[8] = { 200, 100, 50, 20, 10, 5, 2, 1 };
int count(int money, int idx);

int main()
{
	printf("%d\n", count(200, 0));
	return 0;
}

int count(int money, int idx)
{
	if (money == 0)
		return 1;
	if (money < 0 || 8 <= idx)
		return 0;
	return count(money - coin[idx], idx) + count(money, idx + 1);
}