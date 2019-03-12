#include <iostream>
#include <vector>
#include <algorithm>
#define ABS(x,y) x-y>=0?x-y:y-x
using namespace std;

typedef struct ingredient {
	long long s, b;
}ing;
int n;
long long min_diff(vector<ing> &v,int i,long long muls, long long sumb,bool flag) {
	if (i == n) {
		if (flag) {
			return ABS(muls, sumb);
		}
		else {
			return 99999999;
		}
	}
	long long t1=min_diff(v, i + 1, muls*v[i].s, sumb + v[i].b,true);
	long long t2=min_diff(v, i + 1, muls, sumb,flag);
	long long ans = min(t1, t2);
	return ans;
}
int main()
{
	
	cin >> n;
	vector<ing> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].s >> v[i].b;
	}
	cout<<min_diff(v,0,1,0,0);
	return 0;
}