#define N		100001
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int a[N];
vector<int> bucket[317];

int n, m;
int sz;
void init() {
	sz = sqrt(n);
	for (int i = 0; i < n; ++i) {
		bucket[i / sz].push_back(a[i]);
	}
	for (int i = 0; i < n / sz + 1; ++i) {
		sort(bucket[i].begin(), bucket[i].end());
	}
}
void update(int pos, int val) {
	auto it = lower_bound(bucket[pos / sz].begin(), bucket[pos / sz].end(), a[pos]);
	a[pos] = val;
	*it = val;
	sort(bucket[pos / sz].begin(), bucket[pos / sz].end());
}

int query(int lo, int hi, int k) {
	int ret = 0;
	while (lo%sz&&lo <= hi) {
		if (a[lo++] > k) {
			++ret;
		}
	}
	while ((hi + 1) % sz&&lo <= hi) {
		if (a[hi--] > k) {
			++ret;
		}
	}
	while (lo <= hi) {
		ret += bucket[lo / sz].end() - upper_bound(bucket[lo / sz].begin(), bucket[lo / sz].end(), k);
		lo += sz;
	}
	return ret;
}


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	init();
	scanf("%d", &m);
	for (int q = 1; q <= m; ++q) {
		int a, i, j, k;
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d %d %d", &i, &j, &k);
			printf("%d\n", query(i - 1, j - 1, k));
		}
		else {
			scanf("%d %d", &i, &k);
			update(i - 1, k);
		}
	}
	return 0;
}