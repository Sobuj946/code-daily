#include<stdio.h>
#include<math.h>
#define size 4
void dfs(int mat[][size],int start)
{
    int stack[size];
    int vis[size]={0};
    int top=-1;
    stack[++top]=start;
    while(top!=-1)
    {
        int current=stack[top--];
        if(vis[current]!=1)
        {
            printf("%d ",current);
            vis[current]=1; 
        }
        for(int i=size-1;i>=0;i--)
        {
            if(mat[current][i]==1&&vis[i]!=1)
            {
            stack[++top]=i;
            }
            
        }
    }
}
int main(){
    int mat[size][size];
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    dfs(mat,0);
    
    return 0;
}