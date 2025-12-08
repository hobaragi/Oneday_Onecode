#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char board[50][50];

int sibal(int y, int x) {
	int cntW = 0, cntB = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			char cur = board[y + i][x + j];

			if ((i+j)%2 == 0) {
				if (cur == 'W') cntW++;
				if (cur == 'B') cntB++;
			}
			else if ((i+j)%2 == 1) {
				if (cur == 'B') cntW++;
				if (cur == 'W') cntB++;
			}
		}
	}

	return (cntW < cntB) ? cntW : cntB;
}

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	int answer = 64;

	for (int i = 0; i <= N-8; i++) {
		for (int j = 0; j <= M-8; j++) {
			int result = sibal(i, j);
			if (result < answer) answer = result;
		}
	}

	printf("%d\n", answer);

	return 0;
}