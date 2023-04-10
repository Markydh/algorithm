#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//定义student类
class Student{
    private:
    std::string name;
    int math;
    int english;
    int chinese;
    public:
    string getName();
    int getMath();
    int getEnglish();
    int getChinese();
    void setName(string);
    void setMath(int);
    void setEnglish(int);
    void setChinese(int);
};

//为类中函数定义
void Student::setName(string s)
{
  name=s;
};

void Student::setMath(int x)
{
  math=x;
};

void Student::setEnglish(int x)
{
  english=x;
};

void Student::setChinese(int x)
{
  chinese=x;
};

string Student::getName()
{
  return name;
};

int Student::getMath()
{
  return math;
};

int Student::getEnglish()
{
  return english;
};

int Student::getChinese()
{
  return chinese;
};


//判断函数
bool compare(Student stu1,Student stu2){
  int sum1=stu1.getMath()+stu1.getEnglish()+stu1.getChinese();
  int sum2=stu2.getMath()+stu2.getEnglish()+stu2.getChinese();
  string name1=stu1.getName();
  string name2=stu2.getName();
  if(sum1>sum2)return true;   //如果stu1总分高则返回stu1.即按总分由高到低排序
  if(sum1<sum2)return false;
  if(sum1==sum2){    //如果两者分数相同则进一步分析
    if(stu1.getChinese()>stu2.getChinese())return true;  //总分相同时按语文由高到低排序
    if(stu1.getChinese()<stu2.getChinese())return false;
    if(stu1.getChinese()==stu2.getChinese()){
      if(stu1.getMath()>stu2.getMath())return true;     //总分相同且语文分数一样按数学高到低排序
      if(stu2.getMath()<stu2.getMath())return false;
      if(stu1.getMath()==stu2.getMath()){
        if(strcmp(name1.c_str(),name2.c_str())<0)return true;      //前面条件都一样，则姓名按字典序排序
        else return false;
      }
    }
  }
  return true;
}

int main(){
  int N;  //N个同学的信息
  int m,e,c,ans;   //m表示数学分数，e表示英语分数，c表示语文分数，ans为需要查看的学生序号
  string s;      //表示姓名
  cin>>N;     
  Student stu[N+1];   //创建stu学生数组
  for(int i=1;i<N+1;i++){
    cin>>s;
    cin>>m;
    cin>>e;
    cin>>c;
    stu[i].setName(s);
    stu[i].setMath(m);
    stu[i].setEnglish(e);
    stu[i].setChinese(c);
  }
  sort(stu+1,stu+N+1,compare);  //按自定义函数compare的规则排序
  cin>>ans;
  cout<<stu[ans].getName()<<" "<<stu[ans].getMath()+stu[ans].getEnglish()+stu[ans].getChinese();
  return 0;
}


