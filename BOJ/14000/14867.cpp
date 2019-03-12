#include <iostream>
#include <string>
#include <set>
#include <queue>
using namespace std;

typedef pair<int, int> bottle;
typedef pair<bottle, int> st;
int a, b, c, d;
set<string> visited;

bottle AtoB(int x, int y) {	//a,b
	if (x <= b - y) {
		y += x;
		x = 0;
	}
	else {
		x -= b -y;
		y = b;
	}
	return make_pair(x, y);
}
bottle BtoA(int x, int y) {	//a,b
	if (y <= a - x) {
		x += y;
		y = 0;
	}
	else {
		y -= a - x;
		x = a;
	}
	return make_pair(x, y);
}
bottle operate(int x, int y, int k) {
	switch (k) {
	case 1:			//1 : A����
		return { 0,y };
	case 2:			//2 : B����
		return { x,0 };
	case 3:			//3 : Aä���
		return { a,y };
	case 4:			//4 : Bä���
		return { x,b };
	case 5:			//5 : A���� B�ű��
		return AtoB(x, y);
	case 6:			//6 : B���� A�ű��
		return BtoA(x, y);
	}
}
int main()
{
	cin >> a >> b >> c >> d;
	int ans = 0;
	bool found = false;
	queue<st> q;
	q.push({ { 0,0},0 });
	visited.insert("A0B0");
	while (!q.empty()) {
		st now_st = q.front();
		bottle now = now_st.first;
		int depth = now_st.second;
		q.pop();
		//cout << now.first << ' ' << now.second << ' ' << depth << '\n';
		if (now.first == c && now.second == d) {
			found = true;
			ans = depth;
			break;	
		}
		
		//Aä���, Bä���, A����, B����, A�� B��, B�� A��
		for (int op = 1; op <= 6; op++) {
			bottle next = operate(now.first, now.second, op);
			string t = "A";
			t += to_string(next.first);
			t += "B";
			t += to_string(next.second);
			//cout << t << '\n';
			if (visited.count(t) == 0) {
				visited.insert(t);
				q.push({ next,depth + 1 });
			}
		}
	}
	if (found) {
		cout << ans;
	}
	else {
		cout << -1;
	}

	return 0;
}