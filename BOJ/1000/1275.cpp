#define N		100000
#include <cstdio>

typedef long long ll;
int n, q;
ll seg[N * 4];
void update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y) return;
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
	if (y<lo || x >hi) return 0;
	if (lo <= x && y <= hi) return seg[node];
	int mid = (x + y) >> 1;
	ll l = query(lo, hi, node * 2, x, mid);
	ll r = query(lo, hi, node * 2 + 1, mid + 1, y);
	return l + r;
}
int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		update(i, x, 1, 1, n);
	}
	for (int i = 1; i <= q; ++i) {
		int x, y, a, b;
		scanf("%d %d %d %d", &x, &y, &a, &b);

		printf("%lld\n", x > y ? query(y, x, 1, 1, n) : query(x, y, 1, 1, n));
		update(a, b, 1, 1, n);
	}
	return 0;
}