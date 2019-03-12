#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int M;
	cin >> M;
	bitset<21> b;
	string str;
	int x;
	for (int tc = 1; tc <= M; tc++) {
		cin >> str;
		if (str == "add") {
			cin >> x;
			b.set(x);
		}
		else if (str == "remove") {
			cin >> x;
			b.reset(x);
		}
		else if (str == "check") {
			cin >> x;
			if (b.test(x)) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (str == "toggle") {
			cin >> x;
			b.flip(x);
		}
		else if (str == "all") {
			b.set();
		}
		else if (str == "empty") {
			b.reset();
		}
	}
	return 0;
}
//#include <iostream>
//#include <string>
//using namespace std;
//
//int S;
//void add(int x);
//void remove(int x);
//void check(int x);
//void toggle(int x);
//void all();
//void empty();
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//	int M;
//	cin >> M;
//	string str;
//	int x;
//	for (int tc = 1; tc <= M; tc++) {
//		cin >> str;
//		if (str == "add") {
//			cin >> x;
//			add(x);
//		}
//		else if (str == "remove") {
//			cin >> x;
//			remove(x);
//		}
//		else if (str == "check") {
//			cin >> x;
//			check(x);
//		}
//		else if (str == "toggle") {
//			cin >> x;
//			toggle(x);
//		}
//		else if (str == "all") {
//			all();
//		}
//		else if (str == "empty") {
//			empty();
//		}
//	}
//	return 0;
//}
//void add(int x) {
//	x -= 1;
//	S |= (1 << x);
//}
//void remove(int x) {
//	x -= 1;
//	S &= ~(1 << x);
//}
//void check(int x) {
//	x -= 1;
//	if (S&(1 << x)) {
//		cout << "1\n";
//	}
//	else {
//		cout << "0\n";
//	}
//}
//void toggle(int x) {
//	x -= 1;
//	S ^= (1 << x);
//}
//void all() {
//	S = (1 << 20) - 1;
//}
//void empty() {
//	S = 0;
//}

//#include <cstdio>
//#include <cstring>
//using namespace std;
//char b[111];
//int main() {
//	int n = 20;
//	int m;
//	scanf("%d", &m);
//	int s = 0;
//	int x;
//	while (m--) {
//		scanf("%s", b);
//		if (!strcmp(b, "add")) {
//			scanf("%d", &x); x--;
//			s = (s | (1 << x));
//		}
//		else if (!strcmp(b, "remove")) {
//			scanf("%d", &x); x--;
//			s = (s & ~(1 << x));
//		}
//		else if (!strcmp(b, "check")) {
//			scanf("%d", &x); x--;
//			int res = (s & (1 << x));
//			if (res) {
//				puts("1");
//			}
//			else {
//				puts("0");
//			}
//		}
//		else if (!strcmp(b, "toggle")) {
//			scanf("%d", &x); x--;
//			s = (s ^ (1 << x));
//		}
//		else if (!strcmp(b, "all")) {
//			s = (1 << n) - 1;
//		}
//		else if (!strcmp(b, "empty")) {
//			s = 0;
//		}
//	}
//	return 0;
//}