#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[100001];
//int level[100001];
int parent[100001];
bool check[100001];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	queue<int> q;
	q.push(1); check[1] = true; parent[1] = 0; //level[1] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : a[x]) {
			if (!check[y]) {
				parent[y] = x;
				//level[y] = level[x] + 1;
				q.push(y);
				check[y] = true;
			}
		}	
	}
	for (int i = 2; i <= n; i++) {
		printf("%d\n", parent[i]);
	}
	return 0;
}