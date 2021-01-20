#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler
{
private:
    BoundCheckPointPtrArray accArr;
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


#endif