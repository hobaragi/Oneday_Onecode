#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

int map[MAX][MAX];
int visited[MAX][MAX];
int Count[MAX];
int N, rain, max = 0;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dfs(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (map[ny][nx] <= rain || visited[ny][nx]) continue;

		dfs(ny, nx);
	}

	return 1;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (rain = 0; rain < 101; rain++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > rain && !visited[i][j]) {
					Count[rain] += dfs(i, j);
				}
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		if (max < Count[i]) max = Count[i];
	}

	printf("%d\n", max);

	return 0;
}