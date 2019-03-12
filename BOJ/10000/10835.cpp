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
//#include <vector> // 인접 리스트.
//#include <string.h> // memset. 배열 초기화 함수.
//#include <algorithm> // max. 둘 중 최대값 리턴.
//
//using namespace std;
//
//int N; // 한 더미의 카드의 개수를 나타내는 자연수. 최대 2,000.
//vector<int> left; // 왼쪽 더미.
//vector<int> right; // 오른쪽 더미.
//int memo[2001][2001]; // 메모이제이션 변수. 2차원.
//					  // solve(L,R)의 리턴값을 memo[L][R]에 기록해놓는다.
//
//int solve(int L, int R) // 함수의 정의 : 최종 점수의 최대값 출력.
//{
//	// 기저 조건. 바닥 조건. 종료 조건.
//	if (L == N || R == N)
//		// 규칙 3. 어느 쪽 더미든 남은 카드가 없다면
//		return 0; // 게임 끝. 더 이상 얻는 점수 없음.
//
//	int &ret = memo[L][R]; // 주소연산자로 연결.
//	if (ret != -1) // solve(L,R)이 이미 실행되어서 그 결과값이 있다면,
//		return ret; // 그 결과값 리턴.
//					// 메모이제이션을 통해 메모리를 희생하는 대신 중복 호출을 줄여 처리 시간을 줄인다.
//
//	ret = max(solve(L + 1, R), solve(L + 1, R + 1)); // 둘 중 최대값을 ret에 입력.
//													 // 규칙 1. 언제든지 왼쪽 카드만 통에 버릴 수도 있고 // solve(L+1,R)
//													 // 왼쪽 카드와 오른쪽 카드를 둘 다 통에 버릴 수도 있다. // solve(L+1,R+1)
//													 // 이때 얻는 점수 없다.
//
//	if (left[L] > right[R])
//		// 규칙 2. 오른쪽 카드에 적힌 수가 왼쪽 카드에 적힌 수보다 작은 경우에는
//		ret = max(ret, solve(L, R + 1) + right[R]); // 둘 중 최대값을 ret에 입력.
//													// 오른쪽 카드만 통에 버릴 수도 있다. // solve(L,R+1)
//													// 이 때 오른쪽 카드에 적힌 수만큼 점수를 얻는다. // +right[R]
//	return ret; // 최종 점수의 최대값 리턴.
//}
//
//int main()
//{
//	scanf("%d", &N); // 한 더미의 카드의 개수 입력.
//	left.resize(N); // left 리스트 크기 N만큼(0~N-1) 증가.
//	right.resize(N); // right 리스트 크기 N만큼(0~N-1) 증가.
//	memset(memo, -1, sizeof(memo)); // 메모이제이션 변수 배열 -1로 모두 초기화.
//									// -1은 절대 점수로 나올 수 없는 값이기 때문에 초기화 값으로 지정했다.
//	for (int i = 0; i<N; i++)
//		scanf("%d", &left[i]); // 왼쪽 더미 카드 순서대로 입력.
//	for (int i = 0; i<N; i++)
//		scanf("%d", &right[i]); // 오른쪽 더미 카드 순서대로 입력.
//	printf("%d", solve(0, 0)); // 최종 점수의 최대값 출력.
//							   // solve(0,0) 은 왼쪽, 오른쪽 더미 모두 첫번재 카드부터 시작한다는 뜻.
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
