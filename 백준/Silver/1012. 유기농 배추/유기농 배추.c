#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 50

int M, N;
int maze[MAX][MAX];
int visited[MAX][MAX];

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

void dfs(int i, int j) {
	visited[i][j] = 1;

	for (int cmmd = 0; cmmd < 4; cmmd++) {
		int ny = i + dy[cmmd];
		int nx = j + dx[cmmd];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (maze[ny][nx] == 0 || visited[ny][nx] == 1) continue;

		dfs(ny, nx);
	}

}

int main()
{
	int T, K, cnt;

	scanf("%d", &T);

	for (int cmd = 0; cmd < T; cmd++) {
		scanf("%d %d %d", &M, &N, &K);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				maze[i][j] = 0;
				visited[i][j] = 0;
			}
		}

		cnt = 0;

		for (int cmd2 = 0; cmd2 < K; cmd2++) {
			int X, Y;
			scanf("%d %d", &X, &Y);
			maze[Y][X] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (maze[i][j] == 1 && !visited[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}