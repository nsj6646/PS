#define N		1000001
#include <cstdio>


int n;

int seg[N * 4];

void update(int pos, int val, int node, int x, int y) {
	if (pos < x || pos>y) return;
	if (x == y) {
		seg[node] += val;
		return;
	}
	int mid = (x + y) >> 1;
	update(pos, val, node << 1, x, mid);
	update(pos, val, (node << 1) + 1, mid + 1, y);
	seg[node] = seg[node << 1] + seg[(node << 1) + 1];
}

int query(int lo, int hi, int node, int x, int y) {
	if (y<lo || x>hi) return 0;
	if (lo <= x && y <= hi) {
		return seg[node];
	}
	int mid = (x + y) >> 1;
	int l = query(lo, hi, node << 1, x, mid);
	int r = query(lo, hi, (node << 1) + 1, mid + 1, y);
	return l + r;
}

int main()
{
	scanf("%d", &n);
	for (int q = 1; q <= n; ++q) {
		int a, b, c;
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d", &b);
			int left = 1, right = N, mid;
			while (left <= right) {
				mid = (left + right) >> 1;
				int temp = query(1, mid, 1, 1, N);
				if (temp >= b) {
					right = mid-1;
				}
				else {
					left = mid + 1;
				}
			}
			printf("%d\n", left);
			update(left, -1, 1, 1, N);
		}
		else {
			scanf("%d %d", &b, &c);
			update(b, c, 1, 1, N);
		}
	}
	return 0;
}