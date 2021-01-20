#include <iostream>
using namespace std;

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
    Point& operator++()
    {
        xpos += 1;
        ypos += 1;
        return *this;
    }
    friend Point& operator--(Point& ref);
    Point& operator-()
    {
        Point pos(-xpos, -ypos);
        return pos;
    }
    friend Point& operator~(Point& ref);
};

Point& operator--(Point& ref)
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

Point& operator~(Point& ref)
{
    int temp;
    temp = ref.xpos;
    ref.xpos = ref.ypos;
    ref.ypos = temp;
    return ref;
}

int main(void)
{
    Point pos1(1, 2);
    Point pos2 = -pos1;
    pos1.ShowPosition();
    pos2.ShowPosition();

    ~pos2;
    pos2.ShowPosition();
    ~(~pos2);
    pos2.ShowPosition();
    return 0;
}