#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int n;
		scanf("%d", &n);
		int max = 1;
		while (n != 1) {
			max = max < n ? n : max;
			if (n % 2 == 0) {
				n /= 2;
			}
			else {
				n = n * 3 + 1;
			}
		}
		printf("%d\n", max);
	}
	return 0;
}