#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"
#include "BankingCommonDecl.h"

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

#endif