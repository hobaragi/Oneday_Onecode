#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

int M, N, K;
int map[MAX][MAX];
int visited[MAX][MAX];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dfs(int y, int x) {
	int cnt = 1;

	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (map[ny][nx] == 1 || visited[ny][nx]) continue;

		cnt += dfs(ny, nx);
	}

	return cnt;
}

void sort(int Count[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (Count[i] > Count[j]) {
				int temp = Count[i];
				Count[i] = Count[j];
				Count[j] = temp;
			}
		}
	}
}

int main()
{
	// M=y, N=x
	scanf("%d %d %d", &M, &N, &K);

	// 초기화
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < K; i++) {
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				map[y][x] = 1;
			}
		}
	}

	int Count[MAX * MAX];
	int cnt = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && !visited[i][j]) {
				int a = dfs(i, j);
				Count[cnt++] = a;
			}
		}
	}

	sort(Count, cnt);

	printf("%d\n", cnt);

	for (int i = 0; i < cnt; i++) {
		printf("%d ", Count[i]);
	}

	return 0;
}