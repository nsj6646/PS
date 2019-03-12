#define N		50
#define MAX_HEIGHT		1000000
#define MIN(X,Y)		(X)<(Y)?(X):(Y)
#define MAX(X,Y)		(X)>(Y)?(X):(Y)
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int n;
typedef pair<int, int> point;

int dx[] = { -1,0,1,-1,1,-1,0,1 };
int dy[] = { -1,-1,-1,0,0,1,1,1 };

char a[N][N];
int height[N][N];
int visited[N][N];

point post;
queue<point> q;
vector<point> v;
vector<int> values;

bool safe(int x, int y) {
	return (x >= 0 && x < n&&y >= 0 && y < n);
}
void init(int low, int high) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (height[i][j]<low || height[i][j]>high) {
				visited[i][j] = 2;	//¸ø°¨
			}
			else {
				visited[i][j] = 0;
			}
		}
	}
}


void bfs() {
	q.push(post);
	visited[post.second][post.first] = 1;

	while (!q.empty()) {
		point now = q.front();
		int x = now.first;
		int y = now.second;
		q.pop();
		for (int k = 0; k < 8; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (safe(nx, ny) && visited[ny][nx] == 0) {
				q.push({ nx,ny });
				visited[ny][nx] = 1;
			}
		}
	}
}

bool check() {
	for (int i = 0; i < v.size(); ++i) {
		if (!visited[v[i].second][v[i].first]) {
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf(" %c", &a[i][j]);
			if (a[i][j] == 'P') {
				post = { j,i };
				v.push_back(post);
			}
			else if (a[i][j] == 'K') {
				v.push_back({ j,i });
			}
		}
	}

	int low = MAX_HEIGHT;
	int high = -1;
	int hLow = MAX_HEIGHT;
	int hHigh = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &height[i][j]);
			values.push_back(height[i][j]);
			if (a[i][j] == 'K' || a[i][j] == 'P') {
				hLow = MIN(hLow, height[i][j]);
				hHigh = MAX(hHigh, height[i][j]);
			}
		}
	}
	sort(values.begin(), values.end());

	auto lowIter = lower_bound(values.begin(), values.end(), hLow);
	auto highIter = upper_bound(values.begin(), values.end(), hHigh);
	int lowIdx = lowIter - values.begin();
	int highIdx = highIter - values.begin() - 1;

	int ans = MAX_HEIGHT;
	int limit = -1;
	for (int i = lowIdx; i >= 0; --i) {
		int left = highIdx; int right = values.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			init(values[i], values[mid]);
			bfs();
			if (check()) {
				ans = MIN(ans, values[mid] - values[i]);
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
