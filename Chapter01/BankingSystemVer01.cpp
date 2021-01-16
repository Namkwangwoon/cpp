#include <iostream>

using namespace std;

int showMenu(void);
void newAccount(void);
void deposit(void);
void withdraw(void);
void showAll(void);

typedef struct{
    int account;
    char name[100];
    int balance;
} Account;

Account account[100];
int customerNum = 0;

int main(void){
    while(1){
        switch(showMenu()){
        case 1:
            newAccount();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            showAll();
            break;
        case 5:
            return 0;
        }
    }
}

int showMenu(){
    int num;

    cout<<"-----Menu______"<<endl;
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
    cout<<"\n[계좌개설]"<<endl;
    cout<<"계좌ID: ";
    cin>>account[customerNum].account;
    cout<<"이 름: ";
    cin>>account[customerNum].name;
    cout<<"입금액: ";
    cin>>account[customerNum].balance;
    cout<<endl;
    
    customerNum++;
    return;
}

void deposit(){
    int temp;
    int input;

    cout<<"\n[입  금]"<<endl;
    cout<<"계좌ID: ";
    cin>>temp;
    for(int i=0; i<customerNum; i++){
        if(temp==account[i].account){
            temp = i;
            break;
        }
    }
    cout<<"입금액: ";
    cin>>input;
    account[temp].balance += input;
    cout<<"입금완료\n"<<endl;

    return;
}

void withdraw(){
    int temp;
    int withdraw;

    cout<<"\n[출  금]"<<endl;
    cout<<"계좌ID: ";
    cin>>temp;
    for(int i=0; i<customerNum; i++){
        if(temp==account[i].account){
            temp = i;
            break;
        }
    }
    cout<<"출금액: ";
    cin>>withdraw;
    account[temp].balance -= withdraw;
    cout<<"출금완료\n"<<endl;

    return;
}

void showAll(){
    for(int i=0; i<customerNum; i++){
        cout<<"\n계좌ID: "<<account[i].account<<endl;
        cout<<"이 름: "<<account[i].name<<endl;
        cout<<"잔 액: "<<account[i].balance<<"\n"<<endl;
    }
}