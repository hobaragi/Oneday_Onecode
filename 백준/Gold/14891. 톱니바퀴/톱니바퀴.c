#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int gear[4][8];

// n=방향, m=기어 번호
void rotate(int n, int m) {
	int temp;
	if (n == 1) {
		temp = gear[m][7];
		for (int i = 7; i > 0; i--)
			gear[m][i] = gear[m][i - 1];
		gear[m][0] = temp;
	}
	else if (n == -1) {
		temp = gear[m][0];
		for (int i = 0; i < 7; i++)
			gear[m][i] = gear[m][i + 1];
		gear[m][7] = temp;
	}
}

int main()
{
	int K, num, way;
	int temp, sum = 0;
	int result[3];

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
		scanf("%d %d", &num, &way);

		// 다른 극인지 확인
		for (int j = 0; j < 3; j++) {
			if (gear[j][2] != gear[j+1][6])
				result[j] = 1;
			else
				result[j] = 0;
		}

		// 1번 기어
		if (num == 1) {
			if (way == 1) {
				rotate(1, 0);
				if (result[0] == 1) {
					rotate(-1, 1);
					if (result[1] == 1) {
						rotate(1, 2);
						if (result[2] == 1) {
							rotate(-1, 3);
						}
					}
				}
			}
			else {
				rotate(-1, 0);
				if (result[0] == 1) {
					rotate(1, 1);
					if (result[1] == 1) {
						rotate(-1, 2);
						if (result[2] == 1) {
							rotate(1, 3);
						}
					}
				}
			}
		}
		// 2번 기어
		else if (num == 2) {
			if (way == 1) {
				rotate(1, 1);
				if (result[0] == 1) {
					rotate(-1, 0);
				}
				if (result[1] == 1) {
					rotate(-1, 2);
					if (result[2] == 1) {
						rotate(1, 3);
					}
				}
			}
			else {
				rotate(-1, 1);
				if (result[0] == 1) {
					rotate(1, 0);
				}
				if (result[1] == 1) {
					rotate(1, 2);
					if (result[2] == 1) {
						rotate(-1, 3);
					}
				}
			}
		}
		// 3번 기어
		else if (num == 3) {
			if (way == 1) {
				rotate(1, 2);
				if (result[2] == 1) {
					rotate(-1, 3);
				}
				if (result[1] == 1) {
					rotate(-1, 1);
					if (result[0] == 1) {
						rotate(1, 0);
					}
				}
			}
			else {
				rotate(-1, 2);
				if (result[2] == 1) {
					rotate(1, 3);
				}
				if (result[1] == 1) {
					rotate(1, 1);
					if (result[0] == 1) {
						rotate(-1, 0);
					}
				}
			}
		}
		// 4번 기어
		else if (num == 4) {
			if (way == 1) {
				rotate(1, 3);
				if (result[2] == 1) {
					rotate(-1, 2);
					if (result[1] == 1) {
						rotate(1, 1);
						if (result[0] == 1) {
							rotate(-1, 0);
						}
					}
				}
			}
			else {
				rotate(-1, 3);
				if (result[2] == 1) {
					rotate(1, 2);
					if (result[1] == 1) {
						rotate(-1, 1);
						if (result[0] == 1) {
							rotate(1, 0);
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