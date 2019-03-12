//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int N;
//	cin >> N;
//	vector<pair<int, string>> v(N);
//	for (int i = 0; i < N; i++) {
//		int age;
//		string name;
//		cin >> age >> name;
//		v[i] = make_pair(age, name);
//	}
//	stable_sort(v.begin(), v.end(), [](pair<int, string> u, pair<int, string> v) {
//		return u.first < v.first;
//	});
//	for (auto &x : v) {
//		cout << x.first << ' ' << x.second << '\n';
//	}
//	return 0;
//}

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Person {
	int age;
	string name;
};
bool cmp(const Person &u, const Person &v) {
	return u.age < v.age;
}
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<Person> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].age >> a[i].name;
	}

	stable_sort(a.begin(), a.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << a[i].age << ' ' << a[i].name << '\n';
	}

	return 0;
}