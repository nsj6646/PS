#define N		100001
#define INF		1000000000
#define MAX(X,Y)	(X)>(Y)?(X):(Y)
#include <cstdio>
#include <cstring>
using namespace	std;

typedef long long ll;
ll ans;

int n;
ll a[N];
int seg[N * 4];


void init(int node, int x, int y) {
	if (x == y) {
		seg[node] = x;
		return;
	}
	int mid = (x + y) >> 1;
	init(node << 1, x, mid);
	init((node << 1) + 1, mid + 1, y);

	seg[node] = a[seg[node << 1]] <= a[seg[(node << 1) + 1]] ? seg[node << 1] : seg[(node << 1) + 1];
}

int query(int lo, int hi, int node, int x, int y) {
	if (y<lo || x>hi) return INF;
	if (lo <= x && y <= hi) {
		return seg[node];
	}
	int mid = (x + y) >> 1;
	int l = query(lo, hi, node << 1, x, mid);
	int r = query(lo, hi, (node << 1) + 1, mid + 1, y);
	
	if (l == INF) {
		return r;
	}
	else if (r == INF) {
		return l;
	}
	else {
		if (a[l] <= a[r]) {
			return l;
		}
		else {
			return r;
		}
	}
}

ll largest(int x,int y) {
	if (x > y) {
		return 0;
	}
	int mid = query(x, y, 1, 1, n);
	ll area = (y - x + 1)*a[mid];
	ll left=largest(x, mid - 1);
	area = MAX(area, left);
	ll right = largest(mid +1, y);
	area = MAX(area, right);
	return area;
}
int main()
{
	while ((scanf("%d", &n)) && n) {
		memset(seg, 0, sizeof(seg));
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			
		}
		init(1, 1, n);
		printf("%lld\n", largest(1, n));
	}

	return 0;
}



//#include <iostream>
//#include <vector>
//#include <stack>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//	int n;
//	while (true) {
//		cin >> n;
//		if (n == 0) {
//			break;
//		}
//		vector<long long> v(n);
//		for (int i = 0; i < n; i++) {
//			cin >> v[i];
//		}
//		
//		stack<long long> s;
//		long long ans = v[0];
//		s.push(0);
//		for (int i = 1; i < n; i++) {
//			if (v[i] >= v[s.top()]) {
//				s.push(i);
//			}
//			else {
//				while (!s.empty() && v[s.top()] > v[i]) {
//					long long height = v[s.top()];
//					s.pop();
//					long long width = i;
//					if (!s.empty()) {
//						width = i - s.top() - 1;
//					}
//					ans = max(ans, height*width);
//				}
//				s.push(i);
//			}
//		}
//		while (!s.empty()) {
//			long long height = v[s.top()];
//			s.pop();
//			long long width = n;
//			if (!s.empty()) {
//				width = n - s.top() - 1;
//			}
//			ans = max(ans, height*width);
//		}
//		cout << ans << '\n';
//	}
//
//	return 0;
//}
//
////#include <cstdio>
////#include <stack>
////using namespace std;
////long long a[100000];
////int main() {
////	while (true) {
////		int n;
////		scanf("%d", &n);
////		if (n == 0) break;
////		for (int i = 0; i<n; i++) {
////			scanf("%lld", &a[i]);
////		}
////		stack<long long> s;
////		long long ans = 0;
////		for (int i = 0; i<n; i++) {
////			int left = i;
////			while (!s.empty() && a[s.top()] > a[i]) {
////				long long height = a[s.top()];
////				s.pop();
////				long long width = i;
////				if (!s.empty()) {
////					width = (i - s.top() - 1);
////				}
////				if (ans < width*height) {
////					ans = width * height;
////				}
////			}
////			s.push(i);
////		}
////		while (!s.empty()) {
////			long long height = a[s.top()];
////			s.pop();
////			long long width = n;
////			if (!s.empty()) {
////				width = n - s.top() - 1;
////			}
////			if (ans < width*height) {
////				ans = width * height;
////			}
////		}
////
////		printf("%lld\n", ans);
////	}
////	return 0;
////}