#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100001

int dist[MAX] = { 0 };

typedef struct {
	int x;
}Node;

Node queue[MAX];
int front = 0, rear = 0;

void push(int x) {
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
	int N, K;

	scanf("%d %d", &N, &K);

	// 동생이 수빈이보다 왼쪽에 있을 경우
	if (N >= K) {
		printf("%d", N - K);
		return 0;
	}

	dist[N] = 1;
	push(N);

	while (!isEmpty()) {
		Node cur = pop();
		int X = cur.x;

		// 수빈이 위치에 도착할 경우
		if (X == K) {
			printf("%d", dist[K] - 1);
			return 0;
		}

		if (2 * X < MAX && dist[2*X] == 0) {
			dist[2 * X] = dist[X] + 1;
			push(2 * X);
		}
		if (X + 1 < MAX && dist[X+1] == 0) {
			dist[X+1] = dist[X] + 1;
			push(X + 1);
		}
		if (X - 1 >= 0 && dist[X-1] == 0) {
			dist[X-1] = dist[X] + 1;
			push(X - 1);
		}
	}

	return 0;
}