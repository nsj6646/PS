#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	reverse(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}
	cout << *max_element(d.begin(), d.end());
	return 0;
}
/*
#include <cstdio>
int a[1001];
int d[1001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = n; i >= 1; i--) {
		d[i] = 1;
		for (int j = i + 1; j <= n; j++) {
			if (a[i] > a[j] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
	}
	int ans = d[1];
	for (int i = 2; i <= n; i++) {
		if (ans < d[i]) {
			ans = d[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
*/