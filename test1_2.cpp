#include<iostream>
using namespace std;
int main(){
long long n;//n个数字
 cin>>n;
 int a[n+1];
 long long  ans=0;//结果
 a[0]=0;
 long long sum=0;
 for(int i=1;i<n+1;i++){
   cin>>a[i];
   sum+=a[i];
 }  //读取n个数字,对数组求和

 for(int i=1;i<n;i++){
   sum-=a[i];
   ans+=a[i]*sum;
 }
 cout<<ans;
}
