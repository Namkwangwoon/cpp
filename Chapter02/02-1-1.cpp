#include <iostream>
using namespace std;

void plusOne(int&);
void changeSign(int&);

int main(void)
{
    int num = 10;
    plusOne(num);
    cout<<num<<endl;
    changeSign(num);
    cout<<num<<endl;

    return 0;
}

void plusOne(int &num)
{
    num++;
}

void changeSign(int &num)
{
    num *= -1;
}