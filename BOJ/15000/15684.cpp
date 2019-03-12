#include <cstdio>

int n, m, h;
int a[31][12];
int ans = -1;
bool go() {
	for (int i = 1; i <= n; i++) {
		int result = i;
		for (int j = 1; j <= h; j++) {
			if (a[j][result] == 1) {
				result += 1;
			}
			else if (a[j][result - 1] == 1) {
				result -= 1;
			}
		}
		if (result != i) {
			return false;
		}
	}
	return true;
}
int solve(int i, int cnt) {
	if (cnt > 3) {
		return -1;
	}

	if (i == h+1) {
		if (go()) {
			if (ans == -1 || ans > cnt) {
				ans = cnt;
			}
			return ans;
		}
		else {
			return -1;
		}
	}

	solve(i + 1, cnt);
	for (int j = 1; j < n; j++) {
		if (a[i][j] == 0) {
			if (a[i][j - 1] == 0 && a[i][j + 1] == 0) {
				a[i][j] = 1;
				solve(i, cnt + 1);
				a[i][j] = 0;
			}
		}
	}

	return ans;
}
int main()
{
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x][y] = 1;
	}

	printf("%d\n", solve(1, 0));

	return 0;
}