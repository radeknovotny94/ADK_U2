#include<cmath>

#include "points.h"

Points::Points()
{

}

std::vector<QPoint> Points::generateRandom(int &n, QSize &size)
{
    // Set maximum values of coordinates based on canvas size
    int w = size.width();
    int h = size.height();
    std::vector<QPoint> points;
    for (int i = 0; i<n;i++)
        points.push_back({rand()%w,rand()%h});

    return points;
}

std::vector<QPoint> Points::generateGrid(int &n, QSize &size)
{
    //Size of smaller side
    int max;
    if (size.width()<size.height())
        max = size.width();
    else
        max = size.height();

    //Make grid
    std::vector<QPoint> points;
    double gap = max/ceil(std::sqrt(n));

    for(double x=0; x<max; x+=gap)
        for(double y=0; y<max; y+=gap)
            points.push_back(QPoint(x,y));

    return points;
}

std::vector<QPoint>  Points::generateCircle(int &n, QSize &size)
{
    //Compute max radius on size of canvas
    int max_radius = 0;
    if (size.width()<size.height())
        max_radius = size.width()/2;
    else
        max_radius = size.height()/2;

    int radius = rand()%max_radius;

    //Make circle based points
    std::vector<QPoint> points;
    for (int i = 0; i<n;i++)
    {
        double angle = rand();
        points.push_back({radius*cos(angle)+size.width()/2,radius*sin(angle)+size.height()/2});
    }

    return points;
}

std::vector<QPoint>  Points::generateEllipse(int &n, QSize &size)
{
    int max_radius = 0;
    if (size.width()<size.height())
        max_radius = size.width()/2;
    else
        max_radius = size.height()/2;

    int radius = rand()%(max_radius);
    double a = ((double) rand() / (RAND_MAX));
    double b = ((double) rand() / (RAND_MAX));

    std::vector<QPoint> points;
    for (int i = 0; i<n;i++)
    {
        double angle = rand();
        points.push_back({a*radius*cos(angle)+size.width()/2,size.height()/2 - b* radius*sin(angle)});
    }

    return points;
}

std::vector<QPoint>  Points::generateRectangle(int &n, QSize &size)
{
    //Size of smaller side
    int x1 = rand()%size.width();
    int x2 = x1 + rand()%(size.width()-x1);
    int y1 = rand()%size.height();
    int y2 =  y1 + rand()%(size.height()-y1);

    //Make grid
    std::vector<QPoint> points;
    for (int i = 0; i<n;i++)
    {
        std::vector<int> list{1, 2, 3, 4};
        int index = rand() % list.size(); // pick a random index
        int side = list[index]; // a random value taken from that list

        if (side == 1)
            points.push_back(QPoint(x1,rand()%(y2-y1 + 1) + y1));
        else if (side == 2)
            points.push_back(QPoint(x2,rand()%(y2-y1 + 1) + y1));
        else if (side == 3)
            points.push_back(QPoint((rand()%(x2-x1 + 1) + x1), y1));
        else if (side == 4)
            points.push_back(QPoint((rand()%(x2-x1 + 1) + x1), y2));
    }

    return points;
}

std::vector<QPoint>  Points::generateSquare(int &n, QSize &size)
{
    //Size of smaller side
    int x1 = rand()%size.width();
    int s = rand()%(size.width()-x1);
    int x2 = x1 + s;
    int y1 = rand()%(size.height()-s);
    int y2 =  y1 + s;

    //Make grid
    std::vector<QPoint> points;
    for (int i = 0; i<n;i++)
    {
        std::vector<int> list{1, 2, 3, 4};
        int index = rand() % list.size(); // pick a random index
        int side = list[index]; // a random value taken from that list

        if (side == 1)
            points.push_back(QPoint(x1,rand()%(y2-y1 + 1) + y1));
        else if (side == 2)
            points.push_back(QPoint(x2,rand()%(y2-y1 + 1) + y1));
        else if (side == 3)
            points.push_back(QPoint((rand()%(x2-x1 + 1) + x1), y1));
        else if (side == 4)
            points.push_back(QPoint((rand()%(x2-x1 + 1) + x1), y2));
    }

    return points;
}
