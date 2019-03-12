//#include <bits/stdc++.h>
//using namespace std;
//
//set<pair<int, int>> s;
//set<int> dist;
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//
//	srand(time(0));
//	s.insert({ -8140,-8140 });
//	s.insert({ 8140,8140 });
//	for (int i = 0; i < 812; ++i) {
//		int x = rand() % 16281 - 8140;
//		int y = rand() % 16281 - 8140;
//		if (s.count({ x,y }) == 0) {
//			for (auto &p : s) {
//				int k = (p.first - x)*(p.first - x) + (p.second - y)*(p.second - y);
//				if (dist.count(k) == 0) {
//					s.insert({ x,y });
//
//				}
//			}
//		}
//
//	}
//	for (auto &p : s) {
//		cout << p.first << ' ' << p.second << '\n';
//	}
//	return 0;
//}