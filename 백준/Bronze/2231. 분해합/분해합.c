#include <stdio.h>

int main()
{
    int N;
    scanf("%d",&N);
    for (int a1=0; a1<10; a1++) {
        for (int a2=0; a2<10; a2++) {
            for (int a3=0; a3<10; a3++) {
                for (int a4=0; a4<10; a4++) {
                    for (int a5=0; a5<10; a5++) {
                        for (int a6=0; a6<10; a6++) {
                            int sum;
                            sum = (a1*100000) + (a2*10000) + (a3*1000) + (a4*100) + (a5*10) + (a6*2) +a1+a2+a3+a4+a5;
                            if (N==sum) {
                                printf("%d",(a1*100000) + (a2*10000) + (a3*1000) + (a4*100) + (a5*10) + a6);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    
    printf("0");
    
    return 0;
}