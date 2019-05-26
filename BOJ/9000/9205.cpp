/*
 * boj 9205: 맥주 마시면서 걸어가기
 * copyright: nsj6646@naver.com
 */
#include <bits/stdc++.h>
using namespace std;
#define MAXDISTANCE 1000
typedef pair<int,int> point;
point dst;              //목적지
int n;                  //편의점 개수
vector<point> v;        //편의점
bool visited[105];
inline int getDistance(point a, point b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}
bool dfs(int idx){
    point cur=v[idx];
    if(getDistance(cur,dst)<=MAXDISTANCE){
        /* 목적지로 갈 수 있는 상황*/
        return true;   
    }
    if(idx==v.size()){
        /* 편의점을 다 돌았는데도 도착 못한 경우 */
        return false;   
    }
    for(int i=1; i<v.size(); ++i){
        point next=v[i];
        if(!visited[i]&&getDistance(cur,next)<=MAXDISTANCE){
            /* 아직 방문 안한 편의점 && 갈 수 있는 거리*/
            visited[i]=true;
            if(dfs(i)){
                return true;
            }
            //visited[i]=false;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    int T;
    cin>>T;
    int x,y;
    for(int tc=1;tc<=T;++tc){
        /* initailize */
        memset(visited,false,sizeof(visited));
        v.clear();

        cin>>n;
        cin>>x>>y;
        v.emplace_back(x,y);
        for(int j=0;j<n;++j){
            cin>>x>>y;
            v.emplace_back(x,y);
        }
        cin>>dst.first>>dst.second;
        visited[0]=true;
        if(dfs(0)){
            cout<<"happy\n";
        }
        else{
            cout<<"sad\n";
        }
    }
    return 0;
}