#include <iostream>

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
    int changeBalance(int balance);
    ~Account();
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
int Account::changeBalance(int balance)
{
    this->balance += balance;
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
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "\n[계좌개설]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "이 름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> balance;
    account[customerNum++] = new Account(id, name, balance);
    cout << endl;

    return;
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
            account[i]->changeBalance(input);
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
            account[i]->changeBalance(withdraw * (-1));
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