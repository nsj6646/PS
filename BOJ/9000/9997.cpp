#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;

typedef unsigned long ul;

vector<ul> acc;

ul bitmasking(string s) {
	bitset<26> ret;
	for (char c:s){
		ret.set(c-'a', true);
	}
	return ret.to_ulong();
}
ul bitmasking(vector<int> v) {
	int size = v.size();
	bitset<26> ret;
	for (int i=0;i<size;i++){
		if (v[i] == 1) {
			ret.set(i, true);
		}
	}
	return ret.to_ulong();
}
bool isalready(ul word) {
	for (ul &x : acc){
		if ((x&word)==x) {
			return true;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<ul> v(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v[i] = bitmasking(s);	//비트마스킹된 문자열이 들어갑니다.
	}

	//sort(v.begin(), v.end());
	
	int ans = 0;
	
	for (int bit = 1; bit <= n; bit++) {
		vector<int> b(n);
		//조합 초기화
		for (int i = 0; i < bit; i++) {
			b[i] = 1;
		}
		for (int i = bit; i < n; i++) {
			b[i] = 0;
		}
		do {
			for (int x : b) {
				cout << x << ' ';
			}
			cout << '\n';
			ul wordcombi = bitmasking(b);
			cout <<"wordcombi : "<< wordcombi << '\n';
			//기존에 조합으로 성공한 케이스가 있으면 패스
			if (isalready(wordcombi)) {
				cout << "존재함\n";
				ans += 1;
				continue;
			}

			ul alpha = 0;
			for (int i = 0; i < n; i++) {
				if (b[i] == 1) {
					alpha |= v[i];
				}
			}
			if (alpha==((1<<26)-1)) {	//accept
				cout <<"accept: " <<wordcombi << '\n';
				acc.push_back(wordcombi);
				ans += 1;
			}
		} while (prev_permutation(b.begin(), b.end()));
	}
	cout << ans;
	return 0;
}