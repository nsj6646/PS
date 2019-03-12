#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int cnt = 1;
	while (n != 1) {
		cnt += 1;
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n = n * 3 + 1;
		}
	}
	printf("%d\n", cnt);

	return 0;
}