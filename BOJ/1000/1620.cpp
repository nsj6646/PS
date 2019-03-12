#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;

map<string, int> dict1;
string dict2[100001];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	
	for (int i = 1; i <= n; i++) {
		string name;
		cin >> name;
		dict1[name] = i;
		dict2[i] = name;
	}

	for (int i = 0; i < m; i++) {
		string que;
		cin >> que;
		if (isalpha(que[0])) {
			cout << dict1[que] << '\n';
		}
		else {
			cout << dict2[stoi(que)] << '\n';
		}
	}
	return 0;
}