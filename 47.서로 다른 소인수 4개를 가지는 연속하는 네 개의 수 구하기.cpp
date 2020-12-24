#include <stdio.h>

#define MAX 1000000
int num[MAX] = { 0 };

int main()
{
	for (int i = 2; i <= MAX; i++) {
		if (num[i] == 0) { // i==0, 즉, i가 소수이면 i의 배수가 되는 항목들에 1씩 더해준다.
			//예를 들어 i가 3이면 i = 3 , 6, 9, 12, 15, ... 일 때 1씩 더해준다.
			for (int j = i; j <= MAX; j += i) {
				num[j]++;
			}
		}
	}

	for (int i = 2; i <= MAX; i++) { // i가 연속해서 네 개의 소인수를 가질 때 출력하고 main 함수 종료
		if (num[i] == 4) {
			if (num[i + 1] == 4) {
				if (num[i + 2] == 4) {
					if (num[i + 3] == 4) {
						printf("%d", i);
						return 0;
					}
					else { i += 3; }
				}
				else { i += 2; }
			}
			else { i++; }
		}
	}
}