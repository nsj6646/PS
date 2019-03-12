#define N		17
#define MIN(x,y)	(x)>(y)?(y):(x)
#include <cstdio>

int Bessie[N][N];
int Elsie[N][N];
int costB[1<<N];
int costE[1<<N];
int idxB, idxE;
int n, m;

void goBessie(int from, int cost) {
	if (from == n) {
		costB[idxB++] = cost;
		return;
	}

	for (int to = from+1; to <= n; ++to) {
		if (Bessie[from][to] != 0) {
			goBessie(to, cost + Bessie[from][to]);
		}
	}
	return;
}
void goElsie(int from, int cost) {
	if (from == n) {
		costE[idxE++] = cost;
		return;
	}
	for (int to = from+1; to <= n; ++to) {
		if (Elsie[from][to] != 0) {
			goElsie(to, cost + Elsie[from][to]);
		}
	}
	return;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		Bessie[a][b] = c;
		Elsie[a][b] = d;
	}


	for (int i = 2; i <= n; ++i) {
		if (Bessie[1][i] != 0) {
			goBessie(i, Bessie[1][i]);
		}

	}
	for (int i = 2; i <= n; ++i) {
		if (Elsie[1][i] != 0) {
			goElsie(i, Elsie[1][i]);
		}
	}

	int ans = 1000000;
	for (int i = 0; i < idxB; ++i) {
		for (int j = 0; j < idxE; ++j) {
			if (costB[i] == costE[j]) {		
				ans = MIN(ans, costE[j]);
			}
		}
	}
	if (ans == 1000000) {
		printf("IMPOSSIBLE");
	}
	else {
		printf("%d", ans);
	}
	return 0;
}