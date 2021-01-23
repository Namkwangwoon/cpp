#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include <iostream>
#include <cstring>

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

enum
{
    NORMAL=1,
    CREDIT
};

enum
{
    A=7,
    B=4,
    C=2
};

#endif