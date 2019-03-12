#define MAXN		1000005
#include <bits/stdc++.h>
using namespace std;

struct Trie {
	int child[26];
	bool term;
	int cnt;
	Trie() {
		memset(child, 0, sizeof(child));
		term = false;
		cnt = 1;
	}
}trie[MAXN];
int TrieIdx;
int newTrie() { return TrieIdx++; }

void insert(int &cur, const char *key) {
	if (*key == 0) {
		trie[cur].cnt += 1;
		trie[cur].term = true;
		return;
	}
	int next = *key - 'a';
	if (!trie[cur].child[next]) {
		trie[cur].child[next] = newTrie();
		trie[cur].term = true;
	}
	insert(trie[cur].child[next], key + 1);
	return;
}
void find(int &cur, const char *key) {
	if (*key == 0) {
		if (trie[cur].cnt >1) {
			cout << trie[cur].cnt;
		}
		return;
	}
	int next = *key - 'a';
	if (!trie[cur].child[next]) {
		cout << *key;
		return;
	}
	cout << *key;
	find(trie[cur].child[next], key + 1);
	return;
}
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int root = newTrie();
	for (int i = 0; i < n; ++i) {
		char str[11];
		cin >> str;
		find(root, str);
		cout << '\n';
		insert(root, str);
	}
	return 0;
}
//#include <bits/stdc++.h>
//#include <unordered_set>
//#include <unordered_map>
//using namespace std;
//
//int n;
//unordered_set<string> used;
//unordered_map<string, int> dict;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> n;
//	for (int i = 0; i < n; ++i) {
//		string s;
//		cin >> s;
//		if (dict.count(s) == 0) {
//			dict[s] = 1;
//		}
//		else {
//			dict[s] += 1;
//			s += to_string(dict[s]);
//			cout << s << '\n';
//			used.insert(s);
//			continue;
//		}
//
//		string pre = "";
//		int j = 0;
//		bool isexist = true;
//		for (j = 0; j < s.size(); ++j) {
//			pre.push_back(s[j]);
//			if (used.count(pre) == 0) {
//				cout << pre << '\n';
//				used.insert(pre);
//				isexist = false;
//				break;
//			}
//		}
//		if (isexist) {
//			cout << s << '\n';
//			continue;
//		}
//		for (j = j + 1; j < s.size(); ++j) {
//			pre.push_back(s[j]);
//			used.insert(pre);
//		}
//	}
//
//	return 0;
//}