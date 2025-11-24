#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 100001

int N, K;
int visited[MAX];

typedef struct {
	int x, time;
}Node;

Node queue[MAX];
int front = 0, rear = 0;

void push(int x, int time) {
	queue[rear].x = x;
	queue[rear].time = time;
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
	int i = 0, min = MAX;
	int cnt[MAX];

	scanf("%d %d", &N, &K);

	if (N >= K) {
		printf("%d", N - K);
		return 0;
	}

	visited[N] = 1;
	push(N, 0);

	while (!isEmpty()) {
		Node cur = pop();
		int x = cur.x;
		int time = cur.time;
		int nx, nextTime = time + 1;;

		if (x == K) {
			printf("%d\n", time);
			return 0;
		}

		nx = x - 1;
		if (0 <= nx && !visited[nx]) {
			push(nx, nextTime);
			visited[nx] = 1;
		}

		nx = x + 1;
		if (nx < MAX && !visited[nx]) {
			push(nx, nextTime);
			visited[nx] = 1;
		}

		nx = 2 * x;
		if (nx < MAX && !visited[nx]) {
			push(nx, nextTime);
			visited[nx] = 1;
		}
	}
	return 0;
}