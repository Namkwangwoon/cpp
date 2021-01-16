#include <iostream>
using namespace std;

class SinivelCap    // 콧물 처치용 캡슐
{
public:
    void Take() const {cout<<"콧물이 싹~ 납니다."<<endl;}
};

class SneezeCap     // 재채기 처치용 캡슐
{
public:
    void Take() const {cout<<"재채기가 멎습니다."<<endl;}
};

class SnuffleCap    // 코막힘 처치용 캡슐
{
public:
    void Take() const {cout<<"코가 뻥 뚫립니다."<<endl;}
};

class CONTACT600
{
private:
    SinivelCap sin;
    SneezeCap sne;
    SnuffleCap snu;

public:
    void Take() const
    {
        sin.Take();
        sne.Take();
        snu.Take();
    }
};

class ColdPatient
{
public:
    void TakeCONTACT600(const CONTACT600 &cap) const { cap.Take(); }
};

int main(void)
{
    CONTACT600 cap;
    ColdPatient snufferer;
    snufferer.TakeCONTACT600(cap);
    return 0;
}