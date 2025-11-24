#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gear[4][8];

void change(int num, int way) {
	int temp;
	if (way == 1) {
		temp = gear[num][7];
		for (int i = 7; i > 0; i--) {
			gear[num][i] = gear[num][i - 1];
		}
		gear[num][0] = temp;
	}
	else if (way == -1) {
		temp = gear[num][0];
		for (int i = 0; i < 7; i++) {
			gear[num][i] = gear[num][i + 1];
		}
		gear[num][7] = temp;
	}
}

int main()
{
	int K, num, way, score = 0;
	int check[3];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &gear[i][j]);
		}
	}

	for (int i = 0; i < 3; i++) {
		if (gear[i][2] == gear[i + 1][6])
			check[i] = 0;
		else
			check[i] = 1;
	}

	scanf("%d", &K);

	int rotate[4];

	for (int cmd = 0; cmd < K; cmd++) {
		scanf("%d %d", &num, &way);
		num--; // 0-based로 변환

		// 1. 인접 극 확인
		for (int i = 0; i < 3; i++) {
			check[i] = (gear[i][2] != gear[i + 1][6]);
		}

		// 2. 회전 배열 초기화
		for (int i = 0; i < 4; i++) rotate[i] = 0;
		rotate[num] = way;

		// 3. 왼쪽으로 전달
		for (int i = num - 1; i >= 0; i--) {
			if (check[i] == 1) rotate[i] = -rotate[i + 1];
			else break;
		}

		// 4. 오른쪽으로 전달
		for (int i = num; i < 3; i++) {
			if (check[i] == 1) rotate[i + 1] = -rotate[i];
			else break;
		}

		// 5. 실제 회전
		for (int i = 0; i < 4; i++) {
			if (rotate[i] != 0) change(i, rotate[i]);
		}
	}


	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == 1) {
			score += (1 << i);   // 1, 2, 4, 8
		}
	}

	printf("%d", score);

	return 0;
}