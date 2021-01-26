#include <iostream>
using namespace std;

int main(void)
{
    int num1, num2;
    cout<<"두 개의 숫자 입력: ";
    cin>>num1>>num2;

    cout<<"나눗셈의 몫: "<<num1/num2<<endl;
    cout<<"나눗셈의 나머지: "<<num1%num2<<endl;
    return 0;
}