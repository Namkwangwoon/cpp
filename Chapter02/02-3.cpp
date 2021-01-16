#include <iostream>
using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
}Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
    Point * ptr = new Point;
    ptr->xpos = p1.xpos + p2.xpos;
    ptr->ypos = p1.ypos + p2.ypos;
    return *ptr;
}

int main(void)
{
    Point * ptr1 = new Point;
    ptr1->xpos = 3;
    ptr1->ypos = 30;

    Point * ptr2 = new Point;
    ptr2->xpos = 70;
    ptr2->ypos = 7;

    Point &ptr = PntAdder(*ptr1, *ptr2);
    cout<<ptr.xpos<<' '<<ptr.ypos<<endl;

    delete ptr1;
    delete ptr2;
    delete &ptr;
    return 0;
}