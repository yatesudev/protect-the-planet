#include "asteroid.h"
#include "QLabel"

Asteroid::Asteroid(QLabel *asteroidLabel, QLabel *keyLabel, QMovie *asteroid_gif, QPixmap keyImg, QPointF spawnPosXY, QPointF destinationPosXY) :
    m_asteroidLabel(asteroidLabel),m_keyLabel(keyLabel),m_asteroid_gif(asteroid_gif), m_keyImg(keyImg),
    m_spawnPosXY(spawnPosXY), m_destinationPosXY(destinationPosXY)
{    
    m_speed = 5000;

    asteroidLabel->setText("");
    asteroidLabel->setScaledContents(true);
    asteroidLabel->setGeometry(spawnPosXY.rx(), spawnPosXY.ry(), 100, 100);
    asteroidLabel->setMovie(asteroid_gif);
    asteroid_gif->start();

    keyLabel->setPixmap(keyImg);
    keyLabel->setScaledContents(true);
    keyLabel->setGeometry(destinationPosXY.rx(), destinationPosXY.ry(), 50, 50);

    m_anim = new QPropertyAnimation(m_asteroidLabel, "pos");

    m_anim->setDuration(m_speed);
    m_anim->setStartValue(spawnPosXY);
    m_anim->setEndValue(destinationPosXY - QPointF(25,25));
    qDebug() << "new obj";
    qDebug() << spawnPosXY.rx();
    qDebug() << asteroid_gif;

    m_anim->start();
}

void Asteroid::resetAndRandomizeAsteroid(QMovie *asteroid_gif, QPixmap keyImg, QPointF spawnPosXY, QPointF destinationPosXY){

    if(m_speed >= 1250 && m_speed <= 5000){
        m_speed= m_speed - 250;
    }

    qDebug() <<m_speed;
        m_anim->stop();

        m_asteroidLabel->setGeometry(spawnPosXY.rx(), spawnPosXY.ry(), 100, 100);
        m_asteroidLabel->setMovie(asteroid_gif);
        asteroid_gif->start();

        m_keyLabel->setGeometry(destinationPosXY.rx(), destinationPosXY.ry(), 50, 50);
        m_keyLabel->setPixmap(keyImg);

        m_anim->setStartValue(spawnPosXY);
        m_anim->setDuration(m_speed);
        m_anim->setEndValue(destinationPosXY - QPointF(25,25));

        m_anim->start();

        qDebug() << "new astro";
}

Asteroid::~Asteroid(){}
