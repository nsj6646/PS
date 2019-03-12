#include <cstdio>

int a[20];
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	
	int y = 0, m = 0;
	for (int i = 0; i < n; ++i) {
		y += (a[i] / 30+1) * 10;
		m += (a[i] / 60+1) * 15;
	}
	if (y > m) {
		printf("M ");
		printf("%d", m);
	}
	else {
		printf("Y ");
		if (y == m) {
			printf("M ");
		}
		printf("%d", y);
		
	}
	return 0;
}