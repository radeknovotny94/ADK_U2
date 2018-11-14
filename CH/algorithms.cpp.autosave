#include<cmath>
#include<vector>
#include "algorithms.h"
#include "sortbyxasc.h"
#include "sortbyyasc.h"


Algorithms::Algorithms()
{

}

TPosition Algorithms::getPointLinePosition(QPoint &q, QPoint &a, QPoint &b)
{
    //Point and line position
    double eps = 1.0e-10;

    double ux = b.x() - a.x();
    double uy = b.y() - a.y();
    double vx = q.x() - a.x();
    double vy = q.y() - a.y();

    //Determinant
    double t = (ux * vy - uy * vx);

    //Point in the left half plane
    if(t > eps)
        return LEFT;

    //Point in the right half plane
    if(t < -eps)
        return RIGHT;

    //Point on the line
    return ON;
}


double Algorithms::get2LinesAngle(QPoint &p1,QPoint &p2,QPoint &p3, QPoint &p4)
{
    //Angle between two lines
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();
    double vx = p4.x() - p3.x();
    double vy = p4.y() - p3.y();

    //Dot product
    double dot = ux * vx + uy * vy;

    //Norms
    double nu = sqrt(ux * ux + uy * uy);
    double nv = sqrt(vx * vx + vy * vy);

    return fabs(acos(dot/(nu * nv)))*(180/M_PI);
}

QPolygon Algorithms::CHJarvis (vector<QPoint> &points)
{
    double eps = 1.0e-10;

    //Create convex hull using the Jarvis Scan procedure
    QPolygon ch;

    //Find pivot q
    std::sort(points.begin(), points.end(), sortByYAsc());
    QPoint q = points[0];

    std::sort(points.begin(), points.end(), SortByXAsc());
    QPoint s = points[0];

    //Create Pjj
    QPoint pjj (s.x(),q.y());
    QPoint pj = q;

    //Add pivot to CH
    ch.push_back(q);

    //Add all points to CH
    do
    {
        int i_max = -1;
        double fi_max = 0.0;
        double dist_max = 0.0;

        //Find pi = arg max angle(pi, pj, pjj)
        for(int i = 0; i<points.size();i++)
        {
            //Get angle betwwen 2 segments
            double fi = get2LinesAngle(pj, pjj, pj, points[i]);

            //Find maximum
            if (fi>fi_max)
            {
                i_max=i;
                fi_max=fi;
            }

            //Singular point
            else if (std::fabs(fi_max - fi) < eps)
            {
                double dx = pj.x() - points[i].x();
                double dy = pj.y() - points[i].y();
                double distance = sqrt(dx*dx + dy*dy);
                if (distance > dist_max)
                {
                    dist_max = distance;
                    i_max = i;
                }
            }
        }

        //Add the next point to CH
        ch.push_back(points[i_max]);

        //Assign CH verticess
        pjj = pj;
        pj = points[i_max];

    } while (!(pj == q));

    return ch;
}

double Algorithms::getPointLineDistance(QPoint &q, QPoint &a, QPoint &b)
{
    //Point and line distance
    double x12 = b.x()-a.x();
    double y12 = b.y()-a.y();

    double y1a = q.y()-a.y();
    double y2a = b.y()-q.y();

    double numerator = -q.x()*y12 + a.x()*y2a + b.x()*y1a;
    double denominator = sqrt(x12*x12 + y12*y12);

    return fabs(numerator)/denominator;

}

QPolygon Algorithms::QHull (vector<QPoint> &points)
{
    //Create convex hull using the qhull procedure
    QPolygon ch;
    std::vector<QPoint> su, sl;

    //Find q1, q3
    std::sort(points.begin(), points.end(), SortByXAsc());
    QPoint q1 = points[0];
    QPoint q3 = points[points.size()-1];

    // Add to SU,SL
    su.push_back(q1);
    su.push_back(q3);
    sl.push_back(q1);
    sl.push_back(q3);

    //Splite to SU or SL
    for(int i =0;i<points.size();i++)
    {
        // Add to SU
        if(getPointLinePosition(points[i],q1,q3)==LEFT)
        {
            su.push_back(points[i]);
        }

        // Add to SL
        if(getPointLinePosition(points[i],q1,q3)==RIGHT)
        {
            sl.push_back(points[i]);
        }
    }

    //Add q3 to ch
    ch.push_back(q3);

    //Process SU
    qh(1, 0, su, ch);

    //Add q1 to ch
    ch.push_back(q1);

    //Process SL
    qh(0, 1, sl, ch);

    return ch;
}

void Algorithms::qh(int s, int e, vector<QPoint> &p, QPolygon &h)
{
    //Local recursive procedure of qhull
    int i_max = -1;
    double d_max = 0;

    //Browse all points
    for(int i = 2; i<p.size(); i++)
    {
        //Is the point in the right half-plane?
        if(getPointLinePosition(p[i], p[s], p[e])==RIGHT)
        {
            //Compute the distance between point and the given segment
            double d =  getPointLineDistance(p[i], p[s], p[e]);

            //Remember the furthest point and its index
            if (d>d_max)
            {
                d_max = d;
                i_max = i;
            }
        }
    }

    //Point in the right half plain exists
    if(i_max >1)
    {
        //Process the first interval
        qh(s,i_max,p,h);

        //Add to CH
        h.push_back(p[i_max]);

        //Process the second interval
        qh(i_max,e,p,h);
    }
}

QPolygon Algorithms::CHSweep (vector<QPoint> &points)
{
    //Create convex hull using the sweepline procedure
    QPolygon ch;

    //sort by X
    std::sort(points.begin(), points.end(), SortByXAsc());

    //Create list of predecessors
    std::vector<int> p(points.size());

    //Create list of successors
    std::vector<int> n(points.size());

    /*
    //Create triangle (0, 1, 2) from the first 3 points
    //Change i to 3 in the next for loop
    if(getPointLinePosition(points[2], points[0], points[1])==LEFT)
    {
        n[0] = 1;
        n[1] = 2;
        n[2] = 0;

        p[0] = 2;
        p[1] = 0;
        p[2] = 1;
    }

    //Create triangle (0, 2, 1) from the first 3 points
    else
    {
        n[0] = 2;
        n[2] = 1;
        n[1] = 0;

        p[0] = 1;
        p[2] = 0;
        p[1] = 2;
    }
    */

    //Create an initial biangle (0, 1)
    //Change i to 2 in the next for loop
    n[0]=1;
    n[1]=0;

    p[0]=1;
    p[1]=0;

    for (int i = 2; i < points.size(); i++)
    {
        //Point in the upper halfplane
        //Link i with predecessor/successor
        if(points[i].y() > points[i-1].y())
        {
            p[i]=i-1;
            n[i]=n[i-1];
        }

        //Point in the lower halfplane
        else
        {
            n[i]=i-1;
            p[i]=p[i-1];

        }

        //Link predecessor/successor with i-th point
        n[p[i]] = i;
        p[n[i]] = i;

        //Fix the upper tangent
        while(getPointLinePosition(points[n[n[i]]], points[i], points[n[i]])==RIGHT)
        {
            p[n[n[i]]] = i;
            n[i] = n[n[i]];
        }

        //Fix the lower tangent
        while(getPointLinePosition(points[p[p[i]]], points[i], points[p[i]])==LEFT)
        {
            n[p[p[i]]] = i;
            p[i] = p[p[i]];
        }
    }

    // Convert to the polygon
    ch.push_back(points[0]);
    int i = n[0];

    while (i != 0)
    {
       ch.push_back(points[i]);
       i = n[i];
    }

    return ch;
}









