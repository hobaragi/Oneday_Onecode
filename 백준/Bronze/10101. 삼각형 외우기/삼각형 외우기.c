#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n[3], cnt = 0, total = 0;

	for (int i = 0; i < 3; i++) scanf("%d", &n[i]);

	for (int i = 0; i < 3; i++) {
		int d = (i + 1) % 3;
		
		total += n[i];

		if (n[i] == n[d]) cnt++;
	}

	if (total != 180) {
		printf("Error");
		return 0;
	}

	if (cnt == 3) printf("Equilateral");
	else if (cnt == 1) printf("Isosceles");
	else printf("Scalene");

	return 0;
}