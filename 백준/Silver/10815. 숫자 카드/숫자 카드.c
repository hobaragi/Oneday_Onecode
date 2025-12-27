#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int binary_search(int* arr, int n, int target) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == target) return 1;
        if (arr[m] < target) l = m + 1;
        else r = m - 1;
    }
    return 0;
}

int main(void) {
    int N, M;
    scanf("%d", &N);

    int* cards = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) scanf("%d", &cards[i]);

    qsort(cards, N, sizeof(int), cmp_int);

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        printf("%d", binary_search(cards, N, x));
        if (i != M - 1) printf(" ");
    }
    printf("\n");

    free(cards);
    return 0;
}