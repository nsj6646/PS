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
//int dx[] = { -1,0,1,0 };	//�������
//int dy[] = { 0,1,0,-1 };	//�������
//int dp = 1;	//ó���� ������	(�������)
//int cc = 0;	//0:������ 1:����
//int attempt;
//string ans = "";
///*
//1. ���� ����� �ڵ��� �߿��� DP�� �������� ���� �ָ� ��ġ�� �ڵ����� ã�´�. 
//	����� �������� ���� ��� �� �ڵ����� �̾����� ���� ������ �� �ִ�.
//2. ������ ã�� �ڵ��� �� DP ������ ������ �� CC�� �������� ���� ���� �ִ� �ڵ��� �����Ѵ�. 
//	�� �� CC�� ������ ������� �����ӿ� �����϶�. 
//	���� ���, DP�� �Ʒ����� ����Ű�� CC�� �������� ����Ű�� ���, ���õǴ� �ڵ��� ���� ���ʿ� �ִ� �ڵ��� �ȴ�.
//3. ������ ������ �ڵ����� DP�� �������� �´��� �ڵ��� ���Ե� ����� ���� ����� �ȴ�.
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
//					/*���� point ����*/
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
//		/*���������� �õ�Ƚ�� �ʱ�ȭ*/
//		attempt = 0;
//		return;
//	}
//	else {
//		/*������ ��� Ȥ�� �̹����� ��� �ٱ��� �̵��� �� ���� �����̴�. ����
//		1. �������� �̵��Ϸ��� ����� �������̰ų�
//		2. �̹����� ��踦 ����� ���� ������ ������� �����Ѵ�.
//		*/
//		/*
//		1. CC�� ���� ������ ��� ����������, �������� ��� �������� �ٲ� �� �ٽ� �̵��� �õ��Ѵ�.
//		2. CC�� ���� �ٲ� �Ŀ��� �̵��� �� ���� ���, CC�� ���� �����ϸ� DP�� �ð�������� ȸ���� �� �ٽ� �̵��� �õ��Ѵ�.
//		3. �ð�������� ȸ���� �Ŀ��� �̵��� �� ���� ���, 1������ �ǵ��ư���.
//		4. �� ������ ��� �ݺ��Ͽ� �� 8������ ��츦 ��� �õ��ߴµ��� �̵��� �� �ִ� ����� ã�� ���� ���, ���α׷��� ����ȴ�.
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