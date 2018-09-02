#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget* parent = 0);

    QGraphicsScene *scene;
    Player *player;
    Score *score;
    Health *health;

public slots:
    void end();
};

#endif // GAME_H
