#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 101

int N, M;
int maze[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

typedef struct {
	int x, y;
}Node;

Node queue[MAX * MAX];
int front = 0, rear = 0;

void push(int x, int y) {
	queue[rear].x = x;
	queue[rear].y = y;
	rear++;
}

Node pop() {
	return queue[front++];
}

int isEmpty() {
	return front == rear;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}

	visited[0][0] = 1;
	dist[0][0] = 1;
	push(0, 0);

	while (!isEmpty()) {
		Node cur = pop();
		int x = cur.x;
		int y = cur.y;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (maze[nx][ny] == 0 || visited[nx][ny]) continue;

			visited[nx][ny] = 1;
			dist[nx][ny] = dist[x][y] + 1;
			push(nx, ny);
		}
	}

	printf("%d", dist[N - 1][M - 1]);

	return 0;
}