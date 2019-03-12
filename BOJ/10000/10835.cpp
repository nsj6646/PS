#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int l[2001], r[2001];
int d[2001][2001];
int n;
int f(int x, int y) {
	if (x == n || y == n) {
		return 0;
	}
	if (d[x][y] != -1) {
		return d[x][y];
	}
	
	d[x][y] = max(f(x + 1, y), f(x + 1, y + 1));
	
	if (l[x] > r[y]) {
		d[x][y] = max(d[x][y],f(x, y + 1) + r[y]);
		
	}
	return d[x][y];
}
int main()
{
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &l[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &r[i]);
	}
	memset(d, -1, sizeof(d));
	printf("%d", f(0, 0));
	return 0;
}

//#include <cstdio> // scanf, printf.
//#include <vector> // ���� ����Ʈ.
//#include <string.h> // memset. �迭 �ʱ�ȭ �Լ�.
//#include <algorithm> // max. �� �� �ִ밪 ����.
//
//using namespace std;
//
//int N; // �� ������ ī���� ������ ��Ÿ���� �ڿ���. �ִ� 2,000.
//vector<int> left; // ���� ����.
//vector<int> right; // ������ ����.
//int memo[2001][2001]; // �޸������̼� ����. 2����.
//					  // solve(L,R)�� ���ϰ��� memo[L][R]�� ����س��´�.
//
//int solve(int L, int R) // �Լ��� ���� : ���� ������ �ִ밪 ���.
//{
//	// ���� ����. �ٴ� ����. ���� ����.
//	if (L == N || R == N)
//		// ��Ģ 3. ��� �� ���̵� ���� ī�尡 ���ٸ�
//		return 0; // ���� ��. �� �̻� ��� ���� ����.
//
//	int &ret = memo[L][R]; // �ּҿ����ڷ� ����.
//	if (ret != -1) // solve(L,R)�� �̹� ����Ǿ �� ������� �ִٸ�,
//		return ret; // �� ����� ����.
//					// �޸������̼��� ���� �޸𸮸� ����ϴ� ��� �ߺ� ȣ���� �ٿ� ó�� �ð��� ���δ�.
//
//	ret = max(solve(L + 1, R), solve(L + 1, R + 1)); // �� �� �ִ밪�� ret�� �Է�.
//													 // ��Ģ 1. �������� ���� ī�常 �뿡 ���� ���� �ְ� // solve(L+1,R)
//													 // ���� ī��� ������ ī�带 �� �� �뿡 ���� ���� �ִ�. // solve(L+1,R+1)
//													 // �̶� ��� ���� ����.
//
//	if (left[L] > right[R])
//		// ��Ģ 2. ������ ī�忡 ���� ���� ���� ī�忡 ���� ������ ���� ��쿡��
//		ret = max(ret, solve(L, R + 1) + right[R]); // �� �� �ִ밪�� ret�� �Է�.
//													// ������ ī�常 �뿡 ���� ���� �ִ�. // solve(L,R+1)
//													// �� �� ������ ī�忡 ���� ����ŭ ������ ��´�. // +right[R]
//	return ret; // ���� ������ �ִ밪 ����.
//}
//
//int main()
//{
//	scanf("%d", &N); // �� ������ ī���� ���� �Է�.
//	left.resize(N); // left ����Ʈ ũ�� N��ŭ(0~N-1) ����.
//	right.resize(N); // right ����Ʈ ũ�� N��ŭ(0~N-1) ����.
//	memset(memo, -1, sizeof(memo)); // �޸������̼� ���� �迭 -1�� ��� �ʱ�ȭ.
//									// -1�� ���� ������ ���� �� ���� ���̱� ������ �ʱ�ȭ ������ �����ߴ�.
//	for (int i = 0; i<N; i++)
//		scanf("%d", &left[i]); // ���� ���� ī�� ������� �Է�.
//	for (int i = 0; i<N; i++)
//		scanf("%d", &right[i]); // ������ ���� ī�� ������� �Է�.
//	printf("%d", solve(0, 0)); // ���� ������ �ִ밪 ���.
//							   // solve(0,0) �� ����, ������ ���� ��� ù���� ī����� �����Ѵٴ� ��.
//}


//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//#define INF 987654321
//using namespace std;
//int dp[2001][2001], n, a[2001], b[2001];
//int func(int x, int y) {
//	if (x == n || y == n)return 0;
//	int &ret = dp[x][y];
//	if (ret != -1)return ret;
//	ret = max(func(x + 1, y), func(x + 1, y + 1));
//	if (a[x] > b[y])
//		ret = max(ret, func(x, y + 1) + b[y]);
//	return ret;
//}
//int main() {
//	memset(dp, -1, sizeof(dp));
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//		scanf("%d", &a[i]);
//	for (int j = 0; j < n; j++)
//		scanf("%d", &b[j]);
//	printf("%d\n", func(0, 0));
//	return 0;
//}
