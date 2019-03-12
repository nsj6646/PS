/*½Ã°£ÃÊ°ú
#include <cstdio>

int a[100001];
bool check[100001];
int s[100001];
int dfs(int x, int length, int start);

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int ans = n;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			check[i] = false;
			s[i] = 0;
			if (a[i] == i) {
				check[i] = true;
				ans -= 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				check[i] = true;
				ans-=dfs(i, 1, i);
			}
		}
		printf("%d\n", ans);

	}
	return 0;
}
int dfs(int x, int length, int start) {
	if (s[x]==start) {
		if (x == start) {
			while (a[x]!=start) {		
				x = a[x];
				check[x] = true;			
			}
			return length-1;
		}
		else {
			return 0;
		}
	}
	s[x] = start;
	dfs(a[x], length + 1, start);
}
*/
/*Àç±Í*/
#include <cstdio>
int a[100001];
int d[100001];
int s[100001];
int n;
int dfs(int x, int cnt, int &step) {
	if (d[x] != 0) {
		if (step != s[x]) {
			return 0;
		}
		return cnt - d[x];
	}
	d[x] = cnt;
	s[x] = step;
	return dfs(a[x], cnt + 1, step);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			d[i] = 0;
			s[i] = 0;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (d[i] == 0) {
				ans += dfs(i, 1, i);
			}
		}
		printf("%d\n", n - ans);
	}
	return 0;
}

/*ºñÀç±Í
#include <cstdio>
int a[100001];
int d[100001];
int s[100001];
int n;
int dfs(int x, int cnt, int &step) {
	while (true) {
		if (d[x] != 0) {
			if (step != s[x]) {
				return 0;
			}
			return cnt - d[x];
		}
		d[x] = cnt;
		s[x] = step;
		x = a[x];
		cnt += 1;
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			d[i] = 0;
			s[i] = 0;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (d[i] == 0) {
				ans += dfs(i, 1, i);
			}
		}
		printf("%d\n", n - ans);
	}
	return 0;
}
*/