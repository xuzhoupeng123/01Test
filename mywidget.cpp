#include "mywidget.h"
#include "ui_mywidget.h"
#include<QThread>
#include<QDebug>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    myTimer = new QTimer(this);

    //只要定时器启动，自动触发timeout();
    connect(myTimer,&QTimer::timeout,this,&MyWidget::dealTimeout);



}
void MyWidget::dealTimeout()
{
    static int  i=0;
    i++;

    //设置lcd的值
    ui->lcdNumber->display(i);


}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{

    //如果定时器没有工作
    if(myTimer->isActive()==false)
    {
        myTimer->start(100);
    }

    //非常复杂的数据处理，耗时较长
    QThread::sleep(5);

    //处理完数据后，关闭定时器
    myTimer->stop();
    qDebug()<<"over";
}
