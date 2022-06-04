#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
    : QWidget{parent},
      mBackgroundColor(0,0,255),
      mShapeColor(255,255,255),
      mShape(Astroid)

{

}


QSize RenderArea::minimumSizeHint() const{
    return QSize(100, 100);
}
QSize RenderArea::sizeHint() const{
     return QSize(400, 100);
}

QPointF RenderArea::compute_astroid(float t){

    // we will compute the astroid function here
    float cost_t = cos (t);
    float sin_t = sin (t);
    float x = 2 * cost_t * cost_t * cost_t; //pow(cost_t, 3);
    float y = 2 * sin_t * sin_t * sin_t;
    return QPointF (x, y);

}
void RenderArea::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    // setshape ::
    switch (mShape){
    //Astroid, Cycloid, HuygensCycloid, HypoCycloid
    case Astroid:
        mBackgroundColor = Qt::red;
    break;

    case Cycloid:
        mBackgroundColor = Qt::blue;
        break;
    case HuygensCycloid:
        mBackgroundColor = Qt::yellow;
        break;
    case HypoCycloid:
        mBackgroundColor = Qt::green;
        break;
    default:
        break;

    }
    painter.setBrush(mBackgroundColor);
    painter.setPen(mShapeColor);




    //drawing Area
    painter.drawRect(this->rect());
    QPoint center = this->rect ().center();
    //painter.drawLine(this->rect().topLeft(),this->rect().bottomRight());
    int stepCount = 256;
    float scale = 40;
    float intervalLength = 2 * M_PI;
    float step = intervalLength / stepCount;
    for (float t = 0; t< intervalLength; t += step) {

        QPointF point = compute_astroid (t);//need to define inside renderarea.h

        QPoint pixel;
        pixel.setX(point.x() * scale + center.x());
        pixel.setY(point.y() * scale + center.y());

        painter.drawPoint(pixel);
    }

}
