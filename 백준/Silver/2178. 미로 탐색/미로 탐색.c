#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

int N, M;
int maze[MAX][MAX];
int dist[MAX][MAX];

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

typedef struct {
	int y, x;
}Node;

Node queue[MAX * MAX];
int front = 0, rear = 0;

void push(int y, int x) {
	queue[rear].y = y;
	queue[rear].x = x;
	rear++;
}

Node pop() {
	return queue[front++];
}

int isEmpty() {
	return front == rear;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &maze[i][j]);
			dist[i][j] = -1;
		}
	}

	dist[0][0] = 1;
	push(0, 0);

	while (!isEmpty()) {
		Node cur = pop();
		int x = cur.x;
		int y = cur.y;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (maze[ny][nx] == 0 || dist[ny][nx] != -1) continue;

			dist[ny][nx] = dist[y][x] + 1;
			push(ny, nx);
		}
	}

	printf("%d", dist[N - 1][M - 1]);

	return 0;
}