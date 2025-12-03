#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

int M, N, H;
int map[MAX][MAX][MAX];
int dist[MAX][MAX][MAX] = { 0 };

int dz[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dx[6] = { 0,0,0,0,1,-1 };

typedef struct {
	int z, y, x;
}Node;

Node queue[MAX * MAX * MAX];
int front = 0, rear = 0;

void push(int z, int y, int x) {
	queue[rear].z = z;
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
	scanf("%d %d %d", &M, &N, &H);

	int cnt = 0;

	for (int z = 0; z < H; z++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				scanf("%d", &map[z][y][x]);
				if (map[z][y][x] == 0) cnt++;
				else if (map[z][y][x] == 1) push(z, y, x);
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

			if (nx < 0 || ny < 0 || nz < 0 || nx >= M || ny >= N || nz >= H) continue;
			if (map[nz][ny][nx] != 0 || dist[nz][ny][nx] != 0) continue;

			dist[nz][ny][nx] = dist[z][y][x] + 1;
			map[nz][ny][nx] = 1;
			push(nz, ny, nx);
		}
	}

	int max = 0;

	for (int z = 0; z < H; z++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (map[z][y][x] == 0) {
					printf("-1");
					return 0;
				}
				if (max < dist[z][y][x]) max = dist[z][y][x];
			}
		}
	}

	printf("%d", max);

	return 0;
}