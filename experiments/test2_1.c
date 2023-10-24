#include<stdio.h>
#include<string.h>

void strrindex(char s[],char t[]){
    int s_len=strlen(s);//字符s的长度
    int t_len=strlen(t);//字符t的长度
    int s_index=0,t_index=0;
    int ans=0;
    for(int i=0;i<s_len;i++){
        s_index=i;
        t_index=0;
        int judge=1;
        if(s[s_index]==t[t_index]){
            for(int j=1;j<t_len;j++){
                if(s[++s_index]!=t[++t_index]){
                    judge=0;
                    break;
                }
            }
            if(judge&&i>ans)ans=i;
        }
    }
    if(ans==0)printf("%d",-1);
    printf("%d",ans);
}
int main()
{
    char s[1000],t[1000];
    gets(s);
    gets(t);
    strrindex(s,t);
}