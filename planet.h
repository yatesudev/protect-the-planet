#ifndef PLANET_H
#define PLANET_H

#include <QMovie>
#include <QLabel>

class Planet
{
public:
    Planet(QLabel *planet_label, QMovie* planet_gif);

    void setLifes(QList<QLabel*> lifes_list){
        m_lifes = lifes_list;
    }

    void setLifeCounter(int lifeCounter){
        m_lifeCounter = lifeCounter;
    }

    void checkDamage(QWidget* mainWindow);

    bool isDestroyed(){
        return m_destroyed;
    }

private:
    QMovie *m_planet_gif;
    QLabel *m_planet_label;
    QList<QLabel*> m_lifes;
    int m_lifeCounter = 3;
    bool m_destroyed;
};

#endif // PLANET_H
