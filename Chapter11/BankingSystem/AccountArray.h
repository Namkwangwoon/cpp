#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "Account.h"
typedef Account * ACCOUNT_PTR;

class BoundCheckPointPtrArray
{
private:
    ACCOUNT_PTR * arr;
    int arrlen;
    BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) { }
    BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) { }

public:
    BoundCheckPointPtrArray(int len=100);
    ACCOUNT_PTR& operator[] (int idx);
    ACCOUNT_PTR& operator[] (int idx) const;
    int GetArrlen() const;
    ~BoundCheckPointPtrArray();
};

#endif