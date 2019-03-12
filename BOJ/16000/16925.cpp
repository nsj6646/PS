#include <bits/stdc++.h>
using namespace std;

struct word {
	int idx;
	string str;
	char type;
	word(int a,string b,char c) :idx(a),str(b),type(c) {}
};
vector<word> a;

int n;

void dfs(int preIdx, int sufIdx, int len) {
	if (len == n - 1) {
		string ans1 = a[preIdx].str + a[sufIdx].str[n - 2];
		string ans2 = a[preIdx].str[0] + a[sufIdx].str;
		if (ans1 == ans2) {
			cout << ans1 << '\n';
			sort(a.begin(), a.end(), [](const word &u, const word &v) {
				return u.idx < v.idx;
			});
			for (int i = 0; i < a.size(); ++i) {
				cout << a[i].type;
			}
			exit(0);
		}
		return;
	}
	if (a[preIdx].str == a[2 * len].str.substr(0, len) && a[sufIdx].str == a[2 * len + 1].str.substr(1, len)) {
		a[2 * len].type = 'P';
		a[2 * len + 1].type = 'S';
		dfs(2 * len, 2 * len + 1, len + 1);
	}

	if (a[preIdx].str == a[2 * len + 1].str.substr(0, len) && a[sufIdx].str == a[2 * len].str.substr(1, len)) {
		a[2 * len + 1].type = 'P';
		a[2 * len].type = 'S';
		dfs(2 * len + 1, 2 * len, len + 1);
	}

	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < 2 * n - 2; ++i) {
		string s;
		cin >> s;
		a.emplace_back(i, s, ' ');
	}

	sort(a.begin(), a.end(), [](const word &u, const word &v) {
		return u.str.size() < v.str.size();
	});

	string ans;

	a[0].type = 'P';
	a[1].type = 'S';
	dfs(0, 1, 1);

	a[1].type = 'P';
	a[0].type = 'S';
	dfs(1, 0, 1);

	return 0;
}