#include <stdio.h>

int binary_coef(int n, int k) {
	int top = 1;
	for (int i = n - k + 1; i <= n; ++i) {
		top *= i;
	}
	int bot = 1;
	for (int i = 1; i <= k; ++i) {
		bot *= i;
	}
	return top / bot;
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", binary_coef(n, k));
	return 0;
}