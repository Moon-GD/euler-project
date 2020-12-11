#include<stdio.h>
#include<math.h> // log10
#include<string.h> // sprintf

int find(int i, int gap) // 타깃 지점을 넘어섰을 때 타깃에서의 수가 무엇인지 구해주는 함수
{
	char N[10] = { 0 }; // 양의 정수 i를 문자열로 변환하여 저장할 배열
	int length = (int)log10(i); // i를 배열에 저장했을 때의 길이
	sprintf_s(N, "%d", i); // 문자열로 변환
	return N[length - gap] - '0';
}

int main()
{
	int target[7] = { 1,10,100,1000,10000,100000,1000000 };

	int goal = 1, cnt = 0;
	// goal = 답, cnt = 소수점의 길이
	int i = 1, j = 0;
	// i = 양의 정수, j = target 배열의 지표
	while (j < 7)
	{
		int ciper = (int)log10(i) + 1; // 정수 i의 자릿수
		cnt += ciper; // 소수점 길이 추가
		if (cnt >= target[j])
		{
			goal *= find(i, cnt - target[j++]); // j++로 target 갱신 (1->10->100-> ...->1,000,000)
		}
		i++;
	}

	printf("답은 %d", goal);

	return 0;
}