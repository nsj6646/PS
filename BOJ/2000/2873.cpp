#include <iostream>
#include <stack>
using namespace std;

int a[1000][1000];

int main()
{
	ios_base::sync_with_stdio(false);
	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}

	if (c % 2) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c - 1; j++) {
				if (i % 2 == 0) {
					cout << 'R';
				}
				else {
					cout << 'L';
				}
			}
			if (i < r - 1) {
				cout << 'D';
			}
		}
	}
	else if (r % 2) {
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < r - 1; j++) {
				if (i % 2 == 0) {
					cout << 'D';
				}
				else {
					cout << 'U';
				}
			}
			if (i < r - 1) {
				cout << 'R';
			}
		}
	}
	else {
		stack<char> s1, s2;
		pair<int, int> p = { 0,1 };
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if ((i + j) % 2 == 1) {
					if (a[i][j] < a[p.first][p.second]) {
						p = { i,j };
					}
				}
			}
		}

		pair<int, int> a = { 0,0 };
		pair<int, int> b = { r - 1,c - 1 };
		while (b.first - a.first > 1) {
			if (a.first / 2 < p.first / 2) {
				for (int i = 0; i < c - 1; i++) {
					s1.push('R');
				}
				s1.push('D');
				for (int i = 0; i < c - 1; i++) {
					s1.push('L');
				}
				s1.push('D');
				a.first += 2;
			}
			if (p.first / 2 < b.first / 2) {
				for (int i = 0; i < c - 1; i++) {
					s2.push('R');
				}
				s2.push('D');
				for (int i = 0; i < c - 1; i++) {
					s2.push('L');
				}
				s2.push('D');
				b.first -= 2;
			}
		}
		while (b.second - a.second > 1) {
			if (a.second / 2 < p.second / 2) {
				s1.push('D');
				s1.push('R');
				s1.push('U');
				s1.push('R');
				a.second += 2;
			}
			if (p.second / 2 < b.second / 2) {
				s2.push('D');
				s2.push('R');
				s2.push('U');
				s2.push('R');
				b.second -= 2;
			}
		}
		if (p.second == a.second) {
			s1.push('R');
			s1.push('D');
		}
		else {
			s1.push('D');
			s1.push('R');
		}
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		while (!s2.empty()) {
			cout << s2.top();
			s2.pop();
		}
	}

	return 0;
}

//#include <iostream>
//#include <algorithm>
//#include <string>
//using namespace std;
//int a[1000][1000];
//void append(string &s, char c, int cnt) {
//	for (int i = 0; i<cnt; i++) {
//		s += c;
//	}
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i<n; i++) {
//		for (int j = 0; j<m; j++) {
//			cin >> a[i][j];
//		}
//	}
//	string s = "";
//	if (n % 2 == 1) {
//		for (int i = 0; i<n; i++) {
//			if (i % 2 == 0) {
//				append(s, 'R', m - 1);
//				if (i != n - 1) {
//					append(s, 'D', 1);
//				}
//			}
//			else {
//				append(s, 'L', m - 1);
//				append(s, 'D', 1);
//			}
//		}
//	}
//	else if (m % 2 == 1) {
//		for (int j = 0; j<m; j++) {
//			if (j % 2 == 0) {
//				append(s, 'D', n - 1);
//				if (j != m - 1) {
//					append(s, 'R', 1);
//				}
//			}
//			else {
//				append(s, 'U', n - 1);
//				append(s, 'R', 1);
//			}
//		}
//	}
//	else {
//		int x, y;
//		x = 0;
//		y = 1;
//		for (int i = 0; i<n; i++) {
//			for (int j = 0; j<m; j++) {
//				if ((i + j) % 2 == 1) {
//					if (a[x][y] > a[i][j]) {
//						x = i;
//						y = j;
//					}
//				}
//			}
//		}
//		int x1 = 0;
//		int y1 = 0;
//		int x2 = n - 1;
//		int y2 = m - 1;
//		string s2 = "";
//		while (x2 - x1 > 1) {
//			if (x1 / 2 < x / 2) {
//				append(s, 'R', m - 1);
//				append(s, 'D', 1);
//				append(s, 'L', m - 1);
//				append(s, 'D', 1);
//				x1 += 2;
//			}
//			if (x / 2 < x2 / 2) {
//				append(s2, 'R', m - 1);
//				append(s2, 'D', 1);
//				append(s2, 'L', m - 1);
//				append(s2, 'D', 1);
//				x2 -= 2;
//			}
//		}
//		while (y2 - y1 > 1) {
//			if (y1 / 2 < y / 2) {
//				append(s, 'D', 1);
//				append(s, 'R', 1);
//				append(s, 'U', 1);
//				append(s, 'R', 1);
//				y1 += 2;
//			}
//			if (y / 2 < y2 / 2) {
//				append(s2, 'D', 1);
//				append(s2, 'R', 1);
//				append(s2, 'U', 1);
//				append(s2, 'R', 1);
//				y2 -= 2;
//			}
//		}
//		if (y == y1) {
//			append(s, 'R', 1);
//			append(s, 'D', 1);
//		}
//		else {
//			append(s, 'D', 1);
//			append(s, 'R', 1);
//		}
//		reverse(s2.begin(), s2.end());
//		s += s2;
//	}
//	cout << s << '\n';
//	return 0;
//}