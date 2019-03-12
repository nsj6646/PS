#define N		1001
#define MIN(X,Y)	(X)<(Y)?(X):(Y)
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

typedef pair<int, int> edge;		//dist, bridge

int n, m;
int visited[N][N];
bool isvisit;
vector<edge> v[N];

//priority_queue<edge> pq;
int to_free;
int ans = 987654321;

void shortest_path(int dist, int from) {
	if (from == n) {
		if (isvisit) {
			ans = MIN(ans, dist);
			printf("%d", ans);
			exit(0);
		}
		return;
	}

	priority_queue<edge> pq;
	for (int i = 0;i< v[from].size(); ++i) {
		int to = v[from][i].second;
		if (visited[from][to] || visited[to][from]) continue;
		pq.push(v[from][i]);
	}
	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();
		visited[from][now.second] = 1;
		visited[now.second][from] = 1;
		if (now.second == 2) {
			isvisit = true;
		}
		shortest_path(dist-now.first, now.second);
		if (now.second == 2) {
			isvisit = false;
		}
		visited[from][now.second] = 0;
		visited[now.second][from] = 0;
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int s, e, d;
		scanf("%d %d %d", &s, &e, &d);
		v[s].push_back({ -d,e });
		v[e].push_back({ -d,s });
	}

	shortest_path(0,1);

	return 0;
}