#include <stdio.h>
#include<string.h>
char* sub(char arr1[],char arr2[]){
    int len1=strlen(arr1);
    int len2=strlen(arr2);
    int index1=len1-1;
    int index2=len2-1;
        while(index2>=0){
            if(arr1[index1]>=arr2[index2])
            {
                arr1[index1]=arr1[index1]-arr2[index2]+'0';
            }
            else
            {
                arr1[index1]=10+arr1[index1]-arr2[index2]+'0';
                if(arr1[index1-1]=='0')
                {
                    int index=index1;
                    while(arr1[--index]=='0'){
                        arr1[index]='9';
                    }
                    arr1[index]=arr1[index]-'1'+'0';  
                }
                else arr1[index1-1]=arr1[index1-1]-'1'+'0';
            }
            index1--,index2--;
        }
        int count=0;//计算开头有几个0
        for(int i=0;i<len1;i++){
           if(arr1[i]=='0')count++;
           else break;
        }
        for(int j=0;j<len1-count;j++)
        arr1[j]=arr1[j+count];//前移覆盖前面的0
        arr1[len1-count]='\0';
        return arr1;
}//两数字相减

int main()
{
    char arr1[81];//第一组
    char arr2[81];//第二组
    int len1,len2;
    scanf("%s",arr1);
    scanf("%s",arr2);
    len1=strlen(arr1);
    len2=strlen(arr2);

    int count1=0,count2=0;//计算开头有几个0
        for(int i=0;i<len1;i++){
           if(arr1[i]=='0')count1++;
           else break;
        }
        for(int j=0;j<len1-count1;j++)
        arr1[j]=arr1[j+count1];//前移覆盖前面的0
        arr1[len1-count1]='\0';

        for(int i=0;i<len2;i++){
           if(arr2[i]=='0')count2++;
           else break;
        }
        for(int j=0;j<len2-count2;j++)
        arr2[j]=arr2[j+count2]; //前移覆盖前面的0
        arr2[len2-count2]='\0';  //将两个数开头零尽数除去

    len1=strlen(arr1);//重新获取第一个数的长度
    len2=strlen(arr2);//重新获取第二个数的长度
    if(strcmp(arr1,arr2)==0)printf("0");//数字1等于数字2
    else if(len1>len2||((len1==len2)&&strcmp(arr1,arr2)>0)){
        printf("%s",sub(arr1,arr2));
    }//数字1大于数字2
    else{
        printf("-%s",sub(arr2,arr1));
    }//数字2大于数字1
}

