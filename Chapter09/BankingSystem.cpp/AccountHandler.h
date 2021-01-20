#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"

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

#endif