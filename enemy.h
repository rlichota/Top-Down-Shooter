#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    int position = 0;
    Enemy();
public slots:
    void move();
    void change();
};
#endif // ENEMY_H
