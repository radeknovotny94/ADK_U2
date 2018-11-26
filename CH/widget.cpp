#include <ctime>
#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"
#include "points.h"
#include <iostream>
#include <fstream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_create_ch_clicked()
{
    QPolygon ch;
    std::vector<QPoint> points = ui->Canvas->getPoints();

    //Start time
    clock_t s = std::clock();

    //Construct CH
    if (ui->method_ch->currentIndex()==0)
        ch = Algorithms::CHJarvis(points);
    else if (ui->method_ch->currentIndex()==1)
        ch = Algorithms::QHull(points);
    else ch= Algorithms::CHSweep(points);

    //End time
    clock_t e = std::clock();

    //Time difference in miliseconds
    ui->label_time->setText(QString::number(double(e-s)/CLOCKS_PER_SEC) + " s");
    ui->label_info->setText("Convex Hull was computed!");
    //Set and repaint
    ui->Canvas->setCH(ch);
    repaint();
}

void Widget::on_clear_clicked()
{
    ui->Canvas->clearAll();
    repaint();
    ui->label_info->setText("Generate points or input points manually.");
}

void Widget::on_generate_clicked()
{
    ui->Canvas->clearAll();
    QSize s = ui->Canvas->size();
    int input_num=ui->number->text().toInt();
    if(input_num<=0)
    {
        error_flag = true;
        QMessageBox *msg = new QMessageBox();
        msgSettings(msg);
        msg->show();
        return;
    }
    else
    {
        error_flag = false;
        if (ui->style->currentIndex()==0)
        {
            std::vector<QPoint> points = Points::generateRandom(input_num,s);
            ui->Canvas->setPoints(points);
            ui->Canvas->repaint();
        }
        else if (ui->style->currentIndex()==2)
        {
             std::vector<QPoint> points = Points::generateGrid(input_num,s);
             ui->Canvas->setPoints(points);
             ui->Canvas->repaint();
        }
        else if (ui->style->currentIndex()==1)
        {
             std::vector<QPoint> points = Points::generateCircle(input_num,s);
             ui->Canvas->setPoints(points);
             ui->Canvas->repaint();
        }
        else if (ui->style->currentIndex()==3)
        {
             std::vector<QPoint> points = Points::generateEllipse(input_num,s);
             ui->Canvas->setPoints(points);
             ui->Canvas->repaint();
        }
        else if (ui->style->currentIndex()==4)
        {
             std::vector<QPoint> points = Points::generateRectangle(input_num,s);
             ui->Canvas->setPoints(points);
             ui->Canvas->repaint();
        }
        else
        {
             std::vector<QPoint> points = Points::generateSquare(input_num,s);
             ui->Canvas->setPoints(points);
             ui->Canvas->repaint();
        }
        ui->label_info->setText("Select method of CH computation.");
    }
}

void Widget::on_table_clicked()
{
    ui->Canvas->clearAll();
    ui->label_info->setText("Computing.");
    vector<vector<double> > table(10, vector<double>(10));
    QSize s = ui->Canvas->size();
    //std::vector<int> num_points{1000,2500,5000,10000,25000,50000,100000,250000,500000,1000000};
   std::vector<int> num_points{1000,2500,5000,10000};
    for(int j = 0; j<10; j++)
    {
        ui->label_info->setText(QString::number(j));
        for(int i = 0; i<num_points.size();i++)
        {
            if (ui->style->currentIndex()==0)
            {
                std::vector<QPoint> points = Points::generateRandom(num_points[i],s);
                ui->Canvas->setPoints(points);
                ui->Canvas->repaint();
            }
            else if (ui->style->currentIndex()==2)
            {
                 std::vector<QPoint> points = Points::generateGrid(num_points[i],s);
                 ui->Canvas->setPoints(points);
                 ui->Canvas->repaint();
            }
            else if (ui->style->currentIndex()==1)
            {
                 std::vector<QPoint> points = Points::generateCircle(num_points[i],s);
                 ui->Canvas->setPoints(points);
                 ui->Canvas->repaint();
            }
            else if (ui->style->currentIndex()==3)
            {
                 std::vector<QPoint> points = Points::generateEllipse(num_points[i],s);
                 ui->Canvas->setPoints(points);
                 ui->Canvas->repaint();
            }
            else if (ui->style->currentIndex()==4)
            {
                 std::vector<QPoint> points = Points::generateRectangle(num_points[i],s);
                 ui->Canvas->setPoints(points);
                 ui->Canvas->repaint();
            }
            else
            {
                 std::vector<QPoint> points = Points::generateSquare(num_points[i],s);
                 ui->Canvas->setPoints(points);
                 ui->Canvas->repaint();
            }
            QPolygon ch;
            std::vector<QPoint> points = ui->Canvas->getPoints();
            //Start time
            clock_t s = std::clock();

            //Construct CH
            if (ui->method_ch->currentIndex()==0)
                ch = Algorithms::CHJarvis(points);
            else if (ui->method_ch->currentIndex()==1)
                ch = Algorithms::QHull(points);
            else ch= Algorithms::CHSweep(points);

            //End time
            clock_t e = std::clock();
            table[j][i] = double(e-s)/CLOCKS_PER_SEC;

            //Time difference in miliseconds
            //ui->label_time->setText(QString::number(double(e-s)/CLOCKS_PER_SEC) + " s");

            ui->Canvas->setCH(ch);
            ofstream file;
            file.open ("table.txt");
            for (unsigned int i = 0; i < table.size(); ++i)
            {
                for (unsigned int j = 0; j < table[i].size(); ++j)
                {
                    file << table[i][j] << " ";
                }
                file << std::endl;
            }
            file.close();
            repaint();
        }
    }

    ui->label_info->setText("Table is DONE.");
}

