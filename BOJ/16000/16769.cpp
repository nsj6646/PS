#include <cstdio>

int m[3];
int c[3];
int main()
{
	for (int i = 0; i < 3; ++i) {
		scanf("%d %d", c + i, m + i);
	}
	int now;
	int next;
	for (int t = 0; t < 100; ++t) {
		now = t % 3;
		next = (t + 1) % 3;
		m[next] += m[now];
		m[now] = 0;
		if (m[next] > c[next]) {
			m[now] = m[next] - c[next];
			m[next] = c[next];
		}
	}
	for (int i = 0; i < 3; ++i) {
		printf("%d\n", m[i]);
	}
	return 0;
}