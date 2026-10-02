#include<stdio.h>

int main(){
    int n,m;
    scanf("%d%d", &n, &m);
    int a[n], b[m];
    
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i=0; i<m; i++) {
        scanf("%d", &b[i]);
    }

    int i,j,k;
    i=j=k=0;
    int ar[n+m];
    while(i<n&&j<m)
    {
        if(a[i]<b[j])
        {
            ar[k++]=a[i];
            i++;
        }
        else
        {
            ar[k++]=b[j];
            j++;
        }
    }
    while(i<n)
    {
        ar[k++]=a[i];
        i++;
    }
    while(j<m)
    {
        ar[k++]=b[j];
        j++;
    }
    for(int i=0;i<m+n;i++)
    {
        printf("%d ",ar[i]);
    }
    return 0;
}
