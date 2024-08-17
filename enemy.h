#ifndef ENEMY_H
#define ENEMY_H

#include "QGraphicsItem"
#include "QLabel"

class Enemy
{
public:
    Enemy(QLabel* enemyLabel, QPointF enemyPos, QPointF targetPos) : m_enemyLabel(enemyLabel), m_enemyPos(enemyPos), m_targetPos(targetPos) {};
    void move();
    void takeDamage(int damage);
    bool isDead();

    void setSpeed(int speed){
        m_speed = speed;
    }

private:
    QLabel* m_enemyLabel;
    QPointF m_enemyPos;
    QPointF m_targetPos;
    int m_speed;
    int m_health;
    int m_damage;
};

#endif // ENEMY_H
