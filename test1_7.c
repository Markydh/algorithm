#include<stdio.h>
int main()
{
    int n,m;//n行m列
    scanf("%d%d",&n,&m);
    int a[n+1][m+1];//二维数组
    int max;
    int max_r[n+1];//每一行最大值
    int max_c[m+1];//每一行最大值
    int col[n+1][m],row[n][m+1];//每一行最大值所在列，每一列最大值所在行
    for(int i=0;i<n+1;i++)
    for(int j=0;j<m;j++)
    col[i][j]=0;
    for(int j=0;j<m+1;j++)
    for(int i=0;i<n;i++)
    row[i][j]=0;
    //赋值为0
    for(int i=1;i<n+1;i++)
    for(int j=1;j<m+1;j++){
        scanf("%d",&a[i][j]);
    }//输入数据
    if(m==1&&n==1){
         printf("%d %d %d",a[1][1],1,1);
    }
    else {
    for(int i=1;i<n+1;i++)
    {
        max=a[i][1];
        for(int j=1;j<m+1;j++){
            if(a[i][j]>max)max=a[i][j];
        }
        max_r[i]=max;
    }
    for(int j=1;j<m+1;j++)
    {
        max=a[1][j];
        for(int i=1;i<n+1;i++){
            if(a[i][j]>max)max=a[i][j];
        }
        max_c[j]=max;
    }//将每一行每一列最大值读取
    for(int i=1;i<n+1;i++)
    {
        int num=0;
        for(int j=1;j<m+1;j++){
            if(a[i][j]==max_r[i])col[i][num++]=j;
        }      
    }   //将每一行最大值的列数记录
    for(int j=1;j<m+1;j++)
    {
        int num=0;
        for(int i=1;i<n+1;i++){
            if(a[i][j]==max_c[j])row[num++][j]=i;
        }      
    }   //将每一列最大值的行数记录

    for(int i=1;i<n+1;i++)
    {
        for(int j=0;col[i][j]!=0;j++){
            for(int k=0;row[k][col[i][j]]!=0;k++){
                if(row[k][col[i][j]]==i)
                printf("%d %d %d\n",max_r[i],i,col[i][j]);
            }
        }
    }
    }
}