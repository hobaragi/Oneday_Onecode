#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 101

int N, M;
int maze[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX][MAX];

// 큐 구현
typedef struct {
    int x, y;
} Node;

Node queue[MAX * MAX];
int front = 0, rear = 0;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


// 큐에 넣기
void push(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

// 큐에서 빼기
Node pop() {
    return queue[front++];
}

// 큐 비었는지 확인
int isEmpty() {
    return front == rear;
}


int main() {
    scanf("%d %d", &N, &M);

    // 미로 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &maze[i][j]);   // 한 글자씩 입력
        }
    }

    // BFS 시작점
    visited[0][0] = 1;
    dist[0][0] = 1;
    push(0, 0);

    while (!isEmpty()) {
        Node cur = pop();
        int x = cur.x;
        int y = cur.y;

        // 상하좌우 탐색
        for (int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 체크
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            // 벽(0) or 이미 방문 → 패스
            if (maze[nx][ny] == 0 || visited[nx][ny]) continue;

            // 방문 처리
            visited[nx][ny] = 1;
            dist[nx][ny] = dist[x][y] + 1;

            push(nx, ny);
        }
    }

    printf("%d\n", dist[N - 1][M - 1]);
    return 0;
}
