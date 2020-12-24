#include<stdio.h>
#include<math.h> // sqrt

int isPrime(int i) // 소수 판별 함수. 소수는 1, 합성수는 0을 반환
{
	for (int j = 2; j <= sqrt(i); j++)
	{
		if (i % j == 0)
			return 0;
	}
	return 1;
}

int main()
{
	for (int i = 9;; i += 2)
	{
		int flag = 1;
		if (isPrime(i) == 0)
		{
			for (int j = 3; j < i; j++)
			{
				if (isPrime(j))
				{
					int temp = (i - j);
					//temp = 합성수 - 소수
					for (int k = 1; k * k * 2 <= temp; k++) { // 합성수 - 소수가 2 X 제곱수로 표현되는지 확인
						//표현되면 flag = 0 대입하고 반복문 중단
						if (k * k * 2 == temp) {
							flag = 0;
							break;
						}
					}
				}
				if (flag == 0) // flag == 0, 즉, 골드바흐의 추측대로 표현이 되면 반복문 중단
					break;
			}
			if (flag == 1) { // 골드바흐의 추측에 어긋난 합성수 i가 등장했을 경우 i를 출력하고 main 함수 종료
				printf("정답은 : %d", i);
				return 0;
			}
		}
	}
}