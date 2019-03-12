#define N 1000005
#include <bits/stdc++.h>

char parent[N];
char pattern[N];
int parentHash;
int patternHash;
int power = 1;

bool naive_check(int i, int n) {
	bool equal = true;
	for (int j = 0; j < n; ++j) {
		if (parent[i + j] ^ pattern[j]) {
			equal = false;
			break;
		}
	}
	return equal;
}
int main()
{
	scanf("%s %s", parent, pattern);
	int parentSize = strlen(parent);
	int patternSize = strlen(pattern);
	int ans = 0;

	for (int i = 0; i <= parentSize - patternSize; ++i) {
		if (i == 0) {
			for (int j = 0; j < patternSize; ++j) {
				patternHash = (patternHash << 1) + pattern[j];
				parentHash = (parentHash << 1) + parent[j];
				if (j<patternSize - 1) power <<= 1;
			}
		}
		else {
			parentHash = ((parentHash - parent[i - 1] * power) << 1) + parent[i + patternSize - 1];
		}
		if (parentHash == patternHash) {
			if (naive_check(i, patternSize)) {
				ans = 1;
				break;
			}
		}
	}
	printf("%d", ans);
	return 0;
}