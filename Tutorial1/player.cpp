#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include "enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    bulletsound = new QMediaPlayer();
    bulletsound->setVolume(20);
    bulletsound->setMedia(QUrl("qrc:/sounds/gun.mp3"));

     setPixmap(QPixmap(":/images/shoot_0.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0)
        setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    else if(event->key() == Qt::Key_Space){
        Bullet * b = new Bullet();
        b->setPos(x()+50,y());
        scene()->addItem(b);
        if(bulletsound->state() == QMediaPlayer::PlayingState)
            bulletsound->setPosition(50);
        else{
            bulletsound->play();
        }
    }
}

void Player::spawn(){
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
