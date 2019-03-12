#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
using namespace std;


bool D(deque<int> &d, bool r) {
	if (d.empty()) {
		return true;
	}
	if (r) {
		d.pop_front();
	}
	else {
		d.pop_back();
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		
		string p;
		cin >> p;

		int n;
		cin >> n;
		deque<int> d(n);
		string raw;
		cin >> raw;
		string input = raw.substr(1, raw.size()-2);
		istringstream sin(input);
		string number;
		int idx = 0;
		while (getline(sin, number, ',')) {
			d[idx++]=stoi(number);
		}

		bool r = true;
		bool error = false;
		for (char op : p) {
			if (op == 'R') {
				r = !r;
			}
			else if (op == 'D') {
				error = D(d,r);
				if (error) {
					cout << "error\n";
					break;
				}
			}
		}
		if (!error) {
			string ans = "[";
			if (r) {
				for (int x : d) {
					ans += to_string(x);
					ans += ",";
				}
			}
			else {
				for (int i = d.size() - 1; i >= 0; i--) {
					ans += to_string(d[i]);
					ans += ",";
				}
			}
			 
			if (ans.back() == ',') {
				ans.back() = ']';
			}
			else {
				ans.push_back(']');
			}
			cout << ans << '\n';
		}
	}
	return 0;
}