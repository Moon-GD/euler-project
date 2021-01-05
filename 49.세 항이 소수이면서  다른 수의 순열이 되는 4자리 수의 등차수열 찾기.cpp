#include<stdio.h>
#include<math.h> // sqrt
int array[11] = { 0,1,2,3,4,5,6,7,8,9 };
int target[600] = { 0 };

int isPrime(int i) {
	for (int j = 2; j <= sqrt(i); j++) {
		if (i % j == 0) {
			return 0;
		}
	}
	return 1;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b, *b = temp;
	return;
}

void Permutation(int n, int r, int depth)
{
	int sum = array[0] * 1000 + array[1] * 100 + array[2] * 10 + array[3];
	if (r == depth) {
		if (isPrime(sum)) {
			if (sum < 1000)
				return;
			int i = 0;
			while (1) {
				if (target[i] == 0) {
					target[i] = sum;
					break;
				}
				else {
					i++;
				}
			}
		}
		return;
	}

	for (int i = depth; i < n; i++) {
		swap(&array[i], &array[depth]);
		Permutation(n, r, depth + 1);
		swap(&array[i], &array[depth]);
	}
}

int main()
{
	Permutation(10, 4, 0);
	
	/* 출력하기
	for (int i = 0; i<510; i++) {
		printf("%d %d개\n", target[i], i+1);
	}
	*/

	for (int a = 0; a <= 507; a++) {
		for (int c = a + 2; c <= 509; c++) {
			for (int b = a + 1; b <= 508; b++) {
				//세 수의 대소 비교
				int max = 0, min = 0;
				if (target[a] > target[b]) {
					max = target[a];
					min = target[b];
				}
				else { 
					max = target[b];
					min = target[a];
				}
				if (target[c] > max) { max = target[c]; }
				if (target[c] < min) { min = target[c]; }

				if (target[a] + target[b] + target[c] == 3 / 2 * (max + min)) {
					printf("%d %d %d\n", min, (max + min) / 2, max);
				}
			}
		}
	}

	return 0;
}