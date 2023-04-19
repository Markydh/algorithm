#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[100];
    scanf("%s",str1);
    scanf("%s",str2);//输入两个字符串
    int len1=strlen(str1);
    int len2=strlen(str2);
    char ans[len1+len2+1];
    int i=0,j=0,num=0;
    while(i<len1&&j<len2){
        if(str1[i]<=str2[j]){
            ans[num++]=str1[i++];
        }
        if(str1[i]>str2[j]){
            ans[num++]=str2[j++];
        }
    }
    while(i<len1){
        ans[num++]=str1[i++];
    }
     while(j<len2){
        ans[num++]=str2[j++];
    }
    ans[num]='\0';
    printf("%s",ans);

}