#include <cstdio>
#include <cstring>
#include <cstdlib>
char a[10];
char b[10];

int main()
{
	scanf("%s %s", a, b);
	int lenA = strlen(a);
	int lenB = strlen(b);

	for (int i = 0; i < lenA; ++i) {
		if (a[i] == '6') {
			a[i] = '5';
		}
	}
	for (int i = 0; i < lenB; ++i) {
		if (b[i] == '6') {
			b[i] = '5';
		}
	}
	int numA = atoi(a);
	int numB = atoi(b);
	int min = numA + numB;

	for (int i = 0; i < lenA; ++i) {
		if (a[i] == '5') {
			a[i] = '6';
		}
	}
	for (int i = 0; i < lenB; ++i) {
		if (b[i] == '5') {
			b[i] = '6';
		}
	}

	numA = atoi(a);
	numB = atoi(b);
	int max = numA + numB;

	printf("%d %d", min, max);
	return 0;
}