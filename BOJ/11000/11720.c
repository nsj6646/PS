#include <stdio.h>

int main()
{
	int N, sum = 0;
	int num[100];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%1d", &num[i]);
		sum += num[i];
	}
	printf("%d", sum);
	return 0;
}