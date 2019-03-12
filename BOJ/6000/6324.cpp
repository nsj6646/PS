#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		string s;
		cin >> s;

		int n = s.size();
		string protocol, host = "", port = "<default>", path = "<default>";
		int idx;
		if (s[0] == 'f') {
			protocol = "ftp";
			idx = 6;
		}
		else if (s[0] == 'h') {
			protocol = "http";
			idx = 7;
		}
		else {
			protocol = "gopher";
			idx = 9;
		}

		for (int i = idx; i < n; ++i) {
			if (s[i] == ':' || s[i] == '/') {
				idx = i;
				break;
			}
			host.push_back(s[i]);
		}
		if (s[idx] == ':') {
			port = "";
			for (int i = idx + 1; i < n; ++i) {
				if (s[i] == '/') {
					idx = i;
					break;
				}
				port.push_back(s[i]);
			}

		}
		if (s[idx] == '/') {
			path = "";
			for (int i = idx + 1; i < n; ++i) {
				path.push_back(s[i]);
			}
		}

		cout << "URL #" << tc << '\n';
		cout << "Protocol = " << protocol << '\n';
		cout << "Host     = " << host << '\n';
		cout << "Port     = " << port << '\n';
		cout << "Path     = " << path << '\n';
		cout << '\n';

	}

	return 0;
}