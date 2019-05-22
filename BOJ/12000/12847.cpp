/*
 * boj 12847: 꿀 아르바이트
 * copyright: nsj6646@naver.com
 */
#include <bits/stdc++.h>
using namespace std;
#define N   100001
long long psum[N];  //구간합을 저장할 배열
int n,m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    int x;

    for(int i=1;i<=n;++i){
        cin>>x;
        psum[i]=psum[i-1]+x;
    }
    
    long long ans=0LL;
    for(int i=m;i<=n;++i){
        ans=max(ans,psum[i]-psum[i-m]); //구간합의 최대를 구함
    }
    cout<<ans;
    return 0;
}