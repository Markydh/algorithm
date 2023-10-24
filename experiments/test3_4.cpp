#include<iostream>
#include<cstring>
using namespace std;

//f函数判断两个字符是否相等
int f(char left,char right){
    if(tolower(left)==tolower(right))return 1;
    return 0;
}

void del(string arr){
    int len;//记录字符串的长度
    char ans[100];//记录最后结果
    int idx=0,i=0;//arr字符串的下标
    len=arr.length();
    //从头遍历字符串
    //如果字符从未出现过则存入ans字符串中
    //如果字符出现在ans字符串中，则把之前字符所在ans元素替换成最新的字符(区别在于大小写)
    for(;i<len;i++){
        int judge=0;
        for(int j=0;j<i;j++){
            //判断字符是否存在
            if(f(arr[j],arr[i])){
                judge=1;
                break;
            }
        }
        //字符存在
            if(judge){
                for(int k=0;k<idx;k++){
                    //查找此字符在ans的下标并替换之
                    if(f(ans[k],arr[i])){
                        ans[k]=arr[i];
                        break;
                }
            }
        }
        //字符之前并未出现
        else ans[idx++]=arr[i];
    }
    ans[idx]='\0';
    cout<<ans;
}

int main(){
    string ch;//字符串
    cin>>ch;
    del(ch);
    return 0;
}