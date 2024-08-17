#include "enemy.h"

void Enemy::move()
{
    QLineF lineToTarget(m_enemyPos, m_targetPos);
    qreal angleToTarget = lineToTarget.angle();

    m_enemyPos.setX(m_enemyPos.x() + cos(angleToTarget) * m_speed);
    m_enemyPos.setY(m_enemyPos.y() + sin(angleToTarget) * m_speed);

    m_enemyLabel->move(m_enemyPos.toPoint());
}
