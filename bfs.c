#include<stdio.h>
#include<math.h>
#define SZ 5
void bfs(int mat[][SZ],int n,int start)
{
    int vis[SZ]={0};
    int queue[SZ];
    int rear=0;
    int front=0;
    queue[rear++]=start;
    vis[start]=1;
    while(front<rear)
    {
        int current=queue[front++];
        printf("%d ",current);
        for(int i=0;i<n;i++)
        {
            if(mat[current][i]==1&&vis[i]!=1)
            {
                queue[rear++]=i;
                vis[i]=1;
            }
        }

    }
}
int main(){

    int mat[SZ][SZ];
    for(int i=0;i<SZ;i++)
    {
        for(int j=0;j<SZ;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    bfs(mat,SZ,0);
    return 0;
}