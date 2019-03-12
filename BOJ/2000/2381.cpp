//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;
//
//typedef struct Point {
//	int x, y;
//}point;
//point make_point(int x, int y) {
//	point ret;
//	ret.x = x;
//	ret.y = y;
//	return ret;
//}
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//	int n;
//	cin >> n;
//	vector<point> v(n);
//	for (int i = 0; i < n; i++) {
//		int x, y;
//		cin >> x >> y;
//		v[i] = make_point(x, y);
//	}
//	int ans = 0;
//	for (int i = 0; i < n-1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			ans = max(ans, abs(v[i].x - v[j].x) + abs(v[i].y - v[j].y));
//		}
//	}
//	cout << ans;
//	return 0;
//}
#include<algorithm>
#include<cstdio>
using namespace std;
int n, res;
int maxp = -2000000, maxm = -2000000, minp = 2000000, minm = 2000000;
int main()
{
	scanf("%d", &n);
	while (n--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		maxp = max(maxp, a + b);
		minp = min(minp, a + b);
		maxm = max(maxm, a - b);
		minm = min(minm, a - b);
	}
	int res = 0;
	res = max(maxp - minp, maxm - minm);
	printf("%d\n", res);
}