/*
boj 17315: 캐슬 디펜스
*/
#include <bits/stdc++.h>
using namespace std;
#define SAFE(x,y)   (x>=0&&x<n&&y>=0&&y<m)
typedef pair<int,int> point;

int a[15][15];              //입력배열
bool visited[15][15];       //bfs방문체크
bool dead[15][15];          //타겟이 죽었는지 체크
const int dx[]={0,-1,0};
const int dy[]={-1,0,1};
int n,m,d;

vector<int> archer;             //궁수 3명의 위치
point target[3];                //궁수 3명의 타겟을 임시 저장
vector<point> enemy[15][30];    //[궁수위치별][거리별] 적 위치

int ans=0;

int run(){
    memset(dead,0,sizeof(dead));
    int timer=0;
    while(timer<n){                             //처음부터 끝까지 진행
        timer++;
        for(int x=0;x<3;++x){                   //궁수
            target[x]={-1,-1};                  //타겟 초기화
            int limit=timer+d;
            for(int i=timer;i<limit;++i){         //거리
                bool found=false;
                for(point &p:enemy[archer[x]][i]){                               //[궁수위치에서][해당거리]에 있는 적들좌표 p
                    if(n-p.first<timer||dead[p.first][p.second]) continue;                //제외됬거나, 죽었으면 continue
                    target[x]=p;                                      //타겟 임시저장(바로 죽여버리면 중복 타겟 설정이 안되기 때문)
                    found=true;
                    break;
                }
                if(found) break;
            }
        }
        for(int x=0;x<3;++x){
            if(target[x].first==-1) continue;   //죽일 타겟 없으면 continue
            dead[target[x].first][target[x].second]=true;
        }
    }
    int cnt=0;

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(dead[i][j]) cnt++;
        }
    }
    return cnt;
}
void bfs(int idx){
    memset(visited,0,sizeof(visited));
    queue<point> q;
    q.emplace(n-1,idx);
    visited[n-1][idx]=true;
    int dist=1;
    if(a[n-1][idx]) enemy[idx][dist].emplace_back(n-1,idx);     //거리별 적 위치 저장
    
    while(!q.empty()){
        dist++;
        int sz=q.size();
        while(sz--){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int k=0;k<3;++k){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(SAFE(nx,ny)&&!visited[nx][ny]){   
                    q.emplace(nx,ny);
                    visited[nx][ny]=true;
                    if(a[nx][ny]) enemy[idx][dist].emplace_back(nx,ny);     //거리별 적 위치 저장
                }
            }
        }
    }

}
void dfs(int idx,int cnt){
    if(cnt==3){
        int res=run();
        ans=max(ans,res);
        return;
    }
    for(int i=idx;i<m;++i){
        archer.push_back(i);
        dfs(i+1,cnt+1);
        archer.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m>>d;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<m;++i){
        bfs(i);
    }

    dfs(0,0);

    cout<<ans;
    return 0;
}