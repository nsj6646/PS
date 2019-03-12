#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<tuple<int, pair<int, int>, int>> v(n);//ÀÎµ¦½º, ¸ö¹«°Ô, Å°, µî¼ö
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[i] = make_tuple(i, make_pair(x, y), 1);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((get<1>(v[i]).first < get<1>(v[j]).first) && (get<1>(v[i]).second < get<1>(v[j]).second)) {
				get<2>(v[i]) += 1;
			}
		}
	}
	for (auto &x : v) {
		cout << get<2>(x) << ' ';
	}
	return 0;
}
//#include <iostream>
//#include <vector>
//#include <tuple>
//#include <algorithm>
//using namespace std;
//
//bool cmp(const tuple<int, pair<int, int>, int> &u, const tuple<int, pair<int, int>, int> &v) {
//	return get<1>(u) > get<1>(v);
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<tuple<int, pair<int, int>, int>> v(n);//ÀÎµ¦½º, ¸ö¹«°Ô, Å°, µî¼ö
//	for (int i = 0; i < n; i++) {
//		int x, y;
//		cin >> x >> y;
//		v[i] = make_tuple(i, make_pair(x, y), 0);
//	}
//	sort(v.begin(), v.end(),cmp);
//	//for (auto &x : v) {
//	//	cout << get<1>(x).first << ' ' << get<1>(x).second << '\n';
//	//}
//	int rank = 1;
//	get<2>(v[0]) = rank;
//	for (int i = 1; i < n; i++) {
//		if ((get<1>(v[i-1]).first>get<1>(v[i]).first)&&(get<1>(v[i-1]).second > get<1>(v[i]).second)) {
//			rank = i + 1;
//			get<2>(v[i]) = rank;
//		}
//		else {
//			get<2>(v[i]) = rank;
//		}
//	}
//	sort(v.begin(), v.end());
//	for (auto &x : v) {
//		cout << get<2>(x) << ' ';
//	}
//	return 0;
//}