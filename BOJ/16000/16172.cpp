//#include <cstdio>
//#define SIZE 1000002
//char s[SIZE];
//char k[SIZE];
//int n, m;
//
//int make_key() {
//	int key = 0;
//	int j = 0;
//	for (int i = 0; k[i]; i++) {
//		key = (key<<1)+k[i];
//		m += 1;
//	}
//	return key;
//}
//bool naive_search(int j) {
//	for (int i = 0; i < m; i++) {
//		if (s[j] != k[i]) {
//			return false;
//		}
//		j++;
//	}
//	return true;
//}
//int find_keyword(int key) {
//	int ret = 0;
//	int from = 0;
//	int s_key = 0;
//	for (int i = 0; i < n; i++) {
//		if (i < m) {
//			s_key = (s_key << 1) + s[i];
//			if (i == m - 1) {
//				if (s_key == key) {
//					ret = naive_search(from);
//					if (ret == 1) {
//						return 1;
//					}
//				}
//			}			
//			continue;
//		}
//		s_key = ((s_key - (s[from++] << (m - 1)))<<1) + s[i];
//		if (s_key == key) {
//			ret = naive_search(from);
//			if (ret == 1) {
//				return 1;
//			}
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char c;
//	int idx = 0;
//	while ((c = getchar()) && c != '\n') {
//		if (c >= '0'&&c <= '9') continue;
//		s[idx++] = c;
//	}
//	n = idx;
//	s[idx] = 0;
//	scanf("%s", k);
//
//	int key = make_key();
//
//	printf("%d", find_keyword(key));
//
//	return 0;
//}