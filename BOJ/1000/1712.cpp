/*
 * boj 1712: 손익분기점
 * copyright: nsj6646@naver.com
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    long long a,b,c;
    
    cin>>a>>b>>c;
    if(b>=c){
        cout<<-1;
    }
    else{
        long long x=a/(c-b)+1;
        cout<<x;

    }
    return 0;
}