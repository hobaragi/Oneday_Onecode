#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 25

int map[MAX][MAX];
int visited[MAX][MAX] = { 0 };
int Count[MAX];
int N, cnt = 0;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dfs(int y, int x) {
	int num = 1;
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (map[ny][nx] != 1 || visited[ny][nx] == 1) continue;

		num += dfs(ny, nx);
	}

	return num;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				int a = dfs(i, j);
				Count[cnt++] = a;
			}
		}
	}

	for (int i = 0; i < cnt - 1; i++) {
		for (int j = i + 1; j < cnt; j++) {
			if (Count[i] > Count[j]) {
				int temp = Count[i];
				Count[i] = Count[j];
				Count[j] = temp;
			}
		}
	}

	printf("%d\n", cnt);

	for (int i = 0; i < cnt; i++) {
		printf("%d\n", Count[i]);
	}

	return 0;
}