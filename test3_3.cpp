#include  <iostream>
using  namespace  std;
class  myCArray
{
private:
    int*  p_arr;
    int  size;
public:
    myCArray();  //缺省构造函数
    myCArray(int*  p_a,int  s);  //构造函数
    myCArray(const  myCArray  &r_other);//复制构造函数
    ~myCArray();//析构函数
    int  operator[](int  pos)  const;  //访问数组元素值的下标运算符重载函数    
    int&  operator[](int  pos);  //设置数组元素值的下标运算符重载函数
    myCArray operator+(const myCArray &right);//对运算符+重载
    myCArray operator-(const myCArray &right);//对运算符-重载
    void  print()  const;
};

myCArray::myCArray(){};

myCArray::myCArray(int * p_a,int s){
    p_arr=new int[s];
    p_arr=p_a;
    size=s;
}
myCArray::myCArray(const  myCArray  &r_other){
    p_arr=new int[r_other.size];
    p_arr=r_other.p_arr;
    size=r_other.size;
}
 myCArray::~myCArray(){
 }

int  myCArray::operator[](int  pos)  const{
    return p_arr[pos];
} 

int& myCArray::operator[](int  pos){
    return p_arr[pos];
} 

myCArray myCArray::operator+(const myCArray &right){
    myCArray ans;
    ans.p_arr=new int[this->size];
    ans.size=this->size;
    int i=0;
    for(;i<this->size;i++)
    {
        ans.p_arr[i]=this->p_arr[i]+right.p_arr[i];
    }
    return ans;
}
myCArray myCArray::operator-(const myCArray &right){
    myCArray ans1;
    ans1.p_arr=new int[this->size];
    ans1.size=this->size;
    int i=0;
    for(;i<this->size;i++)
    {
        ans1.p_arr[i]=this->p_arr[i]-right.p_arr[i];
    }
    return ans1;
}

void  myCArray::print()  const
{
    for(int  i=0;i<this->size  ;i++)
        cout<<this->p_arr[i]<<" ";
    cout<<endl;
}

int  main()
{      
    int  a[5]={1,2,3,4,5},b[5]={1,1,1,1,1};
    myCArray  t1(a,5),t2(b,5),t3;
    t3=t1+t2;
    t3.print();
    t3=t1-t2;
    t3[4]=1000;
    t3.print();
    return  0;
}
