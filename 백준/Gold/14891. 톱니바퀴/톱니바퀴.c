#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int gear[4][8];
	int K, num, way;
	int temp, sum = 0;

	// 12시 방향부터 톱니바퀴 상태 입력
	// N극 = 0, S극 = 1
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &gear[i][j]);
		}
	}

	// 회전 횟수 입력
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		// 기어와 방향 입력
		scanf("%d %d", &num, &way);

		// 1번 기어 움직일 때
		if (num == 1) {
			if (way == 1) {
				// 1번 기어 시계방향
				temp = gear[0][7];
				for (int j = 7; j > 0; j--) {
					gear[0][j] = gear[0][j - 1];
				}
				gear[0][0] = temp;

				if (gear[0][3] != gear[1][6]) {
					temp = gear[1][0];
					for (int j = 0; j < 7; j++) {
						gear[1][j] = gear[1][j + 1];
					}
					gear[1][7] = temp;

					if (gear[1][1] != gear[2][6]) {
						temp = gear[2][7];
						for (int j = 7; j > 0; j--) {
							gear[2][j] = gear[2][j - 1];
						}
						gear[2][0] = temp;

						if (gear[2][3] != gear[3][6]) {
							temp = gear[3][0];
							for (int j = 0; j < 7; j++) {
								gear[3][j] = gear[3][j + 1];
							}
							gear[3][7] = temp;
						}
					}
				}
			}
			else if (way == -1) {
				temp = gear[0][0];
				for (int j = 0; j < 7; j++) {
					gear[0][j] = gear[0][j + 1];
				}
				gear[0][7] = temp;

				if (gear[0][1] != gear[1][6]) {
					temp = gear[1][7];
					for (int j = 7; j > 0; j--) {
						gear[1][j] = gear[1][j - 1];
					}
					gear[1][0] = temp;

					if (gear[1][3] != gear[2][6]) {
						temp = gear[2][0];
						for (int j = 0; j < 7; j++) {
							gear[2][j] = gear[2][j + 1];
						}
						gear[2][7] = temp;

						if (gear[2][1] != gear[3][6]) {
							temp = gear[3][7];
							for (int j = 7; j > 0; j--) {
								gear[3][j] = gear[3][j - 1];
							}
							gear[3][0] = temp;
						}
					}
				}
			}
		}
		// 2번 기어 움직일 때
		else if (num == 2) {
			if (way == 1) {
				temp = gear[1][7];
				for (int j = 7; j > 0; j--) {
					gear[1][j] = gear[1][j - 1];
				}
				gear[1][0] = temp;

				if (gear[1][3] != gear[2][6]) {
					temp = gear[2][0];
					for (int j = 0; j < 7; j++) {
						gear[2][j] = gear[2][j + 1];
					}
					gear[2][7] = temp;

					if (gear[2][1] != gear[3][6]) {
						temp = gear[3][7];
						for (int j = 7; j > 0; j--) {
							gear[3][j] = gear[3][j - 1];
						}
						gear[3][0] = temp;
					}
				}

				if (gear[1][7] != gear[0][2]) {
					temp = gear[0][0];
					for (int j = 0; j < 7; j++) {
						gear[0][j] = gear[0][j + 1];
					}
					gear[0][7] = temp;
				}
			}
			else if (way == -1) {
				temp = gear[1][0];
				for (int j = 0; j < 7; j++) {
					gear[1][j] = gear[1][j + 1];
				}
				gear[1][7] = temp;

				if (gear[1][1] != gear[2][6]) {
					temp = gear[2][7];
					for (int j = 7; j > 0; j--) {
						gear[2][j] = gear[2][j - 1];
					}
					gear[2][0] = temp;

					if (gear[2][3] != gear[3][6]) {
						temp = gear[3][0];
						for (int j = 0; j < 7; j++) {
							gear[3][j] = gear[3][j + 1];
						}
						gear[3][7] = temp;
					}
				}

				if (gear[1][5] != gear[0][2]) {
					temp = gear[0][7];
					for (int j = 7; j > 0; j--) {
						gear[0][j] = gear[0][j - 1];
					}
					gear[0][0] = temp;
				}
			}

		}
		// 3번 기어 움직일 때
		else if (num == 3) {
			if (way == 1) {
				temp = gear[2][7];
				for (int j = 7; j > 0; j--) {
					gear[2][j] = gear[2][j - 1];
				}
				gear[2][0] = temp;

				if (gear[2][3] != gear[3][6]) {
					temp = gear[3][0];
					for (int j = 0; j < 7; j++) {
						gear[3][j] = gear[3][j + 1];
					}
					gear[3][7] = temp;
				}

				if (gear[2][7] != gear[1][2]) {
					temp = gear[1][0];
					for (int j = 0; j < 7; j++) {
						gear[1][j] = gear[1][j + 1];
					}
					gear[1][7] = temp;

					if (gear[1][5] != gear[0][2]) {
						temp = gear[0][7];
						for (int j = 7; j > 0; j--) {
							gear[0][j] = gear[0][j - 1];
						}
						gear[0][0] = temp;
					}
				}
			}
			else if (way == -1) {
				temp = gear[2][0];
				for (int j = 0; j < 7; j++) {
					gear[2][j] = gear[2][j + 1];
				}
				gear[2][7] = temp;

				if (gear[2][1] != gear[3][6]) {
					temp = gear[3][7];
					for (int j = 7; j > 0; j--) {
						gear[3][j] = gear[3][j - 1];
					}
					gear[3][0] = temp;
				}

				if (gear[2][5] != gear[1][2]) {
					temp = gear[1][7];
					for (int j = 7; j > 0; j--) {
						gear[1][j] = gear[1][j - 1];
					}
					gear[1][0] = temp;

					if (gear[1][7] != gear[0][2]) {
						temp = gear[0][0];
						for (int j = 0; j < 7; j++) {
							gear[0][j] = gear[0][j + 1];
						}
						gear[0][7] = temp;
					}
				}
			}
		}
		// 4번 기어 움직일 때
		else if (num == 4) {
			if (way == 1) {
				temp = gear[3][7];
				for (int j = 7; j > 0; j--) {
					gear[3][j] = gear[3][j - 1];
				}
				gear[3][0] = temp;

				if (gear[3][7] != gear[2][2]) {
					temp = gear[2][0];
					for (int j = 0; j < 7; j++) {
						gear[2][j] = gear[2][j + 1];
					}
					gear[2][7] = temp;

					if (gear[2][5] != gear[1][2]) {
						temp = gear[1][7];
						for (int j = 7; j > 0; j--) {
							gear[1][j] = gear[1][j - 1];
						}
						gear[1][0] = temp;

						if (gear[1][7] != gear[0][2]) {
							temp = gear[0][0];
							for (int j = 0; j < 7; j++) {
								gear[0][j] = gear[0][j + 1];
							}
							gear[0][7] = temp;
						}
					}
				}
			}
			if (way == -1) {
				temp = gear[3][0];
				for (int j = 0; j < 7; j++) {
					gear[3][j] = gear[3][j + 1];
				}
				gear[3][7] = temp;

				if (gear[3][5] != gear[2][2]) {
					temp = gear[2][7];
					for (int j = 7; j > 0; j--) {
						gear[2][j] = gear[2][j - 1];
					}
					gear[2][0] = temp;

					if (gear[2][7] != gear[1][2]) {
						temp = gear[1][0];
						for (int j = 0; j < 7; j++) {
							gear[1][j] = gear[1][j + 1];
						}
						gear[1][7] = temp;

						if (gear[1][5] != gear[0][2]) {
							temp = gear[0][7];
							for (int j = 7; j > 0; j--) {
								gear[0][j] = gear[0][j - 1];
							}
							gear[0][0] = temp;
						}
					}
				}
			}
		}
	}

	if (gear[0][0] == 1)
		sum += 1;
	if (gear[1][0] == 1)
		sum += 2;
	if (gear[2][0] == 1)
		sum += 4;
	if (gear[3][0] == 1)
		sum += 8;

	printf("%d", sum);

	return 0;
}