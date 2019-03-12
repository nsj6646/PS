#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
	string str;
	cin >> str;
	list<char> editor(str.begin(), str.end());
	
	auto cursor = editor.end();
	int N;
	cin >> N;
	while (N--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'L') {
			if (cursor == editor.begin()) {
				continue;
			}
			--cursor;
		}
		else if (cmd == 'D') {
			if (cursor == editor.end()) {
				continue;
			}
			++cursor;
		}
		else if (cmd == 'B') {
			if (cursor == editor.begin()) {
				continue;
			}
			cursor = editor.erase(--cursor);
		}
		else if (cmd == 'P') {
			char c;
			cin >> c;
			editor.insert(cursor, c);
		}
	}
	for (char x : editor) {
		cout << x;
	}
	return 0;
}




#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
char a[600000];
int main() {
	scanf("%s", a);
	stack<char> left, right;
	int n = strlen(a);
	for (int i = 0; i<n; i++) {
		left.push(a[i]);
	}
	int m;
	scanf("%d", &m);
	while (m--) {
		char what;
		scanf(" %c", &what);
		if (what == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (what == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (what == 'B') {
			if (!left.empty()) {
				left.pop();
			}
		}
		else if (what == 'P') {
			char c;
			scanf(" %c", &c);
			left.push(c);
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		printf("%c", right.top());
		right.pop();
	}
	printf("\n");
	return 0;
}