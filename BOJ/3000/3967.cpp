#include <iostream>
#include <string>
#include <deque>
using namespace std;

typedef pair<int, int> pii;
typedef pii node;

bool nums[13];
//(0,4),
//(1,1),(1,3),(1,5),(1,7),
//(2,2),(2,6),
//(3,1),(3,3),(3,5),(3,7),
//(4,4)
int star[5][9];
deque<node> dq;
inline bool check1() {
	return star[0][4] + star[1][3] + star[2][2] + star[3][1] == 26;
}
inline bool check2() {
	return star[3][1] + star[3][3] + star[3][5] + star[3][7] == 26;
}
inline bool check3() {
	return star[3][7] + star[2][6] + star[1][5] + star[0][4] == 26;
}
inline bool check4() {
	return star[1][1] + star[2][2] + star[3][3] + star[4][4] == 26;
}
inline bool check5() {
	return star[4][4] + star[3][5] + star[2][6] + star[1][7] == 26;
}
inline bool check6() {
	return star[1][7] + star[1][5] + star[1][3] + star[1][1] == 26;
}

void printans() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (star[i][j] == '.') {
				cout << (char)star[i][j];
			}
			else {
				cout << (char)(star[i][j] + 'A' - 1);
			}
		}
		cout << '\n';
	}
}
void magic() {
	if (dq.empty()) {
		if (check1() && check2() && check3() && check4() && check5() && check6()) {
			printans();
			exit(0);
		}
		return;
	}
	node now = dq.front();
	dq.pop_front();
	for (int i = 1; i <= 12; i++) {
		if (nums[i] == false) {
			star[now.first][now.second] = i;
			nums[i] = true;
			magic();
			nums[i] = false;
			star[now.first][now.second] = 0;	
		}
	}
	dq.push_front(now);
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 5; i++) {
		string in;
		cin >> in;
		for (int j = 0; j < 9; j++) {
			char c = in[j];
			if (c == '.') {
				star[i][j] = c;
			}
			else if (c == 'x') {
				star[i][j] = 0;
				dq.push_back({ i,j });
			}
			else {
				star[i][j] = c - 'A' + 1;
				nums[star[i][j]] = true;
			}
		}
	}
	magic();
	return 0;
}