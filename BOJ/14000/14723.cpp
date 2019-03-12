#include <cstdio>

struct rational {
	int a=1, b=1;
};
rational r[1001];
int n;
int main()
{
	int cnt = 1;
	for (int i = 1; cnt <= 1000; ++i) {
		for (int j = 1; j <= i&&cnt<=1000; ++j) {
			r[cnt].a = i - j + 1;
			r[cnt].b = j;
			++cnt;
		}
	}
	scanf("%d", &n);
	printf("%d %d", r[n].a, r[n].b);

	return 0;
}