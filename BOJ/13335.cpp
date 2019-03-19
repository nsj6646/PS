#include <bits/stdc++.h>
using namespace std;
#define N   1000
typedef pair<int, int> truck;
int n,w,l;
int cnt;
queue<int> tq;          //최초 트럭들
queue<truck> bq;        //다리 큐<위치,무게> 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);

    cin>>n>>w>>l;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        tq.push(x);
    }
    int ans=0;

    while(cnt<n){
        ans++;
        int sz=bq.size();
        while(sz--){
            truck now=bq.front();
            bq.pop();
            now.first+=1;
            if(now.first>w){
                l+=now.second;
                cnt++;
                continue;
            }
            bq.push(now);
        }
        if(!tq.empty()&&l-tq.front()>=0&&bq.size()<w){
            l-=tq.front();
            bq.push({1,tq.front()});
            tq.pop();
        }
    }
    cout<<ans;
    return 0;
}