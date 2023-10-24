#include<stdio.h>
void itob(int n,char s[],int b){
    int i=0,x;
    int m=n>0?n:-1*n;
    while(m!=0){
        x=m%b;
        if(x>=0&&x<=9)s[i++]=x+'0';
        else s[i++]=x-10+'a';
        m=m/b;
    }
    if(n<0)s[i++]='-';
    char c;
    for(int j=0;j<i/2;j++){
        c=s[j];
        s[j]=s[i-j-1];
        s[i-j-1]=c;
    } //字符串反转  
    for(int j=0;j<i;j++)
    printf("%c",s[j]);
}

int main()
{
    char s[100]={0};
    int n,b;
    scanf("%d%d",&n,&b);
    itob(n,s,b);
}