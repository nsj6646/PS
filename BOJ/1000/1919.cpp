#include <cstdio>

int a[26];

int main()
{
	char c;
	while ((c = getchar()) && c != '\n') {
		a[c - 'a'] += 1;
	}
	while ((c = getchar()) && c != '\n') {
		a[c - 'a'] -= 1;
	}
	int ans = 0;
	for (int i = 0; i < 26; ++i) {
		ans += a[i] < 0 ? -a[i] : a[i];
	}
	printf("%d", ans);
	return 0;
}