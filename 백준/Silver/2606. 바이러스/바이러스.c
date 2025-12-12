#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int N, M, cnt = 0;

void dfs(int n) {
	visited[n] = 1;

	for (int i = 1; i <= N; i++) {
		if (graph[n][i] == 1 && visited[i] != 1) {
			cnt++;
			dfs(i);
		}
	}
}

int main()
{
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	dfs(1);

	printf("%d\n", cnt);

	return 0;
}