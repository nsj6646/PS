#define MAXN		10005
#include <bits/stdc++.h>
using namespace std;

struct Trie {
	bool term;
	Trie* child[10];
	Trie() {
		init();
	}
	void init() {
		term = false;
		memset(child, 0, sizeof(child));
	}
}TriePool[MAXN*10];
int TrieIdx;
Trie* newTrie() { return &TriePool[TrieIdx++]; }

void init() {
	TrieIdx = 0;
	for (int i = 0; i < MAXN*10; ++i) {
		TriePool[i].init();
	}
}

void insert(Trie* cur, const char *key) {
	if (*key == 0) {
		cur->term = true;
		return;
	}
	int next = *key - '0';
	if (!cur->child[next]) cur->child[next] = newTrie();
	insert(cur->child[next], key + 1);
}
bool find(Trie *cur, const char *key) {
	if (*key == 0) return false;
	if (cur->term) return true;

	int next = *key - '0';
	return find(cur->child[next], key + 1);
}


char a[MAXN][11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		init();
		Trie *root=newTrie();
		int n;
		cin >> n;
		bool yes = true;

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			insert(root,a[i]);
		}
		for (int i = 0; i < n; ++i) {
			if (find(root,a[i])) {
				yes = false;
				break;
			}
		}
		
		if (yes) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
