#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> point;

int dist(point p1, point p2) {
	return (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
}

bool cmp(const point &u, const point &v) {
	return u.second < v.second;
}
int merge(vector<point> &v,int start, int end) {
	int n = end - start + 1;
	if (n <= 3) {
		int ans = -1;
		for (int i = start; i < end; i++) {
			for (int j = i + 1; j <= end; j++) {
				int d = dist(v[i], v[j]);
				if (ans == -1 || d < ans) {
					ans = d;
				}
			}
		}
		return ans;
	}
	int mid = (start + end) / 2;
	int left = merge(v, start, mid);
	int right = merge(v, mid + 1, end);
	
	int ans = min(left, right);

	vector<point> nv;

	for (int i = start; i < end; i++) {
		int x = v[i].first - v[mid].first;
		if (x*x < ans) {
			nv.push_back(v[i]);
		}
	}
	sort(nv.begin(), nv.end(), cmp);
	int m = nv.size();
	for (int i = 0; i < m - 1; i++) {
		for (int j = i + 1; j < m; j++) {
			int y = nv[i].second - nv[j].second;
			if (y*y < ans) {
				int d = dist(nv[i], nv[j]);
				if (d < ans) {
					ans = d;
				}
			}
			else {
				break;
			}
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<point> v(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[i] = { x,y };
	}
	sort(v.begin(), v.end());

	cout<<merge(v, 0, n - 1);


	return 0;
}

//#include <cstdio>
//#include <vector>
//#include <set>
//#include <algorithm>
//using namespace std;
//struct Point {
//	int x, y;
//	Point() {
//	}
//	Point(int x, int y) : x(x), y(y) {
//	}
//	bool operator < (const Point &v) const {
//		if (x == v.x) {
//			return y < v.y;
//		}
//		else {
//			return x < v.x;
//		}
//	}
//};
//bool cmp(const Point &u, const Point &v) {
//	return u.y < v.y;
//}
//int dist(Point p1, Point p2) {
//	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
//}
//int brute_force(vector<Point> &a, int x, int y) {
//	int ans = -1;
//	for (int i = x; i <= y - 1; i++) {
//		for (int j = i + 1; j <= y; j++) {
//			int d = dist(a[i], a[j]);
//			if (ans == -1 || ans > d) {
//				ans = d;
//			}
//		}
//	}
//	return ans;
//}
//int closest(vector<Point> &a, int x, int y) {
//	int n = y - x + 1;
//	if (n <= 3) {
//		return brute_force(a, x, y);
//	}
//	int mid = (x + y) / 2;
//	int left = closest(a, x, mid);
//	int right = closest(a, mid + 1, y);
//	int ans = min(left, right);
//	vector<Point> b;
//	for (int i = x; i <= y; i++) {
//		int d = a[i].x - a[mid].x;
//		if (d*d < ans) {
//			b.push_back(a[i]);
//		}
//	}
//	sort(b.begin(), b.end(), cmp);
//	int m = b.size();
//	for (int i = 0; i<m - 1; i++) {
//		for (int j = i + 1; j<m; j++) {
//			int y = b[j].y - b[i].y;
//			if (y*y < ans) {
//				int d = dist(b[i], b[j]);
//				if (d < ans) {
//					ans = d;
//				}
//			}
//			else {
//				break;
//			}
//		}
//	}
//	return ans;
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	vector<Point> a(n);
//	for (int i = 0; i<n; i++) {
//		scanf("%d %d", &a[i].x, &a[i].y);
//	}
//	sort(a.begin(), a.end());
//	printf("%d\n", closest(a, 0, n - 1));
//	return 0;
//}