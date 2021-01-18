#include <iostream>
#include <cstring>

const int NAME_LEN = 20;

using namespace std;

enum
{
    MAKE = 1,
    DEPOSIT,
    WITHDRAW,
    SHOWALL,
    EXIT
};

enum
{
    NORMAL=1,
    CREDIT
};

enum
{
    A=7,
    B=4,
    C=2
};

class Account
{
private:
    int account;
    char *name;
    int balance;

public:
    Account(int account, char *name, int balance);
    Account(const Account &acc);
    int getAccount() const;
    char *getName() const;
    int getBalance() const;
    virtual void deposit(int amount);
    void withdraw(int amount);
    ~Account();
};

class NormalAccount: public Account
{
private:
    int intRate;
public:
    NormalAccount(int account, char * name, int balance, int intRate) : Account(account, name, balance), intRate(intRate)
    { }
    virtual void deposit(int amount)
    {
        Account::deposit(amount + amount*intRate/100);
    }
};

class CreditAccount: public NormalAccount
{
private:
    int credit;
public:
    CreditAccount(int account, char * name, int balance, int intRate, int credit) : NormalAccount(account, name, balance, intRate)
    {
        switch(credit)
        {
        case 1:
            this->credit = A;
        case 2:
            this->credit = B;
        case 3:
            this->credit = C;
        }
    }
    virtual void deposit(int amount)
    {
        NormalAccount::deposit(amount);
        Account::deposit(amount + amount*credit/100);
    }
};

Account::Account(int account, char *name, int balance) : account(account), balance(balance)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
Account::Account(const Account &acc) : account(acc.account), balance(acc.balance)
{
    this->name = new char[strlen(acc.getName()) + 1];
    strcpy(this->name, acc.getName());
}
int Account::getAccount() const
{
    return account;
}
char * Account::getName() const
{
    return name;
}
int Account::getBalance() const
{
    return balance;
}
void Account::deposit(int amount)
{
    balance += amount;
}
void Account::withdraw(int amount)
{
    this->balance -= amount;
}
Account::~Account()
{
    delete []name;
}

class AccountHandler
{
private:
    Account *account[100];
    int customerNum;

public:
    AccountHandler();
    int showMenu(void);
    void newAccount(void);
    void newNormalAccount(void);
    void newCreditAccount(void);
    void deposit(void);
    void withdraw(void);
    void showAll(void);
    ~AccountHandler();
};


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
    account[customerNum++] = new NormalAccount(id, name, balance, intRate);
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
    account[customerNum++] = new CreditAccount(id, name, balance, intRate, credit);
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
        if (temp == account[i]->getAccount())
        {
            cout << "입금액: ";
            cin >> input;
            account[i]->deposit(input);
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
        if (temp == account[i]->getAccount())
        {
            cout << "출금액: ";
            cin >> withdraw;
            if (withdraw > account[i]->getBalance())
            {
                cout << "*** 잔액이 부족합니다. ***" << endl<< endl;
                return;
            }
            account[i]->withdraw(withdraw);
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
        cout << "\n계좌ID: " << account[i]->getAccount() << endl;
        cout << "이 름: " << account[i]->getName() << endl;
        cout << "잔 액: " << account[i]->getBalance() << "\n"
             << endl;
    }
    cout << endl;
}

AccountHandler::~AccountHandler()
{
    for(int i=0; i<customerNum; i++)
        delete account[i];
}


int main(void)
{
    AccountHandler ah;
    while (1)
    {
        switch (ah.showMenu())
        {
        case MAKE:
            ah.newAccount();
            break;
        case DEPOSIT:
            ah.deposit();
            break;
        case WITHDRAW:
            ah.withdraw();
            break;
        case SHOWALL:
            ah.showAll();
            break;
        case EXIT:
            return 0;
        }
    }
}