#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    int count = 0;
    int num = 666;

    while (1) {
        int temp = num;
        int has666 = 0;

        // num 안에 666이 있는지 확인
        while (temp > 0) {
            if (temp % 1000 == 666) { // 끝 세 자리 확인
                has666 = 1;
                break;
            }
            temp /= 10;
        }

        if (has666) {
            count++;
            if (count == N) {
                printf("%d\n", num);
                break;
            }
        }

        num++;
    }

    return 0;
}
