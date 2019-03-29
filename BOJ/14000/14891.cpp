#include <cstdio>
#include <cstring>
int a[5][8];        //톱니바퀴 정보 배열
int pivot[5];       //12시방향에 해당하는 인덱스 정도
bool visited[5];
int k;

void run(int idx,int dir){
    if(idx!=1){
        if(a[idx-1][(pivot[idx-1]+2)%8]^a[idx][(pivot[idx]+6)%8]){
            if(!visited[idx-1]){
                visited[idx-1]=true;
                run(idx-1,dir*-1);
            }
        }
    }

    if(idx!=4){
        if(a[idx][(pivot[idx]+2)%8]^a[idx+1][(pivot[idx+1]+6)%8]){
            if(!visited[idx+1]){
                visited[idx+1]=true;
                run(idx+1,dir*-1);
            }
        }
    }

    pivot[idx]=(pivot[idx]-dir+8)%8;
}
int main()
{
    for(int i=1;i<=4;++i){
        for(int j=0;j<8;++j){
            scanf("%1d",&a[i][j]);
        }
    }
    scanf("%d",&k);

    int idx,dir;
    for(int i=0;i<k;++i){
        scanf("%d %d",&idx,&dir);
        memset(visited,0,sizeof(visited));
        visited[idx]=true;
        run(idx,dir);
    }
    int ans=0;
    int score=1;
    for(int i=1;i<=4;++i){
        if(a[i][pivot[i]]) ans+=score;
        score<<=1;
    }
    printf("%d",ans);
    return 0;
}