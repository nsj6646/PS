#include <cstdio>

int main()
{
	char c;
	while ((c = getchar()) && c != '\n') {
		if (c == 'A') {
			putchar('X');
		}
		else if (c == 'B') {
			putchar('Y');
		}
		else if (c == 'C') {
			putchar('Z');
		}
		else {
			putchar(c - 3);
		}
	}
	return 0;
}