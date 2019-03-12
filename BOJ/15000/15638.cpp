#define N	100000
#include <cstdio>

bool eratos[N+1];
int main()
{
	for (int i = 2; i*i <= N; ++i) {
		if (!eratos[i]) {
			for (int j = i * i; j <= N; j += i) {
				eratos[j] = true;
			}
		}
	}
	int n;
	scanf("%d", &n);
	printf("%s", eratos[n] ? "No" : "Yes");
	return 0;
}