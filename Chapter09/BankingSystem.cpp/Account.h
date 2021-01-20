#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

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

#endif