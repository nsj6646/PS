#include <cstdio>

int main()
{
	int n, w, h;
	scanf("%d %d %d", &n, &w, &h);
	int limit = w * w + h * h;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x*x <= limit) {
			printf("DA\n");
		}
		else {
			printf("NE\n");
		}
	}
	return 0;
}