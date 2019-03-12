#define N		100000
#define M		1000
#define MAX(X,Y)	(X)>(Y)?(X):(Y)
#include <cstdio>

int n, m, k;


int a[N];
int arrX[M][M];
int ans;
bool check(int len) {
	for (int s = 0; s < m; ++s) {
		int cnt = 1;
		for (int i = 0; i < m; ++i) {
			for (int j = i + 1; j < m; ++j) {
				if (arrX[s][i] + len <= arrX[s][j] && ((arrX[s][0] - arrX[s][j])<0 ? n + (arrX[s][0] - arrX[s][j]) : arrX[s][0] - arrX[s][j]) >= len) {
					cnt += 1;
					if (cnt >= k) {
						return true;
					}
					i = j - 1;
					break;
				}
			}
		}
	}

	return false;
}
int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &a[i]);
		for (int j = 0; j < m; ++j) {
			arrX[j][((i - j) + m) % m] = a[i];
		}
	}

	if (k == 1) {
		printf("%d", n);
		return 0;
	}
	int bowLen = n / k;

	int low = 0; int high = bowLen;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (check(mid)) {
			ans = MAX(ans, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	printf("%d\n", ans);

	return 0;
}