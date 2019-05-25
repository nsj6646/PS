/*
 * boj 17252: 삼삼한 수
 * copyright: nsj6646@naver.com
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    /* 
     * 3으로 나누어 떨어지지 않으면 3^0이 있을 가능성이 있으니 1을 빼본다
     * 그래도 나누어 떨어지지 않으면 NO
     * 나누어 떨어지면 n을 3으로 나눈다
     * 그러면 예를 들어 3^1은 3^0이 된다.
     * 다음 루프때 새로생긴 3^0(원래 3^1)이 있으니까 나누어 떨어지지 않을 때 다시 1을 빼본다.
     */ 
    int n;
    cin>>n;
    bool one=false;
    if(n==0){
        cout<<"NO";
        return 0;
    }
    while(n>0){
        if(n%3){
            if(one){
                cout<<"NO";
                return 0;
            }
            n -= 1;
            one = true;
            continue;
        }
        n/=3;
        one=false;
    }
    cout<<"YES";
    return 0;
}