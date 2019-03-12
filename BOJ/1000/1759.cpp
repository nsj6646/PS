#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int l, c;
char a[15];
char mo[] = "aeiou";
vector<char> v;
void dfs(int idx, int cnt,int m,int j) {
	if (cnt == l) {
		if (m >= 1 && j >= 2) {
			for (char x : v) {
				cout << x;
			}
			cout << '\n';
		}
		return;
	}
	for (int i = idx; i < c; i++) {
		v.push_back(a[i]);
		bool ismoin = false;
		for (int k = 0; k < 5; k++) {
			if (a[i] == mo[k]) {
				ismoin = true;
				break;
			}
		}
		if (ismoin) {
			dfs(i + 1, cnt + 1, m + 1, j);
		}
		else {
			dfs(i + 1, cnt + 1, m, j+1);
		}
		v.pop_back();
		
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> a[i];
	}
	sort(a, a + c);
	dfs(0, 0,0,0);
	return 0;
}
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//bool check(string &password) {
//	int ja = 0;
//	int mo = 0;
//	for (char x : password) {
//		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
//			mo += 1;
//		}
//		else {
//			ja += 1;
//		}
//	}
//	return mo >= 1 && ja >= 2;
//}
//void go(int n, vector<char> &alpha, string password, int i) {
//	if (password.size() == n) {
//		if (check(password)) {
//			cout << password << '\n';
//		}
//		return;
//	}
//	if (i == alpha.size()) {
//		return;
//	}
//	go(n, alpha, password + alpha[i], i + 1);
//	go(n, alpha, password, i + 1);
//}
//int main()
//{
//	int l, c;
//	cin >> l >> c;
//	vector<char> a(c);
//	for (int i = 0; i < c; i++) {
//		cin >> a[i];
//	}
//	sort(a.begin(), a.end());
//
//	go(l, a, "", 0);
//	return 0;
//}
//
////#include <iostream>
////#include <algorithm>
////#include <vector>
////using namespace std;
////
////char vowel[5] = { 'a','e','i','o','u' };
////bool isvowel(char c) {
////	for (char x : vowel) {
////		if (c == x) {
////			return true;
////		}
////	}
////	return false;
////}
////int main()
////{
////	ios_base::sync_with_stdio(false);
////
////	int l, c;
////	cin >> l >> c;
////	vector<char> v(c);
////	for (int i = 0; i < c; i++) {
////		cin >> v[i];
////	}
////	sort(v.begin(), v.end());
////	vector<int> combi(c);
////	for (int i = c - 1; i >= l; i--) {
////		combi[i] = 1;
////	}
////	do {
////		char buf[15];
////		int idx = 0;
////		int vow = 0, cons = 0;
////		for (int i = 0; i < c; i++) {
////			if (combi[i] == 0) {
////				if (isvowel(v[i])) {
////					vow += 1;
////				}
////				else {
////					cons += 1;
////				}
////				buf[idx++] = v[i];
////			}
////		}
////		if (vow >= 1 && cons >= 2) {
////			buf[idx] = '\0';
////			cout << buf << '\n';
////		}
////	} while (next_permutation(combi.begin(), combi.end()));
////	return 0;
////}
//
//
////#include <iostream>
////#include <string>
////#include <algorithm>
////#include <vector>
////
////using namespace std;
////
////int L, C, CO, VO;
////char VO2[5] = { 'a','e','i','o','u' };
////vector<char> answer;
////
////bool isvowel(char c);
////void search(vector<char> &v, int s, int cnt);
////
////int main() {
////
////	vector<char> v;
////
////	cin >> L >> C;
////
////	for (int i = 0; i < C; i++) {
////		char T;
////		cin >> T;
////		v.push_back(T);
////	}
////	sort(v.begin(), v.end());
////	search(v, 0, 0);
////
////	return 0;
////}
////
////void search(vector<char> &v, int s, int cnt) {
////	if (L == cnt) {
////		if (CO >= 2 && VO >= 1) {
////			for (int i = 0; i < answer.size(); i++) {
////				cout << answer[i];
////			}
////			cout << '\n';
////		}
////		return;
////	}
////	else if (s == C)
////		return;
////
////	if (isvowel(v[s])) {
////		VO++;
////	}
////	else {
////		CO++;
////	}
////
////	answer.push_back(v[s]);
////	search(v, s + 1, cnt + 1);
////
////	char c2 = answer.back();
////	if (isvowel(c2)) {
////		VO--;
////	}
////	else {
////		CO--;
////	}
////
////	answer.pop_back();
////	search(v, s + 1, cnt);
////}
////
////bool isvowel(char c) {
////	for (char x : VO2) {
////		if (c == x) {
////			return true;
////		}
////	}
////	return false;
////}
//
////#include<iostream>
////#include<string>
////#include<algorithm>
////using namespace std;
////
////void dfs(int loc, int cnt, int m, int j, string s);
////int L, C;
////char arr[15];
////
////int main() {
////	cin >> L >> C;
////	for (int i = 0; i < C; i++) {
////		cin >> arr[i];
////	}
////	sort(arr, arr + C);
////	dfs(0, 0, 0, 0, "");
////	return 0;
////}
////
////void dfs(int loc, int cnt, int m, int j, string s) {
////	if (cnt == L) {
////		if (m >= 1 && j >= 2)
////			cout << s << "\n";
////		return;
////	}
////	if (loc == C)
////		return;
////	if (arr[loc] == 'a' || arr[loc] == 'e' || arr[loc] == 'i' || arr[loc] == 'o' || arr[loc] == 'u')
////		dfs(loc + 1, cnt + 1, m + 1, j, s + arr[loc]);
////	else
////		dfs(loc + 1, cnt + 1, m, j + 1, s + arr[loc]);
////	dfs(loc + 1, cnt, m, j, s);
////}