#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qdatetime.h"
#include <QMainWindow>
#include <QTimer>
#include "QLabel"
#include <QPropertyAnimation>
#include "asteroid.h"
#include "planet.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTime time_1;
    QTime time_2;
    int getNewRandomNumber(int lastRandomNumber);
    void InitializeGameComponents();
    void BeforeStartGame();

    int getScore() {
        return (score);
    }

public slots:
    void CountTimer();
    void checkAnimStatus();
    void ChangeRandomValue();
    void ChangeFontColor();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timer2;
    QLabel *asteroidLabel;
    QLabel *keyLabel;
    QLabel *planetLabel;
    QPropertyAnimation *animation;
    int score = 0;
    int lifeCounter = 3;
    void keyPressEvent(QKeyEvent *event);
    std::unique_ptr<Asteroid> asteroid;
    std::shared_ptr<Asteroid> asteroid_s_1;
    std::shared_ptr<Asteroid> asteroid_s_2;
    Asteroid* astro;
    Asteroid* astro2;
    std::unique_ptr<Asteroid> asteroid2;
    std::unique_ptr<Planet> planet;
    QList<Qt::Key> keyList;
    int randomKeyValue;
    int randomNumber;
    int randomGifNumber;
    QList<QPointF> points_spawn;
    QList<QMovie*> asteroid_gif_presetList;
    QList<QPixmap> key_presetList;
    QList<QPointF> points;
    bool isWhite = true;
    QList<QLabel*> life_list;
    QTimer* startGameBlink;
    bool initOnce = true;
};
#endif // MAINWINDOW_H
