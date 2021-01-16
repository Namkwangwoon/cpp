#include <iostream>

int main(void)
{
    int amount;

    while(1){

        std::cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
        std::cin>>amount;

        if(amount == -1){
            std::cout<<"프로그램을 종료합니다.";
            return 0;
        }

        else{
            std::cout<<"이번 달 급여: "<<50+amount*0.12<<"만원"<<std::endl;
        }
    }
}