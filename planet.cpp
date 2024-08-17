#include "planet.h"
#include "endscreen.h"

Planet::Planet(QLabel *planet_label, QMovie *planet_gif) : m_planet_gif(planet_gif), m_planet_label(planet_label)
{
    QMovie *movie = new QMovie(":/planetgif.gif");
    movie->setSpeed(20);
    planet_label->setGeometry(-100,350,1000,1000); //-100,350,1000,1000
    planet_label->setMovie(movie);
    movie->start();
}

void Planet::checkDamage(QWidget* mainWindow){
    if(m_lifeCounter == 2){
            m_lifes[2]->deleteLater();
        }
        else if(m_lifeCounter == 1){
            m_lifes[1]->deleteLater();
        }
        else if(m_lifeCounter == 0){
             m_lifes[0]->deleteLater();
             m_destroyed = true;
             /*
             mainWindow->close();
             EndScreen* end = new EndScreen;
             end->show();
             */
        }
}
