#include "enemy.h"
#include "health.h"
#include "game.h"
#include <QTimer>
#include <QString>
#include <QGraphicsScene>
#include <stdlib.h>

extern Game *game;

Enemy::Enemy()
{
    int random_number = rand() % 700;
    setPixmap(QPixmap(":/images/shoot_0.png"));
    setPos(random_number, 0);

    //connect
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    connect(timer, SIGNAL(timeout()), this, SLOT(change()));

    timer->start(50);
}

void Enemy::move(){
    if(pos().y() > 500){
        scene()->removeItem(this);
        game->health->decrease();
        delete this;
    }
    setPos(x(),y()+5);
}

void Enemy::change(){
    if(position < 19){
        position += 1;
        QString s = QString::number(position);
        QString t = ":/images/Top_Down_Survivor/knife/move/survivor-move_knife_"+s+".png";
        setPixmap(QPixmap((t)));
}
    else{
        position = 0;
    }
}
