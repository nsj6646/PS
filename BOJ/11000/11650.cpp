#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<pair<int, int>> v;
	while (N--) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	for (auto &x : v) {
		cout << x.first << ' ' << x.second << '\n';
	}
	return 0;
}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int N;
//	scanf("%d", &N);
//	vector<pair<int, int>> v(N);
//	for (int i = 0; i < N; i++) {
//		scanf("%d %d", &v[i].first, &v[i].second);
//	}
//	sort(v.begin(), v.end());
//	for (int i = 0; i < v.size();i++) {
//		printf("%d %d\n", v[i].first, v[i].second);
//	}
//	return 0;
//}