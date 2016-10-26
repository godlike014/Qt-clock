#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QPainter>
#include <QTime>
#include <QTimer>
static QPoint second[4]={QPoint(0,-82),QPoint(-2,0),QPoint(0,5),QPoint(2,0)};
static QPoint minute[4]={QPoint(0,-72),QPoint(-3,0),QPoint(0,6),QPoint(3,0)};
static QPoint hour[4]={QPoint(0,-52),QPoint(-4,0),QPoint(0,7),QPoint(4,0)};
class clock : public QWidget
{
    Q_OBJECT

public:
    clock(QWidget *parent = 0);
    ~clock();
protected:
    void paintEvent(QPaintEvent *);
    QTimer *timer;
};

#endif // CLOCK_H
