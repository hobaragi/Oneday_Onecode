#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int M, N, K;
int map[50][50];
int visited[50][50];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
		if (map[ny][nx] == 0 || visited[ny][nx]) continue;

		dfs(ny, nx);
	}
}

int main()
{
	int T, cnt;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {

		for (int j = 0; j < 50; j++) {
			for (int k = 0; k < 50; k++) {
				map[j][k] = 0;
				visited[j][k] = 0;
				cnt = 0;
			}
		}

		scanf("%d %d %d", &M, &N, &K);

		for (int j = 0; j < K; j++) {
			int x, y;
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (map[j][k] == 1 && !visited[j][k]) {
					dfs(j, k);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}