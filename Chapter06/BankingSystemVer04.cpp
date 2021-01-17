#include <iostream>

const int NAME_LEN=20;

using namespace std;

int showMenu(void);
void newAccount(void);
void deposit(void);
void withdraw(void);
void showAll(void);

enum {MAKE=1, DEPOSIT, WITHDRAW, SHOWALL, EXIT};

class Account
{
private:
    int account;
    char * name;
    int balance;
public:
    Account(int account, char * name, int balance) : account(account), balance(balance)
    {
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
    }
    Account(const Account &acc) : account(acc.account), balance(acc.balance)
    {
        this->name = new char[strlen(acc.getName())+1];
        strcpy(this->name, acc.getName());
    }
    int getAccount() const
    {
        return account;
    }
    char * getName() const
    {
        return name;
    }
    int getBalance() const
    {
        return balance;
    }
    int changeBalance(int balance)
    {
        this->balance += balance;
    }
    ~Account()
    {
        delete []name;
    }
};

Account * account[100];
int customerNum = 0;

int main(void){
    while(1){
        switch(showMenu())
        {
        case MAKE:
            newAccount();
            break;
        case DEPOSIT:
            deposit();
            break;
        case WITHDRAW:
            withdraw();
            break;
        case SHOWALL:
            showAll();
            break;
        case EXIT:
            for(int i=0; i<customerNum; i++)
            {
                delete account[i];
            }
            return 0;
        }
    }
}

int showMenu(){
    int num;

    cout<<"-----Menu-----"<<endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입 금"<<endl;
    cout<<"3. 출 금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
    cout<<"선택: ";
    cin>>num;

    return num;
}

void newAccount(){
    int id;
    char name[NAME_LEN];
    int balance;

    cout<<"\n[계좌개설]"<<endl;
    cout<<"계좌ID: ";
    cin>>id;
    cout<<"이 름: ";
    cin>>name;
    cout<<"입금액: ";
    cin>>balance;
    account[customerNum++] = new Account (id, name, balance);
    cout<<endl;
    
    return;
}

void deposit(){
    int temp;
    int input;

    cout<<"\n[입  금]"<<endl;
    cout<<"계좌ID: ";
    cin>>temp;
    for(int i=0; i<customerNum; i++){
        if(temp==account[i]->getAccount()){
            cout<<"입금액: ";
            cin>>input;
            account[temp]->changeBalance(input);
            cout<<"입금완료\n"<<endl;
            return;
        }
    }

    cout<<"*** 유효하지 않은 계좌ID 입니다. ***"<<endl<<endl;
    return;
}

void withdraw(){
    int temp;
    int withdraw;

    cout<<"\n[출  금]"<<endl;
    cout<<"계좌ID: ";
    cin>>temp;
    for(int i=0; i<customerNum; i++){
        if(temp==account[i]->getAccount()){
            cout<<"출금액: ";
            cin>>withdraw;
            if(withdraw > account[i]->getBalance())
            {
                cout<<"*** 잔액이 부족합니다. ***"<<endl<<endl;
                return;
            }
            account[temp]->changeBalance(withdraw*(-1));
            cout<<"출금완료\n"<<endl;
            return;
        }
    }

    cout<<"*** 유효하지 않은 계좌ID 입니다. ***"<<endl<<endl;
    return;
}

void showAll(){
    for(int i=0; i<customerNum; i++){
        cout<<"\n계좌ID: "<<account[i]->getAccount()<<endl;
        cout<<"이 름: "<<account[i]->getName()<<endl;
        cout<<"잔 액: "<<account[i]->getBalance()<<"\n"<<endl;
    }
    cout<<endl;
}