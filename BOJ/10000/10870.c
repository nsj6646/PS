#include <stdio.h>

int main()
{
	int n;
	int f0 = 0, f1 = 1, fn;
	scanf("%d", &n);
	if (n == 0) {
		printf("0");
	}
	else if (n == 1) {
		printf("1");
	}
	else {
		for (int i = 2; i <= n; i++) {
			fn = f0 + f1;
			f0 = f1;
			f1 = fn;
		}
		printf("%d", fn);
	}
	return 0;
}