//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//typedef struct line {
//	int i;
//	int a, b;
//	int size;
//};
//
//bool cmp(const line &u, const line &v) {
//	return u.size < v.size;
//}
//int linesize(int a, int b, int n) {
//	if (a <= b) {
//		return b - a;
//	}
//	else {
//		return linesize((a + 1) % n, b, n) + 1;
//	}
//}
//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//	vector<line> v(m);
//	for (int i = 0; i < m; i++) {
//		int a, b;
//		scanf("%d %d", &a, &b);
//		v[i].i = i+1;
//		v[i].a = a; v[i].b = b;
//		v[i].size = linesize(a, b, n);
//	}
//
//	sort(v.begin(), v.end(),cmp);
//	vector<int> check(n);
//	for (int i = 0; i < m; i++) {
//		//µ¤¾î¾²±â
//		while (v[i].a != v[i].b) {
//			check[v[i].a++] = v[i].i;
//			v[i].a %= n;
//		}
//		//
//	}
//	sort(check.begin(), check.end());
//	auto last = unique(check.begin(), check.end());
//	for (auto it = check.begin(); it != last; ++it) {
//		printf("%d ", *it);
//	}
//	return 0;
//}

//#include <cstdio>
//#include <algorithm>
//using namespace std;
//
//struct intv {
//	int s, e, i;
//	bool operator <(const intv a) const { return s != a.s ? s<a.s : e>a.e; }
//}I[500001];
//
//int N, M;
//bool forb[500001];
//
//int main()
//{
//
//	scanf("%d %d", &N, &M);
//
//	int over = 0;
//	for (int i = 0; i < M; i++) {
//		scanf("%d %d", &I[i].s, &I[i].e);
//		I[i].i = i + 1;
//		if (I[i].s > I[i].e) {
//			over = max(over, I[i].e);
//			I[i].e += N;
//		}
//	}
//
//	sort(I, I + M);
//
//	for (int i = 0; i < M; i++) {
//		if (I[i].e <= over)forb[I[i].i] = 1;
//		else over = I[i].e;
//	}
//	for (int i = 1; i <= M; i++) if (!forb[i]) printf("%d ", i);
//
//	return 0;
//}