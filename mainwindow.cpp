#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <commatrix.h>
#include <stokes.h>
#include <polarizer.h>
#include <abstractretarder.h>

#include <math.h>
#include <QDir>
#include <QString>
#include <QTextStream>
#include <QTime>
#include <QComboBox>
#include <QCheckBox>
#include <QDebug>

const double PI = 3.14159265359;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dostuff(QVector<double> &angle,QVector<double> &intensity)
{
    float szero = ui->S0LE->text().toFloat();
    float sone = ui->S1LE->text().toFloat();
    float stwo = ui->S2LE->text().toFloat();
    float sthree = ui->S3LE->text().toFloat();

    complex<float> S0(szero,0.0);
    complex<float> S1(sone,0.0);
    complex<float> S2(stwo,0.0);
    complex<float> S3(sthree,0.0);

    Stokes S;
    S.populate(S0,S1,S2,S3);

    polarizer pol(0.0f);//(float) (PI/2)
    abstractRetarder retar(0,PI/2);
    pol.recalc();
    for(int i = 0; i<360;i++)
    {
        retar.setRo((float) (PI*i/180));
        retar.recalc();
        comMatrix result = pol*retar*pol*S;

        angle.append((double)i);
        intensity.append( (double) abs( result.getA11() ) );

        //ui->tE->append(QString::number( abs(result.getA11()) ));
    }
}

void MainWindow::initialize()
{
    ui->widget->xAxis->setRange(0,360);
    ui->widget->yAxis->setRange(0.0,1.1);
    ui->widget_2->xAxis->setRange(0,360);
    ui->widget_2->yAxis->setRange(0.0,1.1);
    ui->widget_3->xAxis->setRange(0,360);
    ui->widget_3->yAxis->setRange(0.0,1.1);
    ui->widget_4->xAxis->setRange(0,360);
    ui->widget_4->yAxis->setRange(0.0,1.1);
    ui->scrollArea->setWidgetResizable(true);
    lay = new QHBoxLayout(ui->scrollArea);
    ui->scrollArea->setWidgetResizable(true);
}

void MainWindow::on_pbLaunch_clicked()
{
    QVector<double> angle, intensityS0;
    QVector<double> intensityS1;
    QVector<double> intensityS2;
    QVector<double> intensityS3;
    //dostuff(angle,intensity);
    float szero = ui->S0LE->text().toFloat();
    float sone = ui->S1LE->text().toFloat();
    float stwo = ui->S2LE->text().toFloat();
    float sthree = ui->S3LE->text().toFloat();

    complex<float> S0(szero,0.0);
    complex<float> S1(sone,0.0);
    complex<float> S2(stwo,0.0);
    complex<float> S3(sthree,0.0);

    Stokes S;
    S.populate(S0,S1,S2,S3);

    for(int ang = 0;ang<360;ang++)
    {
        comMatrix result = S;
        for(int i = 0; i<listas.size();i++)
        {
            float rotationAngle = PI*angles.at(i)->text().toFloat()/180.0;
            if(checkBoxes.at(i)->isChecked())
            {
               rotationAngle = rotationAngle + (float)(PI*ang/180.0);
            }
            ui->tE->append(QString::number(rotationAngle));
            QString name = names.at(i)->objectName();
            if(QString::compare(name,QString("polarizer"))==0)
            {
                polarizer pol(rotationAngle);
                pol.recalc();
                result = pol*result;
            }
            else if(QString::compare(name,QString("retarder"))==0)
            {
                float phaseS = phaseShifts.at(i)->text().toFloat()*PI/180.0;
                abstractRetarder ret(rotationAngle,phaseS);
                ret.recalc();
                result = ret*result;
            }
        }
        angle.append(double(ang));
        intensityS0.append((double) abs(result.getA11()));
        intensityS1.append((double) abs(result.getA21()));
        intensityS2.append((double) abs(result.getA31()));
        intensityS3.append((double) abs(result.getA41()));
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->setData(angle,intensityS0);
    ui->widget->replot();
    ui->widget_2->addGraph();
    ui->widget_2->graph(0)->setData(angle,intensityS1);
    ui->widget_2->replot();
    ui->widget_3->addGraph();
    ui->widget_3->graph(0)->setData(angle,intensityS2);
    ui->widget_3->replot();
    ui->widget_4->addGraph();
    ui->widget_4->graph(0)->setData(angle,intensityS3);
    ui->widget_4->replot();
}

void MainWindow::on_pBclear_clicked()
{
    ui->tE->clear();
}

void MainWindow::on_pBadd_clicked()
{
    QVBoxLayout *vbox = new QVBoxLayout;
    QLineEdit *angleLE = new QLineEdit;
    QLabel *vardas = new QLabel;
    QCheckBox *check = new QCheckBox;
    QLineEdit *phaseLE = new QLineEdit;

    check->setText(QString("rotating"));
    check->setChecked(false);
    vardas->setObjectName(QString("polarizer"));
    vardas->setText(QString("Polarizer\nstarting angle:"));
    angleLE->setText("0");
    phaseLE->setText("0");

    vbox->addWidget(vardas);
    vbox->addWidget(angleLE);
    vbox->addWidget(check);

    QWidget *wi =  new QWidget;
    wi->setLayout(vbox);
    lay->addWidget(wi);
    listas.append(wi);
    boxes.append(vbox);

    angles.append(angleLE);
    names.append(vardas);
    checkBoxes.append(check);
    phaseShifts.append(phaseLE);

    QWidget *wid = new QWidget();
    wid->setLayout(lay);
    ui->scrollArea->setWidget(wid);
}

void MainWindow::on_pB_remove_clicked()
{
    if(listas.size()>0)
    {
        lay->removeWidget(listas.last());
        listas.removeLast();
        names.removeLast();
        angles.removeLast();
        checkBoxes.removeLast();
        phaseShifts.removeLast();
        QWidget *wid =  new QWidget;
        wid->setLayout(lay);
        ui->scrollArea->setWidget(wid);
        ui->scrollArea->update();
    }
}

void MainWindow::on_pBadd_2_clicked()
{
    QVBoxLayout *vbox = new QVBoxLayout;
    QLineEdit *angleLE = new QLineEdit;
    QLineEdit *phaseLE = new QLineEdit;
    QLabel *vardas = new QLabel;
    QLabel *phase = new QLabel;
    QCheckBox *check = new QCheckBox;

    check->setText(QString("rotating"));
    check->setChecked(false);
    vardas->setObjectName(QString("retarder"));
    vardas->setText(QString("Retarder\nstarting angle:"));
    phase->setText(QString("phase shift:"));
    angleLE->setText("0");
    phaseLE->setText("0");

    vbox->addWidget(vardas);
    vbox->addWidget(angleLE);
    vbox->addWidget(phase);
    vbox->addWidget(phaseLE);
    vbox->addWidget(check);

    QWidget *wi =  new QWidget;
    wi->setLayout(vbox);
    lay->addWidget(wi);
    listas.append(wi);
    boxes.append(vbox);

    angles.append(angleLE);
    names.append(vardas);
    checkBoxes.append(check);
    phaseShifts.append(phaseLE);

    QWidget *wid = new QWidget();
    wid->setLayout(lay);
    ui->scrollArea->setWidget(wid);
}
