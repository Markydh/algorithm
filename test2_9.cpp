#include<iostream> 
using namespace std;

int main( )
{
    int n,m,k;
    cin>>n>>m;
    int a[n][m];//起始数组
    int b[n];//记录数组最右一列
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>a[i][j];//输入数组
    cin>>k;//移动的步数
    while(k--){
        for(int i=0;i<n;i++)b[i]=a[i][m-1];
        for(int i=0;i<n;i++)
        for(int j=m-1;j>0;j--)
            a[i][j]=a[i][j-1];  //第一步
        for(int i=0;i<n-1;i++)
        a[i+1][0]=b[i];
        a[0][0]=b[n-1];
    }
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
    cout<<a[i][j]<<" ";
    cout<<endl;
    }
    return 0;
}