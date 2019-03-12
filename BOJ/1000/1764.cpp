//#include <iostream>
//#include <string>
//#include <map>
//#include <set>
//using namespace std;
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	int n, m;
//	cin >> n >> m;
//
//	string name;
//	map<string, int> d;
//	set<string> s;
//	int cnt = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> name;
//		d[name] = 1;
//	}
//	for (int i = 0; i < m; i++) {
//		cin >> name;
//		if (d.count(name)) {
//			s.insert(name);
//			cnt += 1;
//		}
//	}
//	cout << cnt << '\n';
//	for (string str : s) {
//		cout << str << '\n';
//	}
//	return 0;
//}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(m);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<string> ans;
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(ans));
	cout << ans.size() << '\n';
	for (auto &name : ans) {
		cout << name << '\n';
	}

	return 0;
}