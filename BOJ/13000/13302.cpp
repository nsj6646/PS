#include <cstdio>
#include <algorithm>
int d[101][101];
bool check[101];
int c;
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		check[x] = true;
	}

	return 0;
}