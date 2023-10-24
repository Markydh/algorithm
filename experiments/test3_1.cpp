#include<iostream>
using namespace std;
int n;//n  0~9
int visit[10];//记录每个数是否已访问
int ans[10];//记录每组结果

void dfs(int dep){
    //终止条件
    if(dep==n+1){
        for(int i=1;i<=n;i++)
        cout<<"  "<<ans[i];
        cout<<endl;
    }
    //1.枚举方案数
    for(int i=1;i<=n;i++){ 
        //2.若元素未访问，则写入
        if(0==visit[i]){
            visit[i]=1;//改变选中状态
            ans[dep]=i;//搜索当前层
            dfs(dep+1);//搜索下一层
            ans[dep]=0;//回溯
            visit[i]=0;//回溯
        }
    }
}
int main(){
    cin>>n;
    dfs(1);
    return 0;
}