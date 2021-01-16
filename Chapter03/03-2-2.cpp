#include <iostream>
using namespace std;

class Printer
{
private:
    char * str;
public:
    void SetString(char * str);
    void ShowString();
};

int main(void)
{
    Printer pnt;
    pnt.SetString("Hello World!");
    pnt.ShowString();

    pnt.SetString("I Love C++");
    pnt.ShowString();
    return 0;
}

void Printer::SetString(char * str)
{
    this->str = str;
}

void Printer::ShowString(){
    cout<<str<<endl;
}