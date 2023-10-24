#include<stdio.h>
#include<string.h>
int main() {
    char s[100];
    char ans[100];
    int s_len;
    FILE * fp1 = fopen("trans.in", "r");//打开输入文件
    FILE * fp2 = fopen("trans.out", "w+");//打开输入文件
    if (fp1==NULL||fp2==NULL) {//若打开文件失败则退出
        puts("不能打开文件！");
        return 0;
    }
    fgets(s,100,fp1);
    fclose(fp1);
    s_len=strlen(s);
    //读取字符串
    // df23adfd56 2343？23dgjop535
    int num=0;
    int count=0;
    for(int i=0;i<s_len;i++){
        if(s[i]>='0'&&s[i]<='9')
        ans[num++]=s[i];
        if((s[i-1]>='0'&&s[i-1]<='9')&&(s[i]<'0'||s[i]>'9'))
        {
            count++;
            ans[num++]=' ';
        }
    }
    ans[num++]='\n';
    ans[num]='\0';
    char a[3];
    a[0]=count+'0';
    a[1]='\n';
    a[2]='\0';
    fputs(a,fp2);
    fputs(ans,fp2);
    fclose(fp2);
}
