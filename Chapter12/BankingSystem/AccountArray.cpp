#include "AccountArray.h"
#include "BankingCommonDecl.h"

BoundCheckPointPtrArray::BoundCheckPointPtrArray(int len) : arrlen(len)
{
    arr = new ACCOUNT_PTR[len];
}

ACCOUNT_PTR& BoundCheckPointPtrArray::operator[] (int idx)
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    return arr[idx];
}

ACCOUNT_PTR& BoundCheckPointPtrArray::operator[] (int idx) const
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    return arr[idx];
}

int BoundCheckPointPtrArray::GetArrlen() const
{
    return arrlen;
}

BoundCheckPointPtrArray::~BoundCheckPointPtrArray()
{
    delete []arr;
}