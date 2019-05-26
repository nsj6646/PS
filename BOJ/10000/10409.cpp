/*
 * boj 10409: 서버
 * copyright: nsj6646@naver.com
 */
#include <bits/stdc++.h>
using namespace std;

int a[51];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    int n,T;
    cin>>n>>T;
    int ans=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i]+=a[i-1];
        if(a[i]<=T) ans=i;

    }
    cout<<ans;  


    return 0;
}