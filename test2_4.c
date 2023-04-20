#include<stdio.h>
#include<string.h>
int main() {
    char s[50];
    char t[50];
    int s_len,t_len;
    int index1,index2;//记录重复的起始和末尾下标
    FILE * fp1 = fopen("invertsub.in", "r");//打开输入文件
    FILE * fp2 = fopen("invertsub.out", "w+");//打开输入文件
    if (fp1==NULL||fp2==NULL) {//若打开文件失败则退出
        puts("不能打开文件！");
        return 0;
    }
    fgets(s,50,fp1);
    fgets(t,50,fp1);
    fclose(fp1);
    s_len=strlen(s);
    t_len=strlen(t);
    for(int i=0;i<s_len;i++)if(s[i]=='#'){s[i]='\0';break;}
    for(int i=0;i<t_len;i++)if(t[i]=='#'){t[i]='\0';break;}
    s_len=strlen(s);
    t_len=strlen(t);
    int num=0;
    for(int i=0;i<s_len;i++){
        int judge=1;
        if(s[i]==t[num]){
            int mid=i;
            for(int j=0;j<t_len;j++){
                if(s[mid++]!=t[num++]){
                    judge=0;
                    break;
                }
            }
            if(judge){
            index1=i;
            index2=i+t_len-1;
            break;
        }
        }
        num=0;
    }
    char ex;
    while(index1<index2){
        ex=s[index1];
        s[index1]=s[index2];
        s[index2]=ex;
        index1++;
        index2--;
    }
    fputs(s,fp2);
    fclose(fp2);
}
