#include<stdio.h>

int main(){ 
    int m,n;// m表示第一组数数量,n表示第二组数数量
    int num=0;
    scanf("%d",&m);
    int arr1[m];
    for(int i=0;i<m;i++)
    scanf("%d",&arr1[i]);
    scanf("%d",&n);
    int arr2[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr2[i]);
    int ans[m+n];
    //将数组信息读入

    for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){
        if(arr1[i]== arr1[j]){
            for(int k=j;k<m-1;k++){
                arr1[k]=arr1[k+1];
            }
            j--;
            m--;
        }//有重复的,重复元素下标是j，后续元素左移覆盖重复元素
    }
    }//第一个数组去重
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
        if(arr1[i]==arr2[j]){
            ans[num++]=arr1[i];
            break;
        }
    }
    
    if(num==0)printf("No Answer");
    else
    {
    for(int i=0;i<num;i++)
    printf("%d ",ans[i]);
    }
}
