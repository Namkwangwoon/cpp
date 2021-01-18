#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
    char * name;
    int age;
public:
    MyFriendInfo(char * n, int a) : age(a)
    {
        name = new char[strlen(n)+1];
        strcpy(name, n);
    }
    void ShowMyFriendInfo()
    {
        cout<<"이름: "<<name<<endl;
        cout<<"나이: "<<age<<endl;
    }
    ~MyFriendInfo()
    {
        delete []name;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char * addr;
    char * phone;
public:
    MyFriendDetailInfo(char * name, int age, char * a, char * p) : MyFriendInfo(name, age)
    {
        addr = new char[strlen(a)+1];
        phone = new char[strlen(p)+1];
        strcpy(addr, a);
        strcpy(phone, p);
    }
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout<<"주소: "<<addr<<endl;
        cout<<"전화: "<<phone<<endl;
    }
    ~MyFriendDetailInfo()
    {
        delete []addr;
        delete []phone;
    }
};

int main(void)
{
    MyFriendDetailInfo friend1("남광운", 25, "Seoul", "010-2073-2647");
    friend1.ShowMyFriendDetailInfo();
    return 0;
}