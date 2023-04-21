#include <stdio.h>
#include<string.h>

int count[26];//记录26个英文字母每个出现的次数

int main()
{
char s[200];
char ch;
int i=0,max;
int num=0;
while ((ch = getchar()) != EOF)
{
    s[i++]=ch;
}
s[i]='\0';
for(int j=0;j<strlen(s)-1;j++){
    if(s[j]>='a'&&s[j]<='z')count[(s[j]-'a')]++;
}
max=count[0];
for(int k=0;k<26;k++)
{
    if(count[k]>max)max=count[k];
    if(count[k]!=0)num++;
}

for(int j=0;j<25;j++)
for(int k=0;k<25-j;k++)
if(count[k]>count[k+1]){
    int mid=count[k];
    count[k]=count[k+1];
    count[k+1]=mid;
}//冒泡排序将出现的次数排序
for(int k=max;k>0;k--){
    int t=0;
    for(int j=0;j<26;j++)if(count[j]>=k)t++;
    for(int l=0;l<num;l++){
        if(l>=num-t)printf("*");
        else printf(" ");
    }
    printf("\n");
}
}
/*
max=count[0];
for(int k=0;k<26;k++)if(count[k]>max)max=count[k];
*/