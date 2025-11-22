#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int N, M;
	int r, c, d;
	int room[50][50];
	int cnt = 0;		// 청소한 방 개수

	// 방 크기 입력
	scanf("%d %d", &N, &M);

	// 로봇 청소기 위치, 바라보는 방향 입력
	// 0:북, 1:동, 2:남, 3:서
	scanf("%d %d %d", &r, &c, &d);

	// 방 상태 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &room[i][j]);
		}
	}

	while (1) {

		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("%d ", room[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/


		// 현재 칸이 청소되지 않은 빈 칸인 경우
		if (room[r][c] == 0) {
			room[r][c] = 2;
			cnt++;
		}

		// 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
		if ((room[r - 1][c] != 0) && (room[r + 1][c] != 0) && (room[r][c - 1] != 0) && (room[r][c + 1] != 0)) {
			if (d == 0) {
				if (room[r + 1][c] == 1)
					break;
				else {
					r++;
					continue;
				}
			}
			else if (d == 1) {
				if (room[r][c - 1] == 1)
					break;
				else {
					c--;
					continue;
				}
			}
			else if (d == 2) {
				if (room[r - 1][c] == 1)
					break;
				else {
					r--;
					continue;
				}
			}
			else if (d == 3) {
				if (room[r][c + 1] == 1)
					break;
				else {
					c++;
					continue;
				}
			}
		}
		else {
			if (d == 0)
				d = 3;
			else
				d--;

			if (d == 0) {
				if (room[r - 1][c] == 0) {
					r--;
					continue;
				}
			}
			else if (d == 1) {
				if (room[r][c + 1] == 0) {
					c++;
					continue;
				}
			}
			else if (d == 2) {
				if (room[r + 1][c] == 0) {
					r++;
					continue;
				}
			}
			else if (d == 3) {
				if (room[r][c - 1] == 0) {
					c--;
					continue;
				}
			}
		}
	}

	printf("%d", cnt);

	return 0;
}