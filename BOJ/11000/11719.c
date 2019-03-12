/*
#include <stdio.h>

char str[100];
int main()
{
	while (fgets(str, 100, stdin)) {
		printf("%s", str);
	}
	return 0;
}
*/
#include <stdio.h>

int main()
{
	char c;
	while ((c = getchar()) && c != EOF) {
		printf("%c", c);
	}
	return 0;
}