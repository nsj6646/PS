//#include <iostream>
//#include <vector>
//using namespace std;
//
//typedef struct {
//	int country;
//	int m[3];
//}country;
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	vector<country> a(n);
//	int idx = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i].country >> a[i].m[0] >> a[i].m[1] >> a[i].m[2];
//		if (a[i].country == k) {
//			idx = i;
//		}
//	}
//
//	int rank = 1;
//
//	for (int i = 0; i < n; i++) {
//		if (a[i].m[0] > a[idx].m[0]) {
//			rank += 1;
//		}
//		else if (a[i].m[0] == a[idx].m[0]) {
//			if(a[i].m[1] > a[idx].m[1]){
//				rank += 1;
//			}
//			else if (a[i].m[1] == a[idx].m[1]) {
//				if (a[i].m[2] > a[idx].m[2]) {
//					rank += 1;
//				}
//			}
//		}
//	}
//
//	cout << rank;
//
//	return 0;
//}

#include <cstdio>
typedef struct {
	int country;	//국가
	int m[3];		//금,은,동
}country;

country a[1000];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int idx = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a[i].country, &a[i].m[0], &a[i].m[1], &a[i].m[2]);
		if (a[i].country == k) {
			idx = i;
		}
	}

	int rank = 1;

	for (int i = 0; i < n; i++) {
		if (a[i].m[0] > a[idx].m[0]) {
			rank += 1;
		}
		else if (a[i].m[0] == a[idx].m[0]) {
			if (a[i].m[1] > a[idx].m[1]) {
				rank += 1;
			}
			else if (a[i].m[1] == a[idx].m[1]) {
				if (a[i].m[2] > a[idx].m[2]) {
					rank += 1;
				}
			}
		}
	}

	printf("%d", rank);

	return 0;
}

