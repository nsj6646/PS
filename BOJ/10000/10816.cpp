//#include <iostream>
//#include <set>
//using namespace std;
//
//int main()
//{
//	int N, M;
//	scanf("%d", &N);
//	multiset<int> s;
//	for (int i = 0; i < N; i++) {
//		int num;
//		scanf("%d", &num);
//		s.insert(num);
//	}
//	scanf("%d", &M);
//	for (int i = 0; i < M; i++) {
//		int num;
//		scanf("%d", &num);
//		printf("%d ", s.count(num));
//	}
//	return 0;
//}
//#include <iostream>
//#include <map>
//using namespace std;
//
//int main()
//{
//	int N, M;
//	scanf("%d", &N);
//	map<int,int> m;
//	for (int i = 0; i < N; i++) {
//		int num;
//		scanf("%d", &num);
//		if (m.count(num)) {
//			m[num]++;
//		}
//		else {
//			m[num] = 1;
//		}
//	}
//	scanf("%d", &M);
//	for (int i = 0; i < M; i++) {
//		int num;
//		scanf("%d", &num);
//		printf("%d ", m[num]);
//	}
//	return 0;
//}
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);
		auto l = lower_bound(v.begin(), v.end(), num);
		auto r = upper_bound(v.begin(), v.end(), num);
		printf("%d ", r-l);
	}
	return 0;
}