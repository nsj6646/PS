#define SIZE	500001
#include <bits/stdc++.h>
using namespace std;

int a[SIZE];
int ans[SIZE];
int stk[SIZE];
int top = -1;
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = n; i >= 1; --i) {
		if (top == -1) {
			stk[++top] = i;
			continue;
		}
		while (top != -1 && a[i] >= a[stk[top]]) {
			ans[stk[top]] = i;
			--top;
		}
		stk[++top] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}

	return 0;
}