#include <iostream>
#include <cstring>
#define INFI	99999999
using namespace std;

int n, m;
char map[500][501];
int visited[500][500];

int dx[] = { 0,1,0,-1 };	//�������
int dy[] = { -1,0,1,0 };	//�������
void print(int ans, int d) {
	switch (d){
		case 0:cout << "U\n";break;
		case 1:cout << "R\n"; break;
		case 2:cout << "D\n"; break;
		case 3:cout << "L\n"; break;
	}
	if (ans == INFI) {
		cout << "Voyager\n";
	}
	else {
		cout << ans << '\n';
	}
}
void change_d(int &d, char c) {
	if (d == 0) {	//��
		if (c == '/') {
			d = 1;	//��
		}
		else {
			d = 3;	//��
		}
	}
	else if (d == 1) {	//��
		if (c == '/') {
			d = 0;	//��
		}
		else {
			d = 2;	//��
		}
	}
	else if (d == 2) {	//��
		if (c == '/') {
			d = 3;	//��
		}
		else {
			d = 1;	//��
		}
	}
	else if (d == 3) {	//��
		if (c == '/') {
			d = 2;	//��
		}
		else {
			d = 0;	//��
		}
	}
}
int go(int x, int y,const int s,int k) {
	if ((map[y][x] == '/' || map[y][x] == '\\')) {
		if (visited[y][x]>=6) {
			print(INFI, s);
			exit(0);
		}
		else {
			change_d(k, map[y][x]);
			visited[y][x] += k;
		}
	}
	else {
		visited[y][x] += k;
	}

	int nx = x + dx[k];
	int ny = y + dy[k];
	if (nx >= 0 && nx < m&&ny >= 0 && ny < n) {
		if (map[ny][nx] == 'C') {
			return 1;
		}
		else {
			return go(nx, ny, s,k) + 1;
		}
	}
	else {
		return 1;
	}
}

int main()
{
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	int pr, pc;
	cin >> pr >> pc;
	
	int ans = -1;
	int d = 0;
	for (int i = 0; i < 4; i++) {
		for (int a = 0; a < n; a++) {
			memset(visited[a], 0, sizeof(bool)*m);
		}
		int temp = go(pc - 1, pr - 1, i,i);
		if (temp > ans) {
			ans = temp;
			d = i;
		}
	}
	print(ans, d);
	return 0;
}