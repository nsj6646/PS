#define N		100001
#include <cstdio>
const int INF = 1e9 + 1;
int a[N];
int seg[N * 4];
int n,m;

void update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y) return;
	if (x == y) {
		a[pos] = val;
		seg[node] = pos;
		return;
	}
	int mid = (x + y) >> 1;
	update(pos, val, node << 1, x, mid);
	update(pos, val, (node << 1) + 1, mid + 1, y);
	seg[node] = a[seg[node << 1]] <= a[seg[(node << 1) + 1]] ? seg[node << 1] : seg[(node << 1) + 1];
}

int query(int lo, int hi, int node, int x, int y) {
	if (lo > y || hi < x) return 0;
	if (lo <= x && y <= hi) {
		return seg[node];
	}
	int mid = (x + y) >> 1;
	int l = query(lo, hi, node << 1, x, mid);
	int r = query(lo, hi, (node << 1) + 1, mid + 1, y);
	return a[l] <= a[r] ? l : r;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",a + i);
		update(i, a[i], 1, 1, n);
	}
	scanf("%d", &m);
	for (int q = 1; q <= m; ++q) {
		int t, i, v;
		scanf("%d", &t);
		if (t - 1) {
			printf("%d\n", query(1, n, 1, 1, n));
		}
		else {
			scanf("%d %d", &i, &v);
			update(i, v, 1, 1, n);
		}
	}
	return 0;
}