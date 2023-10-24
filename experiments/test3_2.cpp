#include  <iostream>
using  namespace  std;
class  Clock        //时钟类声明
{
public:        //外部接口
        Clock(int  NewH=0,  int  NewM=0,  int  NewS=0);
        void  ShowTime();
         Clock  operator  ++();//前置单目运算符重载
         Clock operator ++(int x);//后置单目运算符重载
         Clock operator +(const Clock &c); //+运算符重载          
private:        //私有数据成员
        int  Hour,  Minute,  Second;
};

Clock::Clock(int NewH,int NewM,int NewS){
   Hour=NewH;
   Minute=NewM;
   Second=NewS;
}

Clock Clock::operator++(){
   this->Second++;
   if(this->Second==60){
      this->Second=0;
      this->Minute++;
      if(this->Minute==60){
         this->Minute=0;
         this->Hour++;
         if(this->Hour==24)
         this->Hour=0;
      }
   }
   return *this;
}

Clock Clock::operator++(int x){
   this->Second++;
   if(this->Second==60){
      this->Second=0;
      this->Minute++;
      if(this->Minute==60){
         this->Minute=0;
         this->Hour++;
         if(this->Hour==24)
         this->Hour=0;
      }
   }
   return *this;
}

 Clock Clock::operator +(const Clock &c){
    this->Second+=c.Second;
    if(this->Second>=60){
       this->Second=this->Second-60;
       this->Minute++;
       this->Minute+=c.Minute;
       if(this->Minute>=60){
          this->Minute=this->Minute-60;
          this->Hour++;
          this->Hour+=c.Hour;
          if(this->Hour>=24){
             this->Hour=this->Hour-24;
          }
       }
    }
    return *this;
 }

void  Clock::ShowTime()
{    
      cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
}

int  main()
{
        Clock  c1(23,59,59),c2(5,12,10),c3;
        c1.ShowTime();
        c1++;
        c1.ShowTime();
        c3=++c2;
        c3.ShowTime();
        c3=c2+c1;
        c3.ShowTime();
        return  0;
}