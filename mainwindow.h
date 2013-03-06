#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void dostuff(QVector<double> &angle,QVector<double> &intensity);
    void initialize();



private slots:
    void on_pbLaunch_clicked();
    void on_pBclear_clicked();
    void on_pBadd_clicked();
    void on_pB_remove_clicked();

    void on_pBadd_2_clicked();

private:
    Ui::MainWindow *ui;
    QHBoxLayout *lay;
    QWidgetList listas;
    QList<QLabel*> names;
    QList<QLineEdit*> angles;
    QList<QCheckBox*> checkBoxes;
    QList<QVBoxLayout*> boxes;
    QList<QLineEdit*> phaseShifts;
};

#endif // MAINWINDOW_H
