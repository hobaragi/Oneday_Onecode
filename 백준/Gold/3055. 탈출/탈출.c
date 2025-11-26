#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 50

// R=y, C=x
// .=빈칸, *=물, X=돌
// D=비버굴, S=고슴도치

int R, C;
char map[MAX][MAX];
int distS[MAX][MAX];
int distW[MAX][MAX];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

typedef struct {
	int x, y;
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
	int sx, sy, Dx, Dy;

	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			distW[i][j] = -1;
			distS[i][j] = -1;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'S') {
				sy = i;
				sx = j;
			}
			else if (map[i][j] == 'D') {
				Dy = i;
				Dx = j;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '*') {
				distW[i][j] = 0;
				push(i, j);
			}
		}
	}

	while (!isEmpty()) {
		Node cur = pop();
		int x = cur.x;
		int y = cur.y;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
			if (map[ny][nx] == 'X' || map[ny][nx] == 'D') continue;
			if (distW[ny][nx] != -1) continue;

			distW[ny][nx] = distW[y][x] + 1;
			push(ny, nx);
		}
	}

	front = rear = 0;
	distS[sy][sx] = 0;
	push(sy, sx);
	
	while (!isEmpty()) {
		Node cur = pop();
		int x = cur.x;
		int y = cur.y;

		if (y == Dy && x == Dx) {
			printf("%d\n", distS[y][x]);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
			if (map[ny][nx] == 'X') continue;
			if (distS[ny][nx] != -1) continue;
			if (distW[ny][nx] != -1 && distW[ny][nx] <= distS[y][x] + 1) continue;

			distS[ny][nx] = distS[y][x] + 1;
			push(ny, nx);
		}
	}

	printf("KAKTUS\n");

	return 0;
}