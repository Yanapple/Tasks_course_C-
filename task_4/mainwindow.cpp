#include <QTimer>
#include <QPushButton>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(300, 600);
    auto timer = new QTimer(this);
        timer->setInterval(700);

    connect(timer, &QTimer::timeout, this, //это.. метод, в котором в качестве параметра
            //в скобках {} я записываю функцию, что должно происходить по таймеру, да?..
            //и передаю для функции widget and timer как параметры? Похоже на то, не забыть бы
            [this, timer]
            {
                auto btn = new QPushButton(this); //создание новой кнопки
                btn->setText("*"); //задаем текст на кнопке
                btn->setFixedSize(25, 25); //габариты кнопки
                btn->setStyleSheet(" background-color: white; color: blue;"); //цвет
                int speed = rand()%4 + 1; //рандомайзер скорости падения
                auto x = this->width() - btn->width(); //вариация по ширине окна - габарит кнопки
                btn->move(rand() % x, 50); //появление по ширине окна и на высоте 50px от верха
                auto moveBtn = [btn, speed, this]() //передвижение с ускорением, функция-лямбда
                {
                btn->move(btn->x(), btn->y() + speed); //к Y коор-те прибавляется N число..
                if (btn->y() >= this->height())
                    {
                        this->setWindowTitle("YOU LOOSE");
                        this->setStyleSheet("background-color: red;");
                    }
                };

                auto timerForMoving = new QTimer(btn);
                connect(timerForMoving, &QTimer::timeout, btn, moveBtn); //..через каждые M секунд.
                        timerForMoving->start(1000/45);
                connect(btn, &QPushButton::clicked, [btn](){btn->deleteLater();}); //удаление по щелчку
                btn->show();
             });
    timer->start();

}

MainWindow::~MainWindow()
{
}
