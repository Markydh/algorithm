#include<stdio.h>



void swap(int* a,int *b){
    int mid;
    mid=*a;
    *a=*b;
    *b=mid;
}

int main(){ 
    int m,n;// m表示第一组数的个数,n表示第一组数的个数
    int count=0;//记录合并后多项式的项数
    scanf("%d",&m);
    int arr1[m];
    for(int i=0;i<m;i++)
    scanf("%d",&arr1[i]);
    scanf("%d",&n);
    int arr2[n];
    int ans[m+n];//相加后的数组
    int result[m+n];//取消重复元素后的数组
    for(int i=0;i<n;i++)
    scanf("%d",&arr2[i]);
    for(int i=0;i<m;i++){
        ans[i]=arr1[i];
    }
    for(int i=m;i<m+n;i++){
        ans[i]=arr2[i-m];
    }  //将两组数连接
    for(int i=0;i<m+n-1;i++)
    for(int j=0;j<m+n-1-i;j++){
        if(ans[j]<ans[j+1])
        swap(&ans[j],&ans[j+1]);
    }//排序使其降序排序
    int k=0;
    while(k<m+n){
        if(k==m+n-1)result[count++]=ans[k++];
        else if(ans[k]!=ans[k+1])result[count++]=ans[k++];
        else k++;
    }//去重
    for(int i=0;i<count;i++){
        printf("%d ",result[i]);
    }
}