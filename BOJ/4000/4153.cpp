#include <cstdio>

void swap(long long *x, long long *y) {
	long long temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{
	long long a, b, c;
	while (scanf("%lld %lld %lld", &a, &b, &c)) {
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		if (a > b) {
			swap(&a, &b);
		}
		if (b > c) {
			swap(&b, &c);
		}
		if (c*c == a * a + b * b) {
			printf("right\n");
		}
		else {
			printf("wrong\n");
		}
	}
	return 0;
}