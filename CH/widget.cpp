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
    ui->label_time->setText(QString::number(double(e-s)/CLOCKS_PER_SEC) + " ms");
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
