#define MAX(X,Y)	(X)>(Y)?(X):(Y)
#include <cstdio>

int h[1000];
int a[1000];
int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	int A=0, H=0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", h + i);
		H = MAX(H, h[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", a + i);
		A = MAX(A, a[i]);
	}
	printf("%d", A + H);
	return 0;
}