#include <iostream>
using namespace std;

class Rectangle
{
private:
    int a;
    int b;
public:
    Rectangle(int l1, int l2) : a(l1), b(l2)
    { }
    void ShowAreaInfo()
    {
        cout<<"면적: "<<a*b<<endl;
    }
};

class Square : public Rectangle
{
public:
    Square(int l) : Rectangle(l, l)
    { }
};

int main(void)
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}