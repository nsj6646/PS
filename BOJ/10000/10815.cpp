#include <iostream>
#include <set>
using namespace std;

int main()
{
	int N, M;
	scanf("%d", &N);
	set<int> s;
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		s.insert(num);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);
		printf("%d ", s.count(num));
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);
		printf("%d ", binary_search(v.begin(), v.end(), num));
	}
	return 0;
}