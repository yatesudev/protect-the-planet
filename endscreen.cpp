#include "endscreen.h"
#include "ui_endscreen.h"
#include "mainwindow.h"

EndScreen::EndScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndScreen)
{
    ui->setupUi(this);

    ui->labelGameOver->setStyleSheet("color: red;");
    ui->labelGameOver_2->setStyleSheet("color:lightblue");

    ui->labelGameOver_2->setText(QString("    Score: " + QString::number(m_score)));
}

EndScreen::~EndScreen()
{
    delete ui;
}

void EndScreen::on_buttonPlayAgain_clicked()
{
    MainWindow* mw = new MainWindow();
    mw->show();
    QWidget::close();
}


void EndScreen::on_buttonExit_clicked()
{
    QWidget::close();
}

