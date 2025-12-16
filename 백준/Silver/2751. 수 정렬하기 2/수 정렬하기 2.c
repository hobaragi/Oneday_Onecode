#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000000

int num[MAX];
int temp[MAX];
int N;

void merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (num[i] >= num[j])
			temp[k++] = num[j++];
		else
			temp[k++] = num[i++];
	}

	while (i <= mid)
		temp[k++] = num[i++];

	while (j <= right)
		temp[k++] = num[j++];

	for (int t = left; t <= right; t++)
		num[t] = temp[t];
}

void mergeSort(int left, int right) {
	if (left >= right) return;

	int mid = (left + right) / 2;

	mergeSort(left, mid);
	mergeSort(mid + 1, right);
	merge(left, mid, right);
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	mergeSort(0, N - 1);

	for (int i = 0; i < N; i++) {
		printf("%d\n", num[i]);
	}

	return 0;
}