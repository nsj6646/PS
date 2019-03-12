#include <cstdio>
#include <cstring>
const int N = 1e5 + 5;

int seg[N*8];
int idx[N];
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

int query(int lo, int hi, int node, int x, int y) {
	if (y<lo || x>hi) return 0;
	if (lo <= x && y <= hi) return seg[node];
	
	int mid = (x + y) >> 1;
	int l = query(lo, hi, node * 2, x, mid);
	int r = query(lo, hi, node * 2 + 1, mid + 1, y);
	return l + r;
}

void init() {
	memset(seg, 0, sizeof(seg));
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		init();
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			idx[i] = i+m;
			if (i == 1) {
				update(i+m, 0, 1, 1, n+m);
				continue;
			}
			update(i+m, 1, 1, 1, n+m);
		}
		int top = 1;
		for (int q = 1; q <= m; ++q) {
			int x;
			scanf("%d", &x);
			printf("%d ", query(idx[top], idx[x], 1, 1, n+m));
			
			update(idx[top], 1, 1, 1, n+m);
			update(idx[x], 0, 1, 1, n + m);
			idx[x] = idx[top]-1;
			top = x;		
		}
		printf("\n");
	}
	return 0;
}