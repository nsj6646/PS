#include <cstdio>

int a[26];
int main()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		char str[31];
		scanf("%s", str);
		a[str[0] - 'a'] += 1;
	}
	int sur = 0;
	for (int i = 0; i < 26; i++) {
		if (a[i] >= 5) {
			printf("%c", 'a' + i);
			sur = 1;
		}
	}
	if (!sur) {
		printf("PREDAJA");
	}
	return 0;
}