#define N		100005
#define M_MAX	1000000001
#define MIN(X,Y)	(X)<(Y)?(X):(Y)

#include <cstdio>


int n, m, a[N], seg[N * 4];


void update(int pos, int val, int node, int left, int right) {
	if (pos<left || pos>right) return;
	if (left == right) {
		seg[node] = val;
		return;
	}
	int mid = (left + right) >> 1;
	update(pos, val, node * 2, left, mid);
	update(pos, val, node * 2 + 1, mid + 1, right);
	seg[node] = MIN(seg[node * 2], seg[node * 2 + 1]);
}

int query(int low, int high, int node, int left, int right) {
	if (right<low || left>high) return M_MAX;
	if (low <= left && right <= high) {
		return seg[node];
	}
	int mid = (left + right) >> 1;
	int l = query(low, high, node * 2, left, mid);
	int r = query(low, high, node * 2 + 1, mid + 1, right);
	return MIN(l, r);
}


int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		update(i, a[i], 1, 1, n);
	}
	for (int q = 1; q <= m; ++q) {
		int low, high;
		scanf("%d %d", &low, &high);
		printf("%d\n", query(low, high, 1, 1, n));
	}


	return 0;
}