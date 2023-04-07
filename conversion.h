#ifndef conversion_h
#define conversion_h
#include<iostream>
#include<cmath>
using namespace std;

int conversion(int n,string num)//n进制转换为十进制
{
  int sum=0;
  for(int i=0;i<num.length();i++){
    sum=n*sum+num[i]-'0';
  }
  return sum;
}
#endif