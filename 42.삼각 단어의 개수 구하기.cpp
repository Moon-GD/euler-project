// 42.txt 파일 맨 마지막 YOUTH 뒤에 " " 공백 한 칸 입력되어 있음을 명심할 것

#define _CRT_SECURE_NO_WARNINGS //fopen 경고 방지
#include<stdio.h>
#include<string.h> // strcmp
char buffer[1000000]; // 파일을 읽어올 배열
char word[2000][20]; // 단어를 저장할 배열
int num_value[2000]; // 단어값을 저장할 배열
int main()
{
	FILE* fp = fopen("42.txt", "r");// 파일 읽기 모드
	fgets(buffer, sizeof(buffer), fp); // 파일 내용 buffer 배열에 저장
	char* p = buffer; // p : buffer 에서 움직일 포인터

	int spell = 0, cnt = 0;
	// spell, cnt = word 배열의 지표

	int temp = 0, goal = 0;
	// temp = 단어값 저장을 위한 변수, goal = 답

	while (strcmp(word[cnt], "YOUTH") != 0)
	{
		cnt++;
		temp = 0, spell = 0;
		while (1)
		{
			if (*p == ' ') // 공백 만나면 cnt 지표 1 증가, 즉, 다음 단어 입력 받을 준비
			{
				p++;
				break;
			}
			temp += (*p - 'A' + 1);
			word[cnt][spell++] = *p++; // word 배열에 글자 저장
		}
		num_value[cnt] = temp; // num_value 배열에 단어값 저장 ex) A = 1, ABILITY = 78 ...

		int n = 1, sum = 0;
		// n = 삼각수 지표, sum = n번째 삼각수의 값

		while (num_value[cnt] >= sum) // 삼각수 일치 여부
		{
			if (num_value[cnt] == sum)
			{
				goal++;
				break;
			}
			sum += n++;
		}

		//각 단어의 값을 보고 싶다면, 아래의 주석을 해제
		//printf("%s = %d\n", word[cnt], num_value[cnt]);
	}
	printf("답은 : %d", goal);

	fclose(fp); // 파일 닫기

	return 0;
}