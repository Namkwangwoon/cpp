#include <iostream>
using namespace std;

namespace COMP_POS
{
    enum {CLERK, SENIOR, ASSIST, MANAGER};
    void numToWord(int num){
        switch (num)
        {
        case CLERK:
            cout<<"사원"<<endl<<endl;
            break;
        case SENIOR:
            cout<<"주임"<<endl<<endl;
            break;
        case ASSIST:
            cout<<"대리"<<endl<<endl;
            break;
        case MANAGER:
            cout<<"과장"<<endl<<endl;
            break;
        }
    }
}

class NameCard
{
private:
    char * name;
    char * companyName;
    char * phoneNumber;
    int grade;
public:
    NameCard(char * n, char * cn, char * pn, int g) : grade(g)
    {
        name = new char[strlen(n)+1];
        companyName = new char[strlen(cn)+1];
        phoneNumber = new char[strlen(pn)+1];
        strcpy(name, n);
        strcpy(companyName, cn);
        strcpy(phoneNumber, pn);
    }
    void ShowNameCardInfo()
    {
        cout<<"이름: "<<name<<endl;
        cout<<"회사: "<<companyName<<endl;
        cout<<"전화번호: "<<phoneNumber<<endl;
        cout<<"직급: ";
        COMP_POS::numToWord(grade);
    }
    ~NameCard()
    {
        delete []name;
        delete []companyName;
        delete []phoneNumber;
    }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}