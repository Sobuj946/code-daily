#include<stdio.h>
#include<math.h>
void insertion_sort(int ar[],int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=ar[i];
        int j=i-1;
        while(j>=0&&ar[j]>temp)
        {
            ar[j+1]=ar[j];
            j--;
        }
        
        ar[j+1]=temp;
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
    insertion_sort(ar,n);
    return 0;
}