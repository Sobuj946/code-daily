#include<stdio.h>
#include<math.h>
void selection_sort(int ar[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(ar[j]<ar[min])
            {
                min=j;
            }
        }
        if(i!=min)
        {
            int temp=ar[i];
            ar[i]=ar[min];
            ar[min]=temp;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
}
int main(){

    int n;
    scanf("%d",&n);
    int ar[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    selection_sort(ar,n);
    return 0;
}