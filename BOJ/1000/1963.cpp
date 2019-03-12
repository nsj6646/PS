#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

bool p[10000];
bool check[10000];
int level[10000];
int d[5] = { 10000, 1000,100,10,1 };

void eratos() {
	p[0] = p[1] = true;
	for (int i = 2; i*i < 10000; i++) {
		if (!p[i]) {
			if (i >= 1000){
			}
			for (int j = i * 2; j < 10000; j += i) {
				p[j] = true;
			}
		}
	}
}

bool bfs(int a, int b) {
	queue<int> q;
	q.push(a);
	check[a] = true;
	level[a] = 0;
	while (!q.empty()) {
		int a = q.front();	
		q.pop();
		if (a == b) {
			return true;
		}
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j <= 9; j++) {
				int next = a - (((a%d[i-1])/ d[i]) * d[i]) + j * d[i];
				if (next >= 1000 && !check[next] && !p[next]) {	//1000이상, 탐색안한숫자, 소수				
					q.push(next);
					check[next] = true;
					level[next] = level[a] + 1;
				}
			}
		}
		
	}
	return false;
}
int main()
{
	eratos();
	int T;
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++) {
		memset(check, false, sizeof(check));
		memset(level, false, sizeof(level));
		int a, b;
		cin >> a >> b;
		if (bfs(a, b)) {
			cout << level[b] << '\n';
		}
		else {
			cout << "Impossible\n";
		}
	}
	return 0;
}

//#include <iostream>
//#include <cstring>
//#include <queue>
//#include <string>
//#include <algorithm>
//using namespace std;
//bool prime[10001];
//bool c[10001];
//int d[10001];
//int change(int num, int index, int digit) {
//	if (index == 0 && digit == 0) return -1;
//	string s = to_string(num);
//	s[index] = digit + '0';
//	return stoi(s);
//}
//int main() {
//	for (int i = 2; i <= 10000; i++) {
//		if (prime[i] == false) {
//			for (int j = i * i; j <= 10000; j += i) {
//				prime[j] = true;
//			}
//		}
//	}
//	for (int i = 0; i <= 10000; i++) {
//		prime[i] = !prime[i];
//	}
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, m;
//		cin >> n >> m;
//		memset(c, false, sizeof(c));
//		memset(d, 0, sizeof(d));
//		d[n] = 0;
//		c[n] = true;
//		queue<int> q;
//		q.push(n);
//		while (!q.empty()) {
//			int now = q.front();
//			q.pop();
//			for (int i = 0; i<4; i++) {
//				for (int j = 0; j <= 9; j++) {
//					int next = change(now, i, j);
//					if (next != -1) {
//						if (prime[next] && c[next] == false) {
//							q.push(next);
//							d[next] = d[now] + 1;
//							c[next] = true;
//						}
//					}
//				}
//			}
//		}
//		cout << d[m] << '\n';
//	}
//	return 0;
//}