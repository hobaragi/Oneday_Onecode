#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 100000

int age[MAX];
int tmp[MAX];
char name[MAX][101];
char nameTmp[MAX][101];

void merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (age[i] > age[j]) {
			tmp[k] = age[j];
			strcpy(nameTmp[k], name[j]);
			k++; j++;
		}
		else {
			tmp[k] = age[i];
			strcpy(nameTmp[k], name[i]);
			k++; i++;
		}
	}

	while (i <= mid) {
		tmp[k] = age[i];
		strcpy(nameTmp[k], name[i]);
		k++; i++;
	}

	while (j <= right) {
		tmp[k] = age[j];
		strcpy(nameTmp[k], name[j]);
		k++; j++;
	}

	for (int t = left; t <= right; t++) {
		age[t] = tmp[t];
		strcpy(name[t], nameTmp[t]);
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
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %s", &age[i], &name[i]);
	}

	mergeSort(0, N - 1);

	for (int i = 0; i < N; i++) {
		printf("%d %s\n", age[i], name[i]);
	}

	return 0;
}