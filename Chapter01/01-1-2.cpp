#include <iostream>

int main(void)
{
    char name[100];
    char number[150];

    std::cout<<"이름: ";
    std::cin>>name;

    std::cout<<"전화번호: ";
    std::cin>>number;

    std::cout<<name<<' '<<number;
}