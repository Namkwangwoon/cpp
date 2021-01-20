#include "Account.h"
#include "BankingCommonDecl.h"

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