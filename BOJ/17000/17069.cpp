#include <bits/stdc++.h>
using namespace std;
#define N       33

typedef long long ll;
int a[N][N];
ll dp[3][N][N];     //0:가로 1: 대각선 2: 세로 경우의 수

int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
        }
    }
    dp[0][1][2]=1;  //시작위치
    for(int i=1;i<=n;++i){
        for(int j=2;j<=n;++j){
            if(a[i][j+1]==0){       //가로로 갈 수있으면
                dp[0][i][j+1]+=dp[0][i][j]+dp[1][i][j];     //가로로 갈 수 있는 경우는 가로->가로, 대각선->가로
            }
            if(a[i][j+1]==0&&a[i+1][j+1]==0&&a[i+1][j]==0){     //대각선으로 갈 수있으면
                dp[1][i+1][j+1]+=dp[0][i][j]+dp[1][i][j]+dp[2][i][j];       //대각선으로 갈 수 있는 경우는 가로->대각선, 대각선->대각선, 세로->대각선
            }
            if(a[i+1][j]==0){       //세로로 갈 수있으면
                dp[2][i+1][j]+=dp[1][i][j]+dp[2][i][j];     //세로로 갈 수 있는 경우는 세로->세로, 대각선->세로
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<dp[0][i][j]+dp[1][i][j]+dp[2][i][j]<<' ';
        }
        cout<<'\n';
    }
    ll ans=dp[0][n][n]+dp[1][n][n]+dp[2][n][n];     //모든 경우의 수 더하기
    cout<<ans;
    return 0;
}