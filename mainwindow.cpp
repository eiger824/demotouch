#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(100);

    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->label->setText(QString::number(position) + "%");
    ui->horizontalSlider->setValue(position);

    if (position == 100) {
        ui->label_2->setText("Winner! :-)");
    } else {
        ui->label_2->setText("");
    }
}

void MainWindow::on_pushButton_clicked()
{
    if (!m_timer->isActive()) {
        m_timer->start(550);
    } else {
        m_timer->stop();
    }
}

void MainWindow::onTimerTimeout()
{
    on_horizontalSlider_sliderMoved(ui->horizontalSlider->value() + 1);
    qDebug() << "boh";
}
