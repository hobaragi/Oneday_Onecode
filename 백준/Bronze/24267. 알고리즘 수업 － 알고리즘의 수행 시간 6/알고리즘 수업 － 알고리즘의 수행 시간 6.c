#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	long long n;
	scanf("%lld", &n);

	printf("%lld\n3", ((n-2)*(n*(n-1)))/6);

	return 0;
}