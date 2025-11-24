#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 101

int H, N, M;
int maze[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];

int dz[6] = { 1,-1,0,0,0,0 };
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 0,0,0,0,1,-1 };

typedef struct {
	int z, x, y;
}Node;

Node queue[MAX * MAX * MAX];
int front = 0, rear = 0;

void push(int z, int x, int y) {
	queue[rear].z = z;
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
					visited[i][j][k] = 1;
					dist[i][j][k] = 0;
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
		int z = cur.z;
		int x = cur.x;
		int y = cur.y;

		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nz < 0 || nx < 0 || ny < 0 || nz >= H || nx >= N || ny >= M) continue;
			if (maze[nz][nx][ny] != 0 || visited[nz][nx][ny]) continue;

			visited[nz][nx][ny] = 1;
			dist[nz][nx][ny] = dist[z][x][y] + 1;
			push(nz, nx, ny);
		}
	}

	cnt = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (max < dist[i][j][k])
					max = dist[i][j][k];

				if (maze[i][j][k] == 0 && visited[i][j][k] == 0) {
					printf("-1");
					return 0;
				}

			}
		}
	}

	printf("%d", max);

	return 0;

}