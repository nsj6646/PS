/*
 * boj 1005: ACM Craft
 * copyright: nsj6646@naver.com
 */
#include <bits/stdc++.h>
using namespace std;
#define N   1001
typedef pair<int,int> building;     //시간, 건물번호
int n,k;
int ind[N];                 //선행되어야하는 건물 수
int cost[N];                //건물별 건설시간
vector<int> adj[N];         //건물 그래프
int dp[N];                  //건물을 건설하는데 걸리는 총 시간
void topologicalSort(int dst){
    priority_queue<building> pq;
    for(int i=1;i<=n;++i){
        if(ind[i]==0){
            pq.push({-cost[i],i});
            dp[i]=cost[i];
        }
    }

    int t=0;
    while(!pq.empty()){
        int c=-pq.top().first;
        int id=pq.top().second;
        pq.pop();
        for(int i=0;i<adj[id].size();++i){
            int next=adj[id][i];
            ind[next]-=1;
            if(ind[next]==0){
                dp[next]=max(dp[next],dp[id]+cost[next]);       //max를 하는 이유 : 여러 건물들 사이에서 가장 늦게걸리는 건물이 완성됬을 때부터 다음 건물을 진행할 수 있기 때문에
                pq.push({-dp[next],next});
            }       
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    int T;
    cin>>T;
    for(int tc=1;tc<=T;++tc){
        memset(dp,0,sizeof(dp));
        memset(ind,0,sizeof(ind));
        
        cin>>n>>k;
        int d;
        for(int i=1;i<=n;++i){
            cin>>cost[i];
            adj[i].clear();
        }

        for(int i=1;i<=k;++i){           
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            ind[y]++;
        }
        int w;
        cin>>w;
        topologicalSort(w);
        cout<<dp[w]<<'\n';
    }
    
    
    return 0;
}