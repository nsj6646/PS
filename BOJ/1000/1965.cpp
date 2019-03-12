#define MAXN		1005
#include <bits/stdc++.h>
using namespace std;

int a[MAXN];
int lis[MAXN];
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		lis[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (a[i] > a[j]) {
				lis[i] = max(lis[i], lis[j] + 1);
			}
		}
	}
	cout << *max_element(lis, lis + n);
	return 0;
}