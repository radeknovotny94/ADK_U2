#ifndef POINTS_H
#define POINTS_H
#include <vector>
#include <QPoint>
#include <QSize>

class Points
{
public:
    Points();
    static std::vector<QPoint> generateRandom(int &n,QSize &size);
    static std::vector<QPoint> generateGrid(int &n,QSize &size);
    static std::vector<QPoint> generateCircle(int &n, QSize &size);
    static std::vector<QPoint> generateEllipse(int &n, QSize &size);
    static std::vector<QPoint> generateRectangle(int &n, QSize &size);
    static std::vector<QPoint> generateSquare(int &n, QSize &size);
};

#endif // POINTS_H
