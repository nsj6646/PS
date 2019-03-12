#include <stdio.h>

int a[100000];
int b[100000];
int main()
{
	int n, m;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}

	return 0;
}