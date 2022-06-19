#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
    : QWidget{parent},
      mBackgroundColor(0,0,255),
      mPen(Qt::white),
      mShape(Astroid)

{
 mPen.setWidth(2);
 on_shape_changed();
}


QSize RenderArea::minimumSizeHint() const{
    return QSize(400, 400);
}
QSize RenderArea::sizeHint() const{
     return QSize(400, 400);
}
void RenderArea::on_shape_changed(){
    switch (mShape){
    //Astroid, Cycloid, HuygensCycloid, HypoCycloid
    case Astroid:
        //load astroid values
        mScale = 40;
        mIintervalLength = 2 * M_PI;
        mStepCount = 256;
        //mBackgroundColor = Qt::red;
    break;

    case Cycloid:
        mScale = 4;
        mIintervalLength = 6 * M_PI;
        mStepCount = 128;
        //mBackgroundColor = Qt::blue;
        break;
    case HuygensCycloid:
        mScale = 4;
        mIintervalLength = 4 * M_PI;
        mStepCount = 256;
        //mBackgroundColor = Qt::yellow;
        break;
    case HypoCycloid:
        mScale = 15;
        mIintervalLength = 2 * M_PI;
        mStepCount = 256;
        //mBackgroundColor = Qt::green;
        break;
    case Cycle:
        mScale = 50;
        mIintervalLength = 2 * M_PI;
        mStepCount = 128;
        //mBackgroundColor = Qt::green;
        break;
    case Ellips:
        mScale = 60;
        mIintervalLength = 2 * M_PI;
        mStepCount = 256;
        //mBackgroundColor = Qt::green;
        break;
    case Starfish:
        mScale = 20;
        mIintervalLength = 6 * M_PI;
        mStepCount = 256;
        //mBackgroundColor = Qt::green;
        break;
    case Fancy:
        mScale = 7;
        mIintervalLength = 12 * M_PI;
        mStepCount = 512;
        //mBackgroundColor = Qt::green;
        break;
    case Cloud:
        mScale = 7;
        mIintervalLength = 28 * M_PI;
        mStepCount = 128;
        //mBackgroundColor = Qt::green;
        break;
    case Cloud2:
        mScale = 7;
        mIintervalLength = 28 * M_PI;
        mStepCount = 128;
        //mBackgroundColor = Qt::green;
        break;
    case Line:
        //TBD
        mScale = 100;
        mIintervalLength = 2;
        mStepCount = 128;
    default:
        break;

    }
}
QPointF RenderArea::compute(float t){
    switch (mShape){
    //Astroid, Cycloid, HuygensCycloid, HypoCycloid
    case Astroid:

        //load astroid values
        return compute_astroid(t);
        //mBackgroundColor = Qt::red;
    break;

    case Cycloid:
        return compute_Cycloid(t);
        //mBackgroundColor = Qt::blue;
        break;
    case HuygensCycloid:
        return compute_HuygensCycloid(t);
        //mBackgroundColor = Qt::yellow;
        break;
    case HypoCycloid:
        return compute_HypoCycloid(t);
        //mBackgroundColor = Qt::green;
        break;
    case Ellips:
        return compute_Ellips(t);
        //mBackgroundColor = Qt::green;
        break;
    case Fancy:
        return compute_Fancy(t);
        //mBackgroundColor = Qt::green;
        break;
    case Cycle:
        return compute_Cycle(t);
        //mBackgroundColor = Qt::green;
        break;
    case Starfish:

        //load astroid values
        return compute_Starfish(t);
        //mBackgroundColor = Qt::red;
    break;
    case Cloud:

        //load astroid values
        return compute_Cloud(t);
        //mBackgroundColor = Qt::red;
    break;
    case Cloud2:

        //load astroid values
        return compute_Cloud2(t);
        //mBackgroundColor = Qt::red;
    break;
    case Line:
        return compute_line(t);
    default:
        break;

    }
    return QPointF (0,0);
}

QPointF RenderArea::compute_astroid(float t){

    // we will compute the astroid function here
    float cos_t = cos (t);
    float sin_t = sin (t);
    float x = 2 * cos_t * cos_t * cos_t; //pow(cost_t, 3);
    float y = 2 * sin_t * sin_t * sin_t;
    return QPointF (x, y);

}
QPointF RenderArea::compute_Cycloid(float t){
    return QPointF (
                1.5 * (1 - cos (t)),  //X
                1.5 * (t - sin (t))  //Y
                );

}
QPointF RenderArea::compute_HuygensCycloid(float t){
  return QPointF (
              4 * (3 * cos (t) - cos (3 * t)),
              4 * (3 * sin (t) - sin (3 *t))
              );
}
QPointF RenderArea::compute_HypoCycloid(float t){
    return QPointF (
                1.5 * (2 * cos (t) + cos (2 * t)), //X
                1.5 * (2 * sin (t) - sin (2 * t)) // Y
                );

}
//     Point( Center.x + radius*cos( angle ), Center.y + radius*sin( angle ) );

QPointF RenderArea::compute_Cycle(float t){

    return QPointF (sin(t), cos(t));


}
QPointF RenderArea::compute_Ellips(float t){
    float a=2;
    float b = 1.1;

    return QPointF (a*sin(t), b*cos(t));


}
QPointF RenderArea::compute_Fancy(float t){

    return QPointF (
                11.0f*cos(t)-6*cos(11.0f/6*t),
                11.0f*sin(t)-6*sin(11.0f/6*t));
}

QPointF RenderArea::compute_Starfish(float t){

   float R = 5,r=3,d=5;
   float x = (R-r)*cos(t)+d*cos(t*(R-r)/r);
   float y = (R-r)*sin(t)-d*sin(t*(R-r)/r);

    return QPointF (
                x,y
                );
}
QPointF RenderArea::compute_line(float t){

    return QPointF (1-t, 1-t);
}

QPointF RenderArea::compute_Cloud(float t){
    float a = 14;
    float b = 1;
    float x = (a+b)*cos(t*b/a)+b*cos(t*(a+b)/a);
    float y = (a+b)*sin(t*b/a)-b*sin(t*(a+b)/a);


    return QPointF (x,y);
}
QPointF RenderArea::compute_Cloud2(float t){
    float a = 14;
    float b = 1;
    float x = (a+b)*cos(t*b/a)-b*cos(t*(a+b)/a);
    float y = (a+b)*sin(t*b/a)-b*sin(t*(a+b)/a);


    return QPointF (x,y);
}

void RenderArea::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    // setshape ::

    painter.setBrush(mBackgroundColor);
    painter.setPen(mPen);




    //drawing Area

    painter.drawRect(this->rect());
    QPoint center = this->rect ().center();
    QPointF prevPoint = compute(0);
    QPoint prevPixel;
    prevPixel.setX(prevPoint.x() * mScale + center.x());
    prevPixel.setY(prevPoint.y() * mScale + center.y());

    //painter.drawLine(this->rect().topLeft(),this->rect().bottomRight());

    float step = mIintervalLength /mStepCount;
    for (float t = 0; t< mIintervalLength; t += step) {

        QPointF point = compute (t);//need to define inside renderarea.h

        QPoint pixel;
        pixel.setX(point.x() * mScale + center.x());
        pixel.setY(point.y() * mScale + center.y());

        //painter.drawPoint(pixel);
        painter.drawLine(pixel, prevPixel);
        prevPixel = pixel;
    }
    QPointF point = compute (mIintervalLength);//need to define inside renderarea.h
    QPoint pixel;
    pixel.setX(point.x() * mScale + center.x());
    pixel.setY(point.y() * mScale + center.y());

    painter.drawLine(pixel, prevPixel);

}
