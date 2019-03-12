#include <bits/stdc++.h>
using namespace std;

int a[100][100];
int save[100][100];

int n, m, r;
void f0() {}
void f1() {
	memcpy(save, a, sizeof(a));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j]=save[n - i - 1][j];
		}
	}
}
void f2() {
	memcpy(save, a, sizeof(a));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			a[j][i] = save[j][m - 1 - i];
		}
	}
}
void f3() {
	memcpy(save, a, sizeof(a));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = save[n - 1 - j][i];
		}
	}
	swap(n, m);
}
void f4() {
	memcpy(save, a, sizeof(a));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = save[j][m - 1 - i];
		}
	}
	swap(n, m);
}
void f5() {
	memcpy(save, a, sizeof(a));
	for (int i = 0; i < n/2; ++i) {
		for (int j = 0; j < m/2; ++j) {
			a[i][j] = save[i + n / 2][j];
			a[i][j + m / 2] = save[i][j];
			a[i + n / 2][j] = save[i + n / 2][j + m / 2];
			a[i + n / 2][j + m / 2] = save[i][j + m / 2];
		}
	}

}
void f6() {
	memcpy(save, a, sizeof(a));
	for (int i = 0; i < n / 2; ++i) {
		for (int j = 0; j < m / 2; ++j) {
			a[i][j] = save[i][j + m / 2];
			a[i][j + m / 2] = save[i + n / 2][j + m / 2];
			a[i + n / 2][j] = save[i][j];
			a[i + n / 2][j + m / 2] = save[i + n / 2][j];
		}
	}
}

void(*f[7])() = { f0,f1,f2,f3,f4,f5,f6 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> r;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < r; ++i) {
		int k;
		cin >> k;
		f[k]();
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}