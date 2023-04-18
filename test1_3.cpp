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

    cout<<n<<" "<<m<<endl;
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

/*
输出的第一行为两个正整数m和n，为输出的新矩阵的行数和列数

剩下的输出为新矩阵的内容，共m行，每行n个整数

数据之间用空格分隔

每行数据的最后无空格

最后的一行输出后面无换行符*/