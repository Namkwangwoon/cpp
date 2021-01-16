#include <iostream>

int main(void)
{
    int num;
    
    std::cout<<"숫자를 입력하세요(2~9): ";
    std::cin>>num;

    for(int i=1; i<10; i++){
        std::cout<<num<<" * "<<i<<" = "<<num*i<<std::endl;
    }
}