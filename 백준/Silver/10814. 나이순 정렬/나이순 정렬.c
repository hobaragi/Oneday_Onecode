#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int age[100000];
int tmp[100000];
char name[100000][101];
char nameTmp[100000][101];
int N;

void merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (age[i] > age[j]) {
			tmp[k] = age[j];
			strcpy(nameTmp[k], name[j]);
			k++;
			j++;
		}
		else {
			tmp[k] = age[i];
			strcpy(nameTmp[k], name[i]);
			k++;
			i++;
		}
	}

	while (i <= mid) {
		tmp[k] = age[i];
		strcpy(nameTmp[k], name[i]);
		k++;
		i++;
	}

	while (j <= right) {
		tmp[k] = age[j];
		strcpy(nameTmp[k], name[j]);
		k++;
		j++;
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
	scanf("%d", &N);

	for (int i = 0; i < N;i++)
		scanf("%d %100s", &age[i], name[i]);

	mergeSort(0, N - 1);

	for (int i = 0; i < N; i++)
		printf("%d %s\n", age[i], name[i]);

	return 0;
}