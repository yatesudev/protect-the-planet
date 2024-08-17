#ifndef ASTEROID_H
#define ASTEROID_H
#include "QMovie.h"
#include "QLabel"
#include <QPropertyAnimation>

class Asteroid
{
public:
    Asteroid(QLabel *asteroidLabel, QLabel *keyLabel, QMovie *asteroid_gif, QPixmap keyImg, QPointF spawnPosXY, QPointF destinationPosXY);
    ~Asteroid();

    void setSpawnPosXY(QPointF spawnPosXY){
        m_spawnPosXY = spawnPosXY;
    }
    const QPointF &getSpawnPosXY() const{
        return m_spawnPosXY;
    }

    QLabel *getAsteroidLabel() const{
        return m_asteroidLabel;
    }

    QLabel *getKeyLabel() const{
        return m_keyLabel;
    }

    QPropertyAnimation *getAnimation() const{
        return m_anim;
    }

    void deleteAsteroid(){
        m_asteroidLabel->deleteLater();
        m_asteroidLabel = nullptr;
        m_keyLabel->deleteLater();
        m_keyLabel = nullptr;
        qDebug() << "obj deleted";
    }

    void resetAndRandomizeAsteroid(QMovie *asteroid_gif, QPixmap keyImg, QPointF spawnPosXY, QPointF destinationPosXY);

private:
    QLabel *m_asteroidLabel;
    QLabel *m_keyLabel;
    QMovie *m_asteroid_gif;
    QPixmap m_keyImg;
    QPointF m_spawnPosXY;
    QPointF m_destinationPosXY;
    int m_speed;

    QPropertyAnimation *m_anim;
};

#endif // ASTEROID_H
