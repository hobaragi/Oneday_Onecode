#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 101

int N, M, H;
int maze[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];

int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 0,0,0,0,1,-1 };
int dz[6] = { 1,-1,0,0,0,0 };

typedef struct {
	int x, y, z;
}Node;

Node queue[MAX * MAX * MAX];
int front = 0, rear = 0;

void push(int z, int x, int y) {
	queue[rear].x = x;
	queue[rear].y = y;
	queue[rear].z = z;
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
	int cnt = 0, max = 0;

	scanf("%d %d %d", &M, &N, &H);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				scanf("%d", &maze[i][j][k]);
				if (maze[i][j][k] == 1) {
					push(i, j, k);
					dist[i][j][k] = 0;
					visited[i][j][k] = 1;
				}
				else if (maze[i][j][k] == 0)
					cnt++;
			}
		}
	}

	if (cnt == 0) {
		printf("0");
		return 0;
	}

	while (!isEmpty()) {
		Node cur = pop();
		int x = cur.x;
		int y = cur.y;
		int z = cur.z;

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
			if (maze[nz][nx][ny] != 0 || visited[nz][nx][ny]) continue;

			visited[nz][nx][ny] = 1;
			dist[nz][nx][ny] = dist[z][x][y] + 1;
			push(nz, nx, ny);
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (visited[i][j][k] != 1 && maze[i][j][k] == 0) {
					printf("-1");
					return 0;
				}
				if (max < dist[i][j][k])
					max = dist[i][j][k];
			}
		}
	}

	printf("%d", max);

	return 0;
}