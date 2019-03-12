#include <cstdio>

int a[21];
void swap(int i, int j) {
	int temp;
	while (i <= j) {
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		i++; j--;
	}
}
int main()
{
	for (int i = 1; i <= 20; ++i) {
		a[i] = i;
	}
	for (int i = 0; i < 10; ++i) {
		int b, e;
		scanf("%d %d", &b, &e);
		swap(b, e);
	}
	for (int i = 1; i <= 20; ++i) {
		printf("%d ", a[i]);
	}
	return 0;
}