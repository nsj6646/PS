#include <cstdio>
const int sz = 38 * 4;

char str[40];
char binCode[sz+1];
char bin[16][5] = { "0000", "0001", "0010","0011", "0100", "0101", "0110","0111","1000","1001","1010","1011" ,"1100","1101","1110","1111" };
char countbits[11];
int ansCnt, ansStr[100];
int btoi() {
	int ret = 0;
	for (int i = 0; countbits[i]; ++i) {
		if (countbits[i] == '1') {
			ret += 1;
		}
		else {
			ret <<= 1;
		}
	}
	return ret;
}
void init() {
	ansCnt = 0;
	ansStr[0] = 0;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int code;
		for (int i = 0; i < 38; ++i) {
			scanf("%1x", &code);
			for (int j = 0; j < 4; ++j) {
				binCode[i * 4 + j] = bin[code][j];
			}
		}
		//printf("%s", bcode);
		int idx = 0;
		while (idx < sz) {
			if (binCode[idx] == '1') {
				/*Numeric*/
				idx += 4;
				for (int i = 0; i < 10; ++i) {
					countbits[i] = binCode[idx++];
				}
				countbits[10] = 0;
				int cnt = btoi();
				ansCnt += cnt;
				int p = cnt / 3;
				int q = cnt % 3;
				for (int i = 0; i < p; ++i) {
					for (int j = 0; j < 10; ++j) {
						countbits[j] = binCode[idx++];
					}
					countbits[10] = 0;
					int num= btoi();
					ito
				}
			}
			else if (binCode[idx + 1] == '1') {
				/*Alphanumeric*/
				idx += 4;

			}
			else if (binCode[idx + 2] == '1') {
				/*8 bit byte*/
				idx += 4;

			}
			else if (binCode[idx + 3] == '1') {
				/*Kanji*/
				idx += 4;

			}
			else {
				/*Termination*/
				idx += 4;

			}
		}
		printf("\n");
	}
	return 0;
}
//#include <iostream>
//#include <string>
//#include <cstdio>
//using namespace std;
//
//int Answer;
//string ans;
//string alphanumeric = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";
//
//string to_bin(string hex) {
//	string b = "";
//	for (int i = 0; i < hex.size(); i++) {
//		int x;
//		if (hex[i] >= '0'&&hex[i] <= '9') {
//			x = hex[i] - '0';
//		}
//		else {
//			x = hex[i] - 'A' + 10;
//		}
//		string bs = "0000";
//		int idx = 3;
//		while (x > 0) {
//			bs[idx] = (x % 2) + '0';
//			x /= 2;
//			idx -= 1;
//		}
//		b += bs;
//	}
//	return b;
//}
//int to_demi(string b) {
//	int d = 0;
//	for (int i = 0; i < b.size(); i++) {
//		d = d << 1;
//		d += b[i] - '0';
//	}
//	return d;
//}
//int main(int argc, char** argv)
//{
//	int T, test_case;
//	cin >> T;
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		ans = "";
//		Answer = 0;
//
//		string a;
//		cin >> a;
//		if (a.substr(0, 4) == "EC11") {
//			cout << "Case #" << test_case + 1 << endl;
//			cout << Answer << ' ' << ans << '\n';
//			continue;
//		}
//		string bin = to_bin(a);
//
//		int p = 0;
//
//		while (p <= 148) {
//			string mode = bin.substr(p, 4);
//			p += 4;
//			string count;
//			if (mode == "0000") {
//				/*Termination*/
//				break;
//			}
//			else if (mode == "0001") {
//				/*Numeric*/
//				count = bin.substr(p, 10);
//				p += 10;
//
//				int cnt = to_demi(count);
//				Answer += cnt;
//				int q = cnt / 3;
//				int r = cnt % 3;
//				for (int i = 1; i <= q; i++) {
//					string s = bin.substr(p, 10);
//					p += 10;
//					ans += to_string(to_demi(s));
//				}
//				if (r == 1) {
//					string s = bin.substr(p, 4);
//					p += 4;
//					ans += to_string(to_demi(s));
//				}
//				else if (r == 2) {
//					string s = bin.substr(p, 7);
//					p += 7;
//					ans += to_string(to_demi(s));
//				}
//			}
//			else if (mode == "0010") {
//				/*Alphanumeric*/
//				count = bin.substr(p, 9);
//				p += 9;
//				int cnt = to_demi(count);
//				Answer += cnt;
//				if (cnt % 2 == 0) {
//					for (int i = 1; i <= cnt; i += 2) {
//						string s = bin.substr(p, 11);
//						p += 11;
//						int alnum = to_demi(s);
//						int q = alnum / 45;
//						int r = alnum % 45;
//						ans.push_back(alphanumeric[q]);
//						ans.push_back(alphanumeric[r]);
//					}
//				}
//				else {
//					for (int i = 1; i < cnt; i += 2) {
//						string s = bin.substr(p, 11);
//						p += 11;
//						int alnum = to_demi(s);
//						int q = alnum / 45;
//						int r = alnum % 45;
//						ans.push_back(alphanumeric[q]);
//						ans.push_back(alphanumeric[r]);
//					}
//					string s = bin.substr(p, 6);
//					p += 6;
//					int alnum = to_demi(s);
//					ans.push_back(alphanumeric[alnum]);
//				}
//			}
//			else if (mode == "0100") {
//				/*8 bite byte*/
//				count = bin.substr(p, 8);
//				p += 8;
//				int cnt = to_demi(count);
//				Answer += cnt;
//				for (int i = 1; i <= cnt; i++) {
//					string s = bin.substr(p, 8);
//					p += 8;
//
//					int x = to_demi(s);
//					if (x >= 0x20 && x <= 0x7e) {
//						if (x == '\\') {
//							ans.push_back('\\');
//							ans.push_back('\\');
//						}
//						else if (x == '#') {
//							ans.push_back('\\');
//							ans.push_back('#');
//						}
//						else {
//							ans.push_back((char)x);
//						}
//					}
//					else {
//						char c[3];
//						sprintf(c, "%X", x);
//						ans.push_back('\\');
//						ans.push_back(c[0]);
//						ans.push_back(c[1]);
//					}
//				}
//			}
//			else if (mode == "1000") {
//				/*Kanji*/
//				count = bin.substr(p, 8);
//				p += 8;
//				int cnt = to_demi(count);
//				Answer += cnt;
//				for (int i = 1; i <= cnt; i++) {
//					string b = bin.substr(p, 1);
//					p += 1;
//					string s = bin.substr(p, 12);
//					p += 12;
//					int x = to_demi(s);
//					char kanji[4];
//					sprintf(kanji, "%X", x);
//					ans.push_back('#');
//					ans += b;
//					ans.push_back(kanji[0]);
//					ans.push_back(kanji[1]);
//					ans.push_back(kanji[2]);
//				}
//			}
//		}
//
//		cout << Answer << ' ' << ans << '\n';
//
//	}
//
//	return 0;
//}