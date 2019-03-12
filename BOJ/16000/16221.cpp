#define N		1000000
#include <iostream>
#include <queue>
using namespace std;

int a[N + 1] = { 1 };
int seg[N * 4];
int n, t, k;

priority_queue<int> pq;

void update(int pos, int val,int node, int x, int y) {
	if (pos<x || pos>y) return;
	if (x == y) {
		seg[node] += val;
		return;
	}
	int mid = (x + y) >> 1;
	update(pos, val,node << 1, x, mid);
	update(pos, val,(node << 1) + 1, mid + 1, y);
	seg[node] = seg[node << 1]+ seg[(node << 1) + 1];
}
int query(int lo, int hi, int node, int x, int y) {
	if (lo > y || hi < x) return 0;
	if (lo <= x && y <= hi) {
		return seg[node];
	}
	int mid = (x + y) >> 1;
	int l=query(lo,hi, node << 1, x, mid);
	int r=query(lo,hi, (node << 1) + 1, mid + 1, y);
	return l+r;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> t >> k;
		if (t - 1) {
			update(k, -1, 1, 1, N);
			--a[k];
			if (a[k] == 0) {
				pq.push(-k);
			}
		}
		else {
			update(k, 1, 1, 1, N);
			pq.push(-k + 1);
			++a[k];
		}

		int h = N;
		while (!pq.empty()) {
			h = -pq.top();
			if (a[h] > 0) {
				h = N;
				pq.pop();
			}
			else {
				break;
			}
		}
		cout << query(1, h, 1, 1, N) << '\n';

	}
	return 0;
}