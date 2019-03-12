#include <stdio.h>

int main()
{
	int num;
	int min = 100, sum = 0;

	for (int i = 0; i < 7; i++) {
		scanf("%d", &num);
		if (num % 2) {
			sum += num;
			if (num < min) {
				min = num;
			}
		}
	}
	if (!sum) {
		printf("-1");
		return 0;
	}
	printf("%d\n", sum);
	printf("%d", min);
	return 0;
}