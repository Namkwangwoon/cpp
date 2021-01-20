#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int bullet;     // 장전된 총알의 수
public:
    Gun(int bnum) : bullet(bnum)
    { }
    void Shot()
    {
        cout<<"BBANG!"<<endl;
        bullet--;
    }
};

class Police
{
private:
    int handcuffs;      // 소유한 수갑의 수
    Gun * pistol;       // 소유하고 있는 권총
public:
    Police(int bnum, int bcuff)
        : handcuffs(bcuff)
    {
        if(bnum>0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }
    Police(const Police& police) : handcuffs(police.handcuffs)
    {
        if(police.pistol != NULL)
            pistol = new Gun(*police.pistol);
        else
            pistol = NULL;
    }
    Police& operator=(const Police& police)
    {
        if(pistol != NULL)
            delete []pistol;
        if(police.pistol != NULL)
            pistol = new Gun(*police.pistol);
        else
            pistol = NULL;

        handcuffs = police.handcuffs;

        return *this;
    }
    void PutHandcuff()
    {
        cout<<"SNAP!"<<endl;
        handcuffs--;
    }
    void Shot()
    {
        if(pistol == NULL)
            cout<<"Hut BBANG!"<<endl;
        else
            pistol->Shot();
    }
    ~Police()
    {
        if(pistol!=NULL)
            delete pistol;
    }
};

int main(void)
{
    Police pman1(5, 3);
    Police pman2 = pman1;   // 복사 생성자의 호출
    pman2.PutHandcuff();
    pman2.Shot();

    Police pman3(2, 4);
    pman3 = pman1;      // 대입 연산자의 호출
    pman3.PutHandcuff();
    pman3.Shot();
    return 0;
}