#include <stdio.h>
#include<string.h>
int ans[100];
int main()
{
    int m,n;//两组 数字个数
    int num=0;//记录不同与第二个数组的元素个数
    scanf("%d",&m);
    int arr1[m];
    for(int i=0;i<m;i++)scanf("%d",&arr1[i]);
    scanf("%d",&n);
    int arr2[n];
    for(int i=0;i<n;i++)scanf("%d",&arr2[i]);
    for(int i=0;i<m;i++)
    {
        int judge=1;
        for(int j=0;j<n;j++)if(arr1[i]==arr2[j]){
            judge=0;
            break;
        }
        if(judge)ans[num++]=arr1[i];
    }
    for(int i=0;i<num-1;i++)
    for(int j=0;j<num-1-i;j++)
    {
        if(ans[j]>ans[j+1]){
            int mid=ans[j];
            ans[j]=ans[j+1];
            ans[j+1]=mid;
        }
    }
    for(int i=0;i<num;i++)
    printf("%d ",ans[i]);
}
