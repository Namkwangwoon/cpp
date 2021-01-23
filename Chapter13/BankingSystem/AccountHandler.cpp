#include "AccountHandler.h"
#include "BankingCommonDecl.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

AccountHandler::AccountHandler()
{
    customerNum=0;
}

int AccountHandler::showMenu()
{
    int num;

    cout << "-----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
    cout << "선택: ";
    cin >> num;

    return num;
}

void AccountHandler::newAccount()
{
    int choice;

    cout << "\n[계좌종류선택]" << endl;
    cout<<"1.보통예금계좌   2.신용신뢰계좌"<<endl;
    cout<<"선택: ";
    cin>>choice;
    if(choice != 1 && choice != 2)
    {
        cout<<"*** 1, 2 중에서 입력하세요 ***"<<endl<<endl;
        return;
    }

    if(choice==1) newNormalAccount();
    else if(choice==2) newCreditAccount();

    return;
}

void AccountHandler::newNormalAccount()
{
    int id;
    char name[NAME_LEN];
    int balance;
    int intRate;

    cout<<"[보통예금계좌 개설]"<<endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "이 름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> balance;
    cout<<"이자율: ";
    cin>>intRate;
    accArr[customerNum++] = new NormalAccount(id, name, balance, intRate);
    cout << endl;
}

void AccountHandler::newCreditAccount()
{
    int id;
    char name[NAME_LEN];
    int balance;
    int intRate;
    int credit;

    cout<<"[신용신뢰계좌 개설]"<<endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "이 름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> balance;
    cout<<"이자율: ";
    cin>>intRate;
    cout<<"신용등급(1toA, 2toB, 3toC): ";
    cin>>credit;
    accArr[customerNum++] = new CreditAccount(id, name, balance, intRate, credit);
    cout << endl;
}

void AccountHandler::deposit()
{
    int temp;
    int input;

    cout << "\n[입  금]" << endl;
    cout << "계좌ID: ";
    cin >> temp;
    for (int i = 0; i < customerNum; i++)
    {
        if (temp == accArr[i]->getAccount())
        {
            cout << "입금액: ";
            cin >> input;
            accArr[i]->deposit(input);
            cout << "입금완료\n"<< endl;
            return;
        }
    }

    cout << "*** 유효하지 않은 계좌ID 입니다. ***" << endl
         << endl;
    return;
}

void AccountHandler::withdraw()
{
    int temp;
    int withdraw;

    cout << "\n[출  금]" << endl;
    cout << "계좌ID: ";
    cin >> temp;
    for (int i = 0; i < customerNum; i++)
    {
        if (temp == accArr[i]->getAccount())
        {
            cout << "출금액: ";
            cin >> withdraw;
            if (withdraw > accArr[i]->getBalance())
            {
                cout << "*** 잔액이 부족합니다. ***" << endl<< endl;
                return;
            }
            accArr[i]->withdraw(withdraw);
            cout << "출금완료\n"<< endl;
            return;
        }
    }

    cout << "*** 유효하지 않은 계좌ID 입니다. ***" << endl
         << endl;
    return;
}

void AccountHandler::showAll()
{
    for (int i = 0; i < customerNum; i++)
    {
        cout << "\n계좌ID: " << accArr[i]->getAccount() << endl;
        cout << "이 름: " << accArr[i]->getName() << endl;
        cout << "잔 액: " << accArr[i]->getBalance() << endl;
    }
    cout << endl;
}

AccountHandler::~AccountHandler()
{
    for(int i=0; i<customerNum; i++)
        delete accArr[i];
}