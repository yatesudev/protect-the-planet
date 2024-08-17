#include "mainwindow.h"
#include "qevent.h"
#include "ui_mainwindow.h"
#include "QMovie.h"
#include <QDateTime>
#include <QDebug>
#include <QPropertyAnimation>

#include <QtGlobal>
#include <cstdlib>
#include <ctime>
#include <QtCore>

#include <asteroid.h>
#include <memory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    planetLabel = new QLabel(this);
    keyLabel = new QLabel(this);
    asteroidLabel = new QLabel(this);

    srand(time(nullptr));
    randomNumber = rand() % 10;
    randomKeyValue = rand() % 4;
    randomGifNumber = rand() % 3;

    life_list = {ui->label_life_1, ui->label_life_2, ui->label_life_3};
    keyList = {Qt::Key_S, Qt::Key_A, Qt::Key_W, Qt::Key_D};
    key_presetList = {QPixmap(":/S-Key.png"), QPixmap(":/A-Key.png"), QPixmap(":/W-Key.png"), QPixmap(":/D-Key.png")};
    asteroid_gif_presetList = {new QMovie(":/small_astro.gif"),new QMovie(":/medium_astro.gif"),new QMovie(":/big_astro.gif")};

    points.append(QPointF(350, 440));
    points.append(QPointF(640, 440));
    points.append(QPointF(230, 410));
    points.append(QPointF(230, 490));
    points.append(QPointF(420, 460));
    points.append(QPointF(450, 420));
    points.append(QPointF(270, 510));
    points.append(QPointF(660, 510));
    points.append(QPointF(170, 470));
    points.append(QPointF(470, 510));

    points_spawn.append(QPointF(500, -40));
    points_spawn.append(QPointF(740, 40));
    points_spawn.append(QPointF(190, -40));
    points_spawn.append(QPointF(-60, 50));
    points_spawn.append(QPointF(460, -40));
    points_spawn.append(QPointF(340, 20));
    points_spawn.append(QPointF(-40, 130));
    points_spawn.append(QPointF(730, 130));
    points_spawn.append(QPointF(760, 50));
    points_spawn.append(QPointF(540, -40));

    ui->label_score_text->setStyleSheet("color: white;");
    ui->label_score_value->setStyleSheet("color: white;");
    ui->label_time_text->setStyleSheet("color: white;");
    ui->lable_time_value->setStyleSheet("color: white;");

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(CountTimer()));

    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(ChangeRandomValue()));

    BeforeStartGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CountTimer(){
    time_1=time_1.addSecs(1);
    ui->lable_time_value->setText(time_1.toString("mm:ss"));

    qDebug() << time_1.toString("mm:ss");
}

void MainWindow::ChangeRandomValue(){
    randomNumber = rand() % 10;
}

void MainWindow::ChangeFontColor(){

    if(isWhite){
        ui->startGameLabel->setText(QString(""));
        isWhite = false;
    }
    else{
        ui->startGameLabel->setText(QString("PRESS SPACEBAR TO START"));
        isWhite = true;
    }
}

void MainWindow::InitializeGameComponents(){

    timer->start(1000);
    timer2->start(100);
    time_1.setHMS(0,0,0);

    planet = std::make_unique<Planet>(planetLabel, new QMovie(":/planetgif.gif"));
    planet->setLifes(life_list);

    ui->startGameLabel->setText(QString(""));

    startGameBlink->stop();

    astro = new Asteroid(asteroidLabel,keyLabel,asteroid_gif_presetList[randomGifNumber], key_presetList[randomKeyValue], points_spawn[randomNumber], points[randomNumber]);

    connect(astro->getAnimation(), &QPropertyAnimation::finished, this, &MainWindow::checkAnimStatus);
}

void MainWindow::BeforeStartGame(){

    startGameBlink = new QTimer(this);
    connect(startGameBlink, SIGNAL(timeout()), this, SLOT(ChangeFontColor()));
    startGameBlink->start(750);

    ui->startGameLabel->setStyleSheet("color: white;");
    ui->startGameLabel->setText(QString("PRESS SPACEBAR TO START"));
}

void MainWindow::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Space && initOnce){
        InitializeGameComponents();
        initOnce = false;
    }

    if(event->key() == keyList[randomKeyValue] && initOnce == false)
    {
        if(asteroidLabel != nullptr && keyLabel != nullptr)
        {
            score++;
            randomKeyValue = rand() % 4;
            randomGifNumber = rand() % 3;
            astro->resetAndRandomizeAsteroid(asteroid_gif_presetList[randomGifNumber], key_presetList[randomKeyValue],
                                             points_spawn[randomNumber], points[randomNumber]);

            qDebug() << randomNumber;
        }
    }
    else if(event->key() != randomKeyValue && event->key() != Qt::Key_Space)
    {
        if(asteroidLabel != nullptr && keyLabel != nullptr)
        {
            lifeCounter--;
            planet->setLifeCounter(lifeCounter);
        }
        planet->checkDamage(this);
    }

    ui->label_score_value->setText(QString::number(score));
}

int MainWindow::getNewRandomNumber(int lastRandomNumber){
    int newRandomNumber = rand() % 10;
    qDebug() << newRandomNumber;
    if (newRandomNumber == lastRandomNumber)
    {
        newRandomNumber = getNewRandomNumber(lastRandomNumber);
    }
    return newRandomNumber;
}

void MainWindow::checkAnimStatus(){
    astro->resetAndRandomizeAsteroid(asteroid_gif_presetList[randomGifNumber], key_presetList[randomKeyValue],
                                     points_spawn[randomNumber], points[randomNumber]);

    lifeCounter--;
    planet->setLifeCounter(lifeCounter);
    planet->checkDamage(this);
}
