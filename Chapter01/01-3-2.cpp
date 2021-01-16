int SimpleFunc(int a=10){
    return a+1;
}

int SimpleFunc(void){
    return 10;
}

int main(void){
    std::cout<<SimpleFunc();
}