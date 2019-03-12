//#include <iostream>
//#include <queue>
//#include <string>
//#include <cstring>
//using namespace std;
//typedef pair<int, int> point;
//
//int n, m;
//char a[100][100];
//int visited[100][100];
//point cur_point;
//char cur_block;
//int dx[] = { -1,0,1,0 };	//상우하좌
//int dy[] = { 0,1,0,-1 };	//상우하좌
//int dp = 1;	//처음엔 오른쪽	(상우하좌)
//int cc = 0;	//0:오른쪽 1:왼쪽
//int attempt;
//string ans = "";
///*
//1. 현재 블록의 코델들 중에서 DP의 방향으로 가장 멀리 위치한 코델들을 찾는다. 
//	블록이 볼록하지 않은 경우 이 코델들은 이어지지 않은 형태일 수 있다.
//2. 위에서 찾은 코델들 중 DP 방향을 향했을 때 CC의 방향으로 가장 끝에 있는 코델을 선택한다. 
//	이 때 CC의 방향은 상대적인 방향임에 유의하라. 
//	예를 들어, DP가 아래쪽을 가리키고 CC가 오른쪽을 가리키는 경우, 선택되는 코델은 가장 왼쪽에 있는 코델이 된다.
//3. 위에서 선택한 코델에서 DP의 방향으로 맞닿은 코델이 포함된 블록이 다음 블록이 된다.
//*/
//
//
//
//
//
//void find_codel(point &top, point &bot, point &left, point &right, int sx, int sy) {
//	cur_point = { sx,sy };
//	cur_block = a[sx][sy];
//	
//	top = bot = left = right = { sx,sy };
//	/*bfs*/
//	memset(visited, 0, sizeof(visited));
//	queue<point> q;
//	q.push({ sx,sy });
//	visited[sx][sy] = 1;
//	while (!q.empty()) {
//		point now = q.front();
//		int x = now.first;
//		int y = now.second;
//		q.pop();
//		for (int k = 0; k < 4; k++) {
//			int nx = x + dx[k];
//			int ny = y + dy[k];
//			if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
//				if (a[nx][ny] == cur_block && visited[nx][ny] == 0) {
//					q.push({ nx,ny });
//					visited[nx][ny] = 1;
//					/*말단 point 갱신*/
//					if (nx <= top.first) {
//						top.first = nx;
//						top.second = ny;
//					}
//					if (nx >= bot.first) {
//						bot.first = nx;
//						bot.second = ny;
//					}
//					if (ny <= left.second) {
//						left.first = nx;
//						left.second = ny;
//					}
//					if (ny >= right.second) {
//						right.first = nx;
//						right.second = ny;
//					}
//				}
//			}
//		}
//	}
//
//	//cout << top.first << ", " << top.second << '\n';
//	//cout << right.first << ", " << right.second << '\n';
//	//cout << bot.first << ", " << bot.second << '\n';
//	//cout << left.first << ", " << left.second << '\n';
//
//}
//point choose_codel(int x,int y) {
//	int k = (cc == 0)? (dp + 1) % 4 : (dp + 3) % 4;
//	point c = { x,y };
//	int nx = x, ny = y;
//	while (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
//		nx += dx[k];
//		ny += dy[k];
//		if (a[nx][ny] == cur_block && visited[nx][ny] == 1) {
//			c = { nx,ny };
//		}
//	}
//	return c;
//}
//void next_block(int x, int y) {
//	point t, b, l, r;
//	find_codel(t, b, l, r, x, y);
//	point c;
//	switch (dp)
//	{
//	case 0: c = t; break;
//	case 1: c = r; break;
//	case 2: c = b; break;
//	case 3: c = l; break;
//	}
//	x = c.first;
//	y = c.second;
//	int nx = x + dx[dp], ny = y + dy[dp];
//	
//	if ((nx >= 0 && nx < n&&ny >= 0 && ny < m) && (a[nx][ny] != 'X')) {
//		cur_point = { nx,ny };
//		cur_block = a[nx][ny];
//		ans.push_back(cur_block);
//		/*성공했으니 시도횟수 초기화*/
//		attempt = 0;
//		return;
//	}
//	else {
//		/*검은색 블록 혹은 이미지의 경계 바깥은 이동할 수 없는 구역이다. 만약
//		1. 다음으로 이동하려는 블록이 검은색이거나
//		2. 이미지의 경계를 벗어나는 경우는 다음의 방법으로 진행한다.
//		*/
//		/*
//		1. CC의 값이 왼쪽인 경우 오른쪽으로, 오른쪽인 경우 왼쪽으로 바꾼 후 다시 이동을 시도한다.
//		2. CC의 값을 바꾼 후에도 이동할 수 없는 경우, CC의 값을 유지하며 DP를 시계방향으로 회전한 후 다시 이동을 시도한다.
//		3. 시계방향으로 회전한 후에도 이동할 수 없는 경우, 1번으로 되돌아간다.
//		4. 위 과정을 계속 반복하여 총 8가지의 경우를 모두 시도했는데도 이동할 수 있는 블록을 찾지 못한 경우, 프로그램이 종료된다.
//		*/
//		attempt = 1;
//		while (attempt < 8) {
//
//		}
//		cc = !cc;
//		choose_codel()
//	}
//
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> a[i][j];
//		}
//	}
//
//	while (attempt<8)
//	{
//		find_codel(0, 0);
//	}
//
//	
//	return 0;
//}