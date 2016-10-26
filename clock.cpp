#include "clock.h"

clock::clock(QWidget *parent)
    : QWidget(parent)
{
    timer = new QTimer(this);
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));

    resize(200,200);
}

clock::~clock()
{

}

void clock::paintEvent(QPaintEvent *)
{
    QTime time=QTime::currentTime();
    QPainter paint(this);
    paint.translate(100,100);
    paint.setRenderHint(QPainter::Antialiasing);

    paint.setBrush(Qt::red);
    paint.setPen(Qt::red);
    paint.save();
    paint.rotate(time.hour()*30.0+time.minute()*0.5);
    paint.drawConvexPolygon(hour,4);
    paint.restore();

    paint.setBrush(Qt::blue);
    paint.setPen(Qt::blue);
    paint.save();
    paint.rotate(time.minute()*6.0+time.second()*6.0/60.0);
    paint.drawConvexPolygon(minute,4);
    paint.restore();

    paint.setBrush(Qt::black);
    paint.setPen(Qt::black);
    paint.save();
    paint.rotate(time.second()*6.0);
    paint.drawConvexPolygon(second,4);
    paint.restore();

    for(int i=0;i<60;i++)
    {
        if(i%5)
            paint.drawLine(0,-98,0,-95);
        paint.rotate(6);
    }
    paint.setPen(Qt::red);
    for(int i=0;i<12;i++)
    {
        paint.rotate(30);
        paint.drawLine(0,-98,0,-90);
    }

}
