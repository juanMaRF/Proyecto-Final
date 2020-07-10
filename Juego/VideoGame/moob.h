#ifndef MOOB_H
#define MOOB_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class moob : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit moob(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;
    double vida=20,vel,vel_x,vel_y,x,y,delta=0.1;
    float filas,columnas;

    float ancho;
    float alto;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void actualizar_y();
    void actualizar_x();


signals:

public slots:
    void Actualizacion();
};
#endif // MOOB_H
