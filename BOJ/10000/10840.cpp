//#define MAX_LEN		1500
//#define MOD			(1<<27)-1;
//#define MIN(X,Y)	(X)>(Y)?(Y):(X)
//#include <cstdio>
//
//char a[MAX_LEN + 1];
//
//int aLen;
//int aHash[MAX_LEN];
//int subA;
//
//char b[MAX_LEN + 1];
//int bLen;
//int bHash[MAX_LEN];
//int subB;
//
//int hashLen = 1;
//int ans;
//
//int alphaCnt[26];
//int getHash(char x) {
//	return (1 << (x - 'a'));
//}
//bool naiveCheck(int x, int y) {
//	register int i;
//	for (i = 0; i < 26; ++i) {
//		alphaCnt[i] =  0;
//	}
//	for (i = 0; i < hashLen; ++i) {
//		++alphaCnt[a[x+i]-'a'];
//		--alphaCnt[b[y+i]-'a'];
//	}
//	for (i = 0; i < 26; ++i) {
//		if (alphaCnt[i]) {
//			return false;
//		}
//	}
//	return true;
//}
//
//int collision;
//int main()
//{
//
//	scanf("%s", a);
//	scanf("%s", b);
//	register int i, j;
//	for (i = 0; a[i]; ++i) {
//		++aLen;
//	}
//	for (j = 0; b[j]; ++j) {
//		++bLen;
//	}
//
//	for (i = 0; i < aLen; ++i) {
//		if (i == 0)aHash[i] = getHash(a[i]);
//		aHash[i] = (aHash[i - 1] + getHash(a[i]))&MOD;
//	}
//	for (j = 0; j < bLen; ++j) {
//		if (i == 0)bHash[j] = getHash(b[j]);
//		bHash[j] = (bHash[j - 1] + getHash(b[j]))&MOD;
//	}
//
//	while (hashLen <= aLen && hashLen <= bLen) {
//		for (i = 0; i <= aLen - hashLen; ++i) {
//			if (hashLen == 1) subA = getHash(a[i]);
//			else {
//				if (i == 0)subA = aHash[i + hashLen - 1];
//				else {
//					subA = aHash[i + hashLen - 1] - aHash[i - 1];
//					if (subA < 0) subA + MOD;
//				}
//			}
//			for (j = 0; j <= bLen - hashLen; ++j) {
//				if (hashLen == 1) subB = getHash(b[j]);
//				else {
//					if (j == 0) subB = bHash[j + hashLen - 1];
//					else {
//						subB = bHash[j + hashLen - 1] - bHash[j - 1];
//						if (subB < 0) subB + MOD;
//					}
//				}
//				if (subA == subB) {
//					++collision;		
//					if (naiveCheck(i, j)) {
//						ans = hashLen;
//					}
//				}
//			}
//		}
//		++hashLen;
//	}
//	printf("%d\n", ans);
//	printf("collision: %d\n", collision);
//	return 0;
//}