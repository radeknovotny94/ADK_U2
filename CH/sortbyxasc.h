#ifndef SORTBYXASC_H
#define SORTBYXASC_H
#include<QtGui>


class SortByXAsc
{
public:
    SortByXAsc();

    bool operator()(QPoint &p1, QPoint &p2)
    {
        return (p1.x()<p2.x())||((p1.x()==p2.x())&&(p1.y()<p2.y()));
    }
};

#endif // SORTBYXASC_H
