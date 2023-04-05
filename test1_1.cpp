#include <iostream>
#include <math.h>
using namespace std;

//判断是否为素数
bool f(int x){
  for(int i=2;i<sqrt(x);i++){
    if(x%i==0)return false;
  }
  return true;
}

int main()
{
  // 请在此输入您的代码
  int ans,num;
  for(int i=2;i<50000;i++){  //从2开始枚举
    if(f(i)){//筛选出素数，遍历每个素数
      for(int d=1;d<1000;d++){//公差d从1开始
          ans=1;    //记录从每个素数起始素数的个数
          for(int j=1;j<100;j++){
            num=i+j*d;    //第j+1项
            if(f(num)){  //如果num为素数ans++
              ans++;
            }else break;

            if(ans==10)
            {
              cout<<d;
            }
          }
      }   
    }   
  }
  return 0;
}
