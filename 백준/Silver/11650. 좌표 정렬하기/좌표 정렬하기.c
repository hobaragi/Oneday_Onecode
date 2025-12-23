#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100000

int N;
int cnt = 0;
int x[MAX], y[MAX];
int tmpX[MAX], tmpY[MAX];

void merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (x[i] < x[j] || (x[i] == x[j] && y[i] <= y[j])) {
			tmpX[k] = x[i];
			tmpY[k] = y[i];
			i++;
		}
		else {
			tmpX[k] = x[j];
			tmpY[k] = y[j];
			j++;
		}
		k++;
	}

	while (i <= mid) {
		tmpX[k] = x[i];
		tmpY[k] = y[i];
		k++;
		i++;
	}

	while (j <= right) {
		tmpX[k] = x[j];
		tmpY[k] = y[j];
		k++;
		j++;
	}

	for (int t = left; t <= right; t++) {
		x[t] = tmpX[t];
		y[t] = tmpY[t];
	}
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
		int a, b;
		scanf("%d %d", &a, &b);
		x[cnt] = a;
		y[cnt] = b;
		cnt++;
	}

	mergeSort(0, cnt - 1);

	for (int i = 0; i < cnt; i++) {
		printf("%d %d\n", x[i], y[i]);
	}

	return 0;
}