#define N		1000005
#include <cstdio>

typedef long long ll;

ll n, m, k,A[N], seg[N * 4];


void update(ll pos, ll val, ll node, ll x, ll y) {
	if (pos<x || pos>y) return;
	if (x == y) {
		seg[node] = val;
		return;
	}
	ll mid = (x + y) >> 1;
	update(pos, val, node * 2, x, mid);
	update(pos, val, node * 2 + 1, mid + 1, y);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query(ll lo, ll hi, ll node, ll x, ll y) {
	if (y<lo || x>hi) return 0;
	if (lo <= x && y <= hi) {
		return seg[node];
	}
	ll mid = (x + y) >> 1;
	ll l = query(lo, hi, node * 2, x, mid);
	ll r = query(lo, hi, node * 2 + 1, mid + 1, y);
	return l + r;
}


int main()
{
	scanf("%lld %lld %lld" , &n, &m,&k);

	for (int i = 1; i <= n; ++i) {
		scanf("%lld", A + i);
		update(i, A[i], 1, 1, n);
	}
	for (int q = 1; q <= m+k; ++q) {
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {
			update(b, c, 1, 1, n);
		}
		if (a == 2) {
			printf("%lld\n", query(b, c, 1, 1, n));
		}
	}

	return 0;
}