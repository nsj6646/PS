#define N		500001
#define M		1000001

#include <cstdio>
typedef long long ll;
int a[N];
ll seg[N * 4];
int idx[M];


void update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y)return;
	if (x == y) {
		seg[node] = val;
		return;
	}
	int mid = (x + y) >> 1;
	update(pos, val, node * 2, x, mid);
	update(pos, val, node * 2 + 1, mid + 1, y);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
ll query(int lo, int hi, int node, int x, int y) {
	if (y<lo || x>hi) return 0;
	if (lo <= x && y <= hi) {
		return seg[node];
	}
	int mid = (x + y) >> 1;
	ll l = query(lo, hi, node * 2, x, mid);
	ll r = query(lo, hi, node * 2 + 1, mid + 1, y);
	return l + r;
}
int n;
int main()
{
	scanf("%d", &n);
	int x;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		idx[a[i]] = i;
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		ans += query(idx[x], n, 1, 1, n);
		update(idx[x], 1, 1, 1, n);
	}
	printf("%lld", ans);


	return 0;
}