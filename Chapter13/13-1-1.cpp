#include <iostream>
using namespace std;

template <class T>
void SwapData(T& num1, T& num2)
{
    T temp = num1;
    num1 = num2;
    num2 = temp;
}

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
    }
};

int main(void)
{
    Point pos1(6, 2);
    Point pos2(25, 3);
    SwapData(pos1, pos2);
    pos1.ShowPosition();
    pos2.ShowPosition();
    return 0;
}