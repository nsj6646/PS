/*
 * boj 2869: 달팽이는 올라가고 싶다
 * copyright: nsj6646@naver.com
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    
    int a,b,v;
    cin>>a>>b>>v;
    /* 
     * 걸린 시간 t
     * at-b(t-1) = v
     * at-bt+b=v
     * (a-b)t=v-b
     * t=(v-b)/(a-b)
     */
    int t=(v-b)/(a-b);
    if((v-b)%(a-b)) t+=1;
    cout<<t;

    return 0;
}