#include <iostream>
using namespace std;

int a[3000][3000];
int papers[3];	//-1 0 1

void divide(int x, int y, int n) {
	bool equal = true;
	for (int i = y; i < y+n; i++) {
		for (int j = x; j < x+n; j++) {
			if (a[y][x] != a[i][j]) {
				equal = false;
				break;
			}
		}
		if (!equal) {
			break;
		}
	}

	if (equal || n == 1) {
		papers[a[y][x] + 1] += 1;
		return;
	}
	else {
		divide(x, y, n / 3);
		divide(x + n / 3, y, n / 3);
		divide(x + n / 3 * 2, y, n / 3);

		divide(x, y + n / 3, n / 3);
		divide(x + n / 3, y + n / 3, n / 3);
		divide(x + n / 3 * 2, y + n / 3, n / 3);

		divide(x, y + n / 3 * 2, n / 3);
		divide(x + n / 3, y + n / 3 * 2, n / 3);
		divide(x + n / 3 * 2, y + n / 3 * 2, n / 3);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	divide(0, 0, n);
	for (int i = 0; i < 3; i++) {
		cout << papers[i] << '\n';
	}
	return 0;
}
//#include <cstdio>
//int a[3000][3000];
//int cnt[3];
//bool same(int x, int y, int n) {
//	for (int i = x; i<x + n; i++) {
//		for (int j = y; j<y + n; j++) {
//			if (a[x][y] != a[i][j]) {
//				return false;
//			}
//		}
//	}
//	return true;
//}
//void solve(int x, int y, int n) {
//	if (same(x, y, n)) {
//		cnt[a[x][y] + 1] += 1;
//		return;
//	}
//	int m = n / 3;
//	for (int i = 0; i<3; i++) {
//		for (int j = 0; j<3; j++) {
//			solve(x + i * m, y + j * m, m);
//		}
//	}
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i<n; i++) {
//		for (int j = 0; j<n; j++) {
//			scanf("%d", &a[i][j]);
//		}
//	}
//	solve(0, 0, n);
//	for (int i = 0; i<3; i++) {
//		printf("%d\n", cnt[i]);
//	}
//	return 0;
//}