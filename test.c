#include<stdio.h>

int main(){ 
    int m,n;// m表示第一个多项式的系数与指数数量,n表示第二个多项式的系数与指数数量 
    int l=1,r=1,k=0;
    int count=0;//记录合并后多项式的项数
    scanf("%d",&m);
    int arr1[m];
    for(int i=0;i<m;i++)
    scanf("%d",&arr1[i]);
    scanf("%d",&n);
    int arr2[n];
    int ans[m+n];//相加后的多项式
    for(int i=0;i<n;i++)
    scanf("%d",&arr2[i]);
    //将多项式信息读入
    while(l<m&&r<n){ 
        if(arr1[l]>arr2[r])//若第一个多项式指数大于第二个,第一个直接写入，并后移两位到第二个指数
        {
            ans[k++]=arr1[l-1];
            ans[k++]=arr1[l];
            l=l+2;
            count=count+2;
        }
        if(arr1[l]<arr2[r])//若第一个多项式指数小于第二个,第二个直接写入，并后移两位到第二个指数
        {
            ans[k++]=arr2[r-1];
            ans[k++]=arr2[r];
            r=r+2;
            count=count+2;
        }
        if(arr1[l]==arr2[r])//若两个多项式指数匹配到
        {
            ans[k++]=arr1[l-1]+arr2[r-1];  //系数相加
            ans[k++]=arr1[l];//系数保留
            l=l+2;
            r=r+2;//同时后移两位到第二个指数
            count=count+2;
        }
    }
    //剩余多项式直接加入
    while(l<m)
    {
        ans[k++]=arr1[l-1];
        ans[k++]=arr1[l];
        l=l+2;
        count=count+2;
    }
     while(r<n)
    {
        ans[k++]=arr2[r-1];
        ans[k++]=arr2[r];
        r=r+2;
        count=count+2;
    }
    //输出新多项式
    for(int i=0;i<count;i++){
        printf("%d ",ans[i]);
    }
}