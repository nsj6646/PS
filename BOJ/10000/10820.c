#include <stdio.h>

int main()
{
	char c;
	int lower=0, upper=0, number=0, space = 0;
	while ((c = getchar()) && c != EOF) {
		if (c == '\n') {
			printf("%d %d %d %d\n", lower, upper, number, space);
			lower = 0, upper = 0, number = 0, space = 0;
		}
		else {
			if (c >= 'A'&&c <= 'Z') upper++;
			else if (c >= 'a'&&c <= 'z')lower++;
			else if (c == ' ')space++;
			else number++;
		}
	}
	return 0;
}