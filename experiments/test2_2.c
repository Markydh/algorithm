#include<stdio.h>
#include<string.h>
int main() {
    char s[100];
    char t[100];
    gets(s);
    gets(t);
    int s_len=strlen(s);
    int t_len=strlen(t);
    int judge=1;
    int j=t_len-1;
    for(int i=s_len-1;i>s_len-1-t_len;i--){
        if(s[i]!=t[j--])
        {
            judge=0;
            break;
        }
    }
    if(judge)printf("Yes");
    else printf("No");
}
