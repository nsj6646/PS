#include <cstdio>

int main()
{
	int total = 0;
	for (int i = 0; i < 4; i++) {
		int t;
		scanf("%d", &t);
		total += t;
	}
	int x = total / 60;
	int y = total % 60;
	printf("%d\n%d", x, y);
	return 0;
}