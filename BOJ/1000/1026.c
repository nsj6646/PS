#include <stdio.h>

int main(void)
{
	int n;
	int s=0;
	int a[50];
	int b[50];
	int i, j;
	int tmp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] < a[j + 1]) {
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] =tmp;
			}
		}
	}
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (b[j] > b[j + 1]) {
				tmp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		s += a[i] * b[i];
	}
	printf("%d", s);
	return 0; 
}