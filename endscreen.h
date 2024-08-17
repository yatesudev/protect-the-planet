#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <QDialog>

namespace Ui {
class EndScreen;
}

class EndScreen : public QDialog
{
    Q_OBJECT

public:
    explicit EndScreen(QWidget *parent = nullptr);
    ~EndScreen();

    void setScore(int score){
        m_score = score;
    }

private slots:
    void on_buttonPlayAgain_clicked();

    void on_buttonExit_clicked();

private:
    Ui::EndScreen *ui;
    int m_score = 0;
};

#endif // ENDSCREEN_H
