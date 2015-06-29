#include <iostream>
#include "mainwindow.h"
#include "ui_gui.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    gpiol.start();

    connect(&gpiol,SIGNAL(b0sig()),this,SLOT(handleButton0()));
    connect(&gpiol,SIGNAL(b1sig()),this,SLOT(handleButton1()));
    connect(&gpiol,SIGNAL(b2sig()),this,SLOT(handleButton2()));
    connect(&gpiol,SIGNAL(b3sig()),this,SLOT(handleButton3()));

    ui->item0_label->setText("Benzinstand");
    ui->item1_label->setText("Batterie");
    ui->item2_label->setText("Kühlwasser");
    ui->item3_label->setText("Ölstand");
    ui->item4_label->setText("TÜV / AU");

    ui->topBar_button0->setText("-");
    ui->topBar_button1->setText("hoch");
    ui->topBar_button2->setText("runter");
    ui->topBar_button3->setText("+");
    
    connect(ui->topBar_button0, SIGNAL (clicked()),this, SLOT (handleButton0()));
    connect(ui->topBar_button1, SIGNAL (clicked()),this, SLOT (handleButton1()));
    connect(ui->topBar_button2, SIGNAL (clicked()),this, SLOT (handleButton2()));
    connect(ui->topBar_button3, SIGNAL (clicked()),this, SLOT (handleButton3()));

    selected=0;
	setBars(50,50,50,50,50);

	scene = new QGraphicsScene(this);
	ui->graphicsView->setScene(scene);


	QBrush yellowBrush(Qt::yellow);
	QBrush blackBrush(Qt::black);
	QPen blackPen(Qt::black);
	blackPen.setWidth(2);

	face = scene->addEllipse(0,0,130,130,blackPen,yellowBrush);
	rEye = scene->addEllipse(80,30,20,20,blackPen,blackBrush);
	lEye = scene->addEllipse(30,30,20,20,blackPen,blackBrush);
	rMouth = scene->addLine(65,90,100,90,blackPen);
	lMouth = scene->addLine(65,90,30,90,blackPen);

	updateToStatus();

}

MainWindow::~MainWindow(){
}

void MainWindow::setBars(int a, int b, int c, int d, int e){
	ui->item0_pbar->setValue(a);
	ui->item1_pbar->setValue(b);
	ui->item2_pbar->setValue(c);
	ui->item3_pbar->setValue(d);
	ui->item4_pbar->setValue(e);
}

void MainWindow::setBar(int num, int val){
	switch (num){
		case 0:
			ui->item0_pbar->setValue(val);
			break;
		case 1:
			ui->item1_pbar->setValue(val);
			break;
		case 2:
			ui->item2_pbar->setValue(val);
			break;
		case 3:
			ui->item3_pbar->setValue(val);
			break;
		case 4:
			ui->item4_pbar->setValue(val);
			break;
		default:
			break;
	}
}


void MainWindow::incBar(int num, int val){
	switch (num){
		case 0:
			ui->item0_pbar->setValue(ui->item0_pbar->value()+val);
			break;
		case 1:
			ui->item1_pbar->setValue(ui->item1_pbar->value()+val);
			break;
		case 2:
			ui->item2_pbar->setValue(ui->item2_pbar->value()+val);
			break;
		case 3:
			ui->item3_pbar->setValue(ui->item3_pbar->value()+val);
			break;
		case 4:
			ui->item4_pbar->setValue(ui->item4_pbar->value()+val);
			break;
		default:
			break;
	}
}


void MainWindow::decBar(int num, int val){
	switch (num){
		case 0:
			ui->item0_pbar->setValue(ui->item0_pbar->value()-val);
			break;
		case 1:
			ui->item1_pbar->setValue(ui->item1_pbar->value()-val);
			break;
		case 2:
			ui->item2_pbar->setValue(ui->item2_pbar->value()-val);
			break;
		case 3:
			ui->item3_pbar->setValue(ui->item3_pbar->value()-val);
			break;
		case 4:
			ui->item4_pbar->setValue(ui->item4_pbar->value()-val);
			break;
		default:
			break;
	}
}

void MainWindow::setSelectedFrame(){
	switch (selected){
		case 0:
			ui->item0_frame->setStyleSheet("background-color:#B0B0B0;");
			ui->item1_frame->setStyleSheet("");
			ui->item2_frame->setStyleSheet("");
			ui->item3_frame->setStyleSheet("");
			ui->item4_frame->setStyleSheet("");
			break;
		case 1:
			ui->item0_frame->setStyleSheet("");
			ui->item1_frame->setStyleSheet("background-color:#B0B0B0;");
			ui->item2_frame->setStyleSheet("");
			ui->item3_frame->setStyleSheet("");
			ui->item4_frame->setStyleSheet("");
			break;
		case 2:
			ui->item0_frame->setStyleSheet("");
			ui->item1_frame->setStyleSheet("");
			ui->item2_frame->setStyleSheet("background-color:#B0B0B0;");
			ui->item3_frame->setStyleSheet("");
			ui->item4_frame->setStyleSheet("");
			break;
		case 3:
			ui->item0_frame->setStyleSheet("");
			ui->item1_frame->setStyleSheet("");
			ui->item2_frame->setStyleSheet("");
			ui->item3_frame->setStyleSheet("background-color:#B0B0B0;");
			ui->item4_frame->setStyleSheet("");
			break;
		case 4:
			ui->item0_frame->setStyleSheet("");
			ui->item1_frame->setStyleSheet("");
			ui->item2_frame->setStyleSheet("");
			ui->item3_frame->setStyleSheet("");
			ui->item4_frame->setStyleSheet("background-color:#B0B0B0;");
			break;
		default:
			break;
	}
}

void MainWindow::updateToStatus(){
	setSelectedFrame();
	int score = ui->item0_pbar->value()+ui->item1_pbar->value()+ui->item2_pbar->value()+ui->item3_pbar->value()+ui->item4_pbar->value();
	int outer = (-0.04) * score + 100;
	int center = 0.04 * score + 80;
	rMouth->setLine(65,(float)center,100,(float)outer);
	lMouth->setLine(65,(float)center,30,(float)outer);
}

//SLOTS
void MainWindow::handleButton0(){ //minus
	decBar(selected,1);
	updateToStatus();
}
void MainWindow::handleButton1(){ //up
	selected--;
	if (selected < 0){
		selected = 4;
	}
	updateToStatus();
}
void MainWindow::handleButton2(){ //down
	selected++;
	selected=selected%5;
	updateToStatus();
}
void MainWindow::handleButton3(){ //plus
	incBar(selected,1);
	updateToStatus();
}

void MainWindow::connectButtons(gpioListener* in){
	connect(in,SIGNAL(mSig()),this,SLOT(handleButton0));
}
