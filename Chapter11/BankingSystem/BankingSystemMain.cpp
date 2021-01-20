#include "AccountHandler.h"
#include "BankingCommonDecl.h"

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