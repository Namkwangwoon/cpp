#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

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

#endif