/*
 * boj 3184: 양 
 * copyright: nsj6646@naver.com
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE    255
#define SAFE(x,y)   (x)>=0&&(x)<r&&(y)>=0&&(y)<c
typedef pair<int,int> point;
int r,c;
char a[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int totalV=0,totalO=0;
queue<point> q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void bfs(int i,int j){
    int cntV=0,cntO=0;
    if (a[i][j] == 'v') cntV++;
    else if (a[i][j] == 'o')cntO++;
    visited[i][j]=true;
    q.push({i,j});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int d=0;d<4;++d){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(SAFE(x,y)&&a[nx][ny]!='#'&&!visited[nx][ny]){
                visited[nx][ny]=true;
                if(a[nx][ny]=='v') cntV++;
                else if(a[nx][ny]=='o') cntO++;
                q.push({nx,ny});
            }
        }
    }
    if(cntV>=cntO){
        totalO-=cntO;
    }
    else{
        totalV-=cntV;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    cin>>r>>c;
    for(int i=0;i<r;++i){
        cin>>a[i];
        for(int j=0;j<c;++j){
            if(a[i][j]=='v') totalV++;
            else if(a[i][j]=='o') totalO++;
        }
    }
    
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            if(a[i][j]!='#'&&!visited[i][j]){
                bfs(i,j);
            }
        }
    }
    cout<<totalO<<' '<<totalV;
    return 0;
}