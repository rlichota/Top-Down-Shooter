#include "Game.h"
#include "Enemy.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include <QDebug>
#include <QImage>
#include <QApplication>

Game::Game(QWidget *parent)
{
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/bg.png")));

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);

    setFixedSize(800,600);

    Player *player = new Player();

    //make player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(width()/2, 500);
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(),health->y()+20);
    scene->addItem(health);

    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/music.mp3"));
    music->setVolume(20);
    music->play();

    show();

    connect(health, SIGNAL(dead()), this, SLOT(end()));
}

void Game::end(){
    QGraphicsScene *scene2 = new QGraphicsScene();
    scene2->setSceneRect(0,0,150,50);
    scene2->addText("Awh, you've died!\nThanks for playing!\nCreated by Robert Lichota\nImages from opengameart.com");

    setScene(scene2);
}
