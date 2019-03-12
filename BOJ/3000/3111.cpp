#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string a, t;
	cin >> a >> t;
	string b = a;
	reverse(b.begin(), b.end());
	int n = a.size();

	string ls, rs;
	int left =0,right = t.size();
	bool flag = true;
	while (left < right) {
		if (flag) {
			ls.push_back(t[left++]);
			if (ls.size() >= n) {
				if (ls.substr(ls.size() - n, n) == a) {
					for (int i = 0; i < n; i++) {
						ls.pop_back();
					}
					flag = !flag;
				}
			}
		}
		else {
			rs.push_back(t[--right]);
			if (rs.size() >= n) {
				if (rs.substr(rs.size() - n, n) == b) {
					for (int i = 0; i < n; i++) {
						rs.pop_back();
					}
					flag = !flag;
				}
			}
		}
	}
	while (!ls.empty()) {
		rs.push_back(ls.back());
		ls.pop_back();
		if (rs.size() >= n) {
			if (rs.substr(rs.size() - n, n) == b) {
				for (int i = 0; i < n; i++) {
					rs.pop_back();
				}
			}
		}
	}
	reverse(rs.begin(), rs.end());
	cout << rs;
	return 0;
}
//#include <iostream>
//#include <string>
//#include <deque>
//#include <stack>
//#include <algorithm>
//using namespace std;
//
////bool Lcheck(const string &a, int n, string &t, int &l) {
////	cout << t.substr(l, n) << '\n';
////	if (t.substr(l, n) == a) {
////		l += n;
////		return true;
////	}
////	else {
////		return false;
////	}
////}
////bool Rcheck(const string &a, int n, string &t, int &r) {
////	cout << t.substr(r - n + 1, r) << '\n';
////	if (t.substr(r - n + 1, r) == a) {
////		r -= n;
////		return true;
////	}
////	else {
////		return false;
////	}
////}
//int main()
//{
//	string a,t;
//	cin >> a >> t;
//
//	
//	//deque<char> d;
//
//	//for (char c : t) {
//	//	d.push_back(c);
//	//}
//
//	//string b(a);
//	//reverse(b.begin(), b.end());
//
//	//
//	//int n = a.length();
//	//string l, r;
//	//int left = 0, right = t.length() - 1;
//	//stack<char> ls, rs;
//
//	//for (int i = 0; i < n; i++) {
//	//	l.push_back(d.front());
//	//	d.pop_front();
//	//	r.push_back(d.back());
//	//	d.pop_back();
//	//}
//	//while (!d.empty()) {
//	//	if (l.size() < n) {
//	//		l.push_back(d.front());
//	//		d.pop_front();
//	//		continue;
//	//	}
//	//	else {
//	//		if (l == a) {
//	//			l.clear();
//	//		}
//	//		else {
//	//			ls.push(l[0]);
//	//			l.erase(0, 1);
//	//		}
//	//	}
//	//}
//
//
//
//
//	//while (left <= right) {
//	//	while (t.substr(left, n) == a) {
//	//		ls.push(t[left++]);
//	//	}
//	//}
//	//while (left + n <= right) {
//	//	while ((!Lcheck(a, n, t, left)) && (left + n <= right)) {
//	//		ls.push(t[left++]);
//	//	}
//	//	while ((!Rcheck(a, n, t, right)) && (left + n <= right)) {
//	//		rs.push(t[right--]);
//	//	}
//	//}
//
//	//while (!ls.empty()) {
//	//	rs.push(ls.top());
//	//	ls.pop();
//	//}
//	//while (!rs.empty()) {
//	//	cout << rs.top();
//	//	rs.pop();
//	//}
//
//	return 0;
//}