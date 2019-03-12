#include <iostream>
#include <vector>
using namespace std;

void go(vector<int> &v, vector<int> &lotto, int i, int cnt) {
	if (cnt == 6) {
		for (int x : lotto) {
			cout << x << ' ';
		}
		cout << '\n';
		return;
	}
	if (i == v.size()) {
		return;
	}
	lotto.push_back(v[i]);
	go(v, lotto, i + 1, cnt+1);
	lotto.pop_back();
	go(v, lotto, i + 1, cnt);

}
int main()
{
	while (true) {
		int k;
		cin >> k;
		if (k == 0) {
			break;
		}
		vector<int> v(k);
		for (int i = 0; i < k; i++) {
			cin >> v[i];
		}
		vector<int> s;
		go(v, s, 0, 0);
		cout << '\n';
	}
	return 0;
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//	
//	while (true) {
//		int k;
//		cin >> k;
//		if (k == 0) break;
//		vector<int> c(k);
//		vector<int> nums(k);
//		for (int i = 0; i < k; i++) {
//			cin >> nums[i];
//			if (i < 6) {
//				c[i] = 0;;
//			}
//			else {
//				c[i] = 1;
//			}
//		}
//		do {	
//			for (int i = 0; i < k; i++) {
//				if (c[i] == 0) {
//					cout << nums[i] << ' ';
//				}
//			}
//			cout << '\n';
//		} while (next_permutation(c.begin(), c.end()));
//		cout << '\n';
//	}
//	return 0;
//}
//
////#include <iostream>
////#include <algorithm>
////#include <vector>
////using namespace std;
////int main() {
////	while (true) {
////		int n;
////		cin >> n;
////		if (n == 0) {
////			break;
////		}
////		vector<int> a(n);
////		for (int i = 0; i<n; i++) {
////			cin >> a[i];
////		}
////		vector<int> d;
////		for (int i = 0; i<n - 6; i++) {
////			d.push_back(0);
////		}
////		for (int i = 0; i<6; i++) {
////			d.push_back(1);
////		}
////		vector<vector<int>> ans;
////		do {
////			vector<int> current;
////			for (int i = 0; i<n; i++) {
////				if (d[i] == 1) {
////					current.push_back(a[i]);
////				}
////			}
////			ans.push_back(current);
////		} while (next_permutation(d.begin(), d.end()));
////		sort(ans.begin(), ans.end());
////		for (auto &v : ans) {
////			for (int i = 0; i<v.size(); i++) {
////				cout << v[i] << ' ';
////			}
////			cout << '\n';
////		}
////		cout << '\n';
////	}
////	return 0;
////}


//#include<iostream>
//#include<algorithm>
//#include<string>
//using namespace std;
//
//int k;
//int arr[13];
//void dfs(int loc, int cnt, string s);
//
//int main() {
//	while (1) {
//		cin >> k;
//		if (k == 0)
//			return 0;
//		for (int i = 0; i < k; i++) {
//			cin >> arr[i];
//		}
//
//		dfs(0, 0, "");
//		cout << "\n";
//	}
//
//	return 0;
//}
//void dfs(int loc, int cnt, string s) {
//	if (cnt == 6) {
//		cout << s << "\n";
//		return;
//	}
//	if (loc == k)
//		return;
//
//	dfs(loc + 1, cnt + 1, s + to_string(arr[loc]) + " ");
//	dfs(loc + 1, cnt, s);
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//vector<int> lotto;
//void solve(vector<int> &a, int index, int cnt) {
//	if (cnt == 6) {
//		for (int num : lotto) {
//			printf("%d ", num);
//		}
//		printf("\n");
//		return;
//	}
//	int n = a.size();
//	if (n == index) return;
//	lotto.push_back(a[index]);
//	solve(a, index + 1, cnt + 1);
//	lotto.pop_back();
//	solve(a, index + 1, cnt);
//}
//int main() {
//	while (true) {
//		int n;
//		cin >> n;
//		if (n == 0) break;
//		vector<int> a(n);
//		for (int i = 0; i<n; i++) {
//			cin >> a[i];
//		}
//		solve(a, 0, 0);
//		cout << '\n';
//	}
//	return 0;
//}