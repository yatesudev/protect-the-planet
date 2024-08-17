#ifndef ASTEROIDSPAWNER_H
#define ASTEROIDSPAWNER_H
#include "asteroid.h"
#include <memory>

class AsteroidSpawner
{
public:
    AsteroidSpawner();
    void addAsteroid(std::shared_ptr<Asteroid> asteroid){
        m_asteroids.append(asteroid);
    }
private:
    QList<std::shared_ptr<Asteroid>> m_asteroids;
};

#endif // ASTEROIDSPAWNER_H
