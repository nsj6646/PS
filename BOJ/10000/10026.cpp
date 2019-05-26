/*
 * boj 10026: 적록색약
 * copyright: nsj6646@naver.com
 */
#include <bits/stdc++.h>
using namespace std;
#define N   101
#define SAFE(x,y)   ((x)>=0&&(x)<n&&(y)>=0&&(y)<n)
int n;
char a[N][N];
bool visited[N][N];
struct point{
    int x,y;
};
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
queue<point> q;

void bfs(char c, int i, int j){
    q.push({i,j});
    visited[i][j]=true;
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        q.pop();
        for(int d=0;d<4;++d){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(a[nx][ny]==c&&SAFE(nx,ny)&&!visited[nx][ny]){
                q.push({nx,ny});
                visited[nx][ny]=true;
            }
        } 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>a[i][j];
        }
    }

    int cnt1=0, cnt2=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(!visited[i][j]){
                cnt1++;
                bfs(a[i][j],i,j);
            }
        }
    }

    memset(visited,false,sizeof(visited));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(a[i][j]=='G'){
                a[i][j]='R';
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(!visited[i][j]){
                cnt2++;
                bfs(a[i][j],i,j);
            }
        }
    }

    cout<<cnt1<<' '<<cnt2;
    return 0;
}