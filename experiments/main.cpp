#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int main(){
    map<int,string> person;//定义一个哈希表
    //给map赋值
    //方法1
    person[0]="mark0";
    //方法2
    person.insert(map<int,string>::value_type(1,"mark1"));
    //方法3
    person.insert(pair<int,string>(2,"mark2"));
    
    //读取map中的值
    //方法1
    map<int,string>::iterator it;
    for(it=person.begin();it!=person.end();it++){
        cout<<it->first<<":"<<it->second<<endl;
    }
    //方法2
    for(auto it=person.begin();it!=person.end();it++){
        cout<<it->first<<":"<<it->second<<endl;
    }
    //方法3
    for(auto it : person){
        cout<<it.first<<":"<<it.second<<endl;
    }
    
    //判断数据是否插入成功
    pair<map<int,string>::iterator,bool> pair_vaule;
    pair_vaule=person.insert(pair<int,string>(3,"mark3"));
    cout<<boolalpha<<pair_vaule.second<<endl;
    
    //查找map中的元素
    map<int,string>::iterator it1;
    it1=person.find(1);
    if(it1!=person.end())
    cout<<it1->second<<endl;
    else
        cout<<"not find"<<endl;
    
    //删除map中的元素
    //方法1
    map<int,string>::iterator it2;
    it2 = person.find(1);
    person.erase(it2);
    //方法2 直接通过key值删除元素
    person.erase(2);
    cout<<"------------------------"<<endl;
    for(auto it=person.begin();it!=person.end();it++){
        cout<<it->first<<":"<<it->second<<endl;
    }
    return 0;
}
