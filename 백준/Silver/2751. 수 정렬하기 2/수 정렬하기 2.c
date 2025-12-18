#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000000

int arr[MAX];
int tmp[MAX];
int N;

void merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (arr[i] > arr[j])
			tmp[k++] = arr[j++];
		else
			tmp[k++] = arr[i++];
	}

	while (i <= mid)
		tmp[k++] = arr[i++];

	while (j <= right)
		tmp[k++] = arr[j++];

	for (int t = left; t <= right; t++)
		arr[t] = tmp[t];
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

	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	mergeSort(0, N - 1);

	for (int i = 0; i < N; i++) printf("%d\n", arr[i]);

	return 0;
}
