#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int kor, eng, math;
string name;

int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	//vector<tuple<int, int, int, string>> v(N);
	vector<pair<pair<int, int>, pair<int, string>>> v(N);
	for (int i = 0; i < N; i++) {
		cin >> name >> kor >> eng >> math;
		v[i]=make_pair(make_pair(-kor, eng),make_pair( -math, name));
	}
	sort(v.begin(), v.end());
	for (auto &x : v) {
		cout << x.second.second<< '\n';
	}
	return 0;
}
//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <vector>
//#include <tuple>
//using namespace std;
//struct Person {
//	string name;
//	int kor, eng, math;
//};
//bool cmp(const Person &u, const Person &v) {
//	return make_tuple(-u.kor, u.eng, -u.math, u.name) < make_tuple(-v.kor, v.eng, -v.math, v.name);
//}
//int main() {
//	int n;
//	cin >> n;
//
//	vector<Person> a(n);
//	for (int i = 0; i<n; i++) {
//		cin >> a[i].name >> a[i].kor >> a[i].eng >> a[i].math;
//	}
//
//	sort(a.begin(), a.end(), cmp);
//
//	for (int i = 0; i<n; i++) {
//		cout << a[i].name << '\n';
//	}
//
//	return 0;
//}