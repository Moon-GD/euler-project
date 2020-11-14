#include<stdio.h>
#include<math.h> // pow
#include<stdbool.h> // bool
bool num[700] = { false };
int main() // 2^60 = 4^30 = 8^20 = … 이런 식으로 중복이 있는 수를 제외하고 세어주면 된다.
{
    int a = 2, x; // a : 밑,  x : 지수 변수
    int cnt = 81 * 99; 
    /* cnt : 주어진 범위 내에서 중복이 없는 수들의 개수를 더해주고 시작
    즉, a가 (2,4,8,16,32,64, 3,9,27, 5,25, 6,36, 7,49, 10,100) 인 경우를 제외한 모든 경우 */
    while (a <= 10) // a가 11보다 커지면 중복되는 경우는 없으니 고려하지 않는다.
    {
        x = 1;
        if (a == 4 || a == 8 || a == 9) // 각각 a=2, a=3 인 경우에서 개수가 세어졌기 때문에 제외한다.
        {
            a++; continue;
        }
        while (pow(a, x) <= 100) { x++; }
        x--; // 한 번 더 더해지기 때문에 1만큼 빼준다.
        int i, j; // 제어문 변수
        for (i = 1; i <= x; i++)
        {
            for (j = 2 * i; j <= i * 100; j += i)
            {
                num[j] = true;
            }
        }
        
        for (i = 1; i <= x * 100; i++)
        {
            if (num[i] == true)
                cnt++;
            num[i] = false; // 배열 초기화
        }
        a++;
    }
    printf("총 개수 : %d", cnt);
}