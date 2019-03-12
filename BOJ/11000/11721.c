#include <stdio.h>

int main()
{
	char str[11];
	while (scanf("%10s", str) == 1) {
		printf("%s\n", str);
	}
	return 0;
}