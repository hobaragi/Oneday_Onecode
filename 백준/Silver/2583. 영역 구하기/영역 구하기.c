#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

int M, N;
int map[MAX][MAX];
int visited[MAX][MAX];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dfs(int y, int x) {
	visited[y][x] = 1;
	int area = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
		if (map[ny][nx] == 1 || visited[ny][nx]) continue;

		area += dfs(ny, nx);
	}

	return area;
}

void sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	int K;

	scanf("%d %d %d", &M, &N, &K);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 0;
		}
	}

	// 직사각형 눈금 좌표를 1로
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				map[y][x] = 1;
			}
		}
	}
    
	int areas[MAX * MAX];
	int areaCount = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && !visited[i][j]) {
				int a = dfs(i, j);
				areas[areaCount++] = a;
			}
		}
	}

	sort(areas, areaCount);

	printf("%d\n", areaCount);
	for (int i = 0; i < areaCount; i++) {
		printf("%d ", areas[i]);
	}
	
	return 0;
}