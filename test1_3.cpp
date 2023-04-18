#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;//m行n列
    int a[m][n];
    int b[n][m];
    cout.setf(ios::left);
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
        cin>>a[i][j];
    //给矩阵赋值
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
        b[j][m-i-1]=a[i][j];
    }

    cout<<n<<" "<<m<<endl;//输出新矩阵的
    //将原来的数组第i行变成第m-i列
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<m;j++)
    {
        if(j==m-1)
        cout<<b[i][j];
        else cout<<b[i][j]<<" ";
    }
    if(i==n-1);
    else
    cout<<endl;
    }
    }
