#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum ShapeType {Astroid, Cycloid, HuygensCycloid, HypoCycloid,Line};

    void setBackgroundColor (QColor color){mBackgroundColor = color; } // setter
    QColor backgroundColor () const {return mBackgroundColor;} //getter

    //set the shape here
    void setShape (ShapeType shape) {mShape = shape; on_shape_changed(); }
    ShapeType shape() const {return mShape;}

  protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
signals:
public slots:
private:
    void on_shape_changed();
    QPointF compute(float t);
    QPointF compute_astroid(float t);
    QPointF compute_Cycloid(float t);
    QPointF compute_HuygensCycloid(float t);
    QPointF compute_HypoCycloid(float t);
    QPointF compute_line(float t);
private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;
    float mIintervalLength;
    float mScale;
    int mStepCount;



};

#endif // RENDERAREA_H
