#ifndef mainwindow_h
#define mainwindow_h

#include <QMainWindow>
#include <QScopedPointer>
#include <QProgressBar>
#include <QPushButton>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include "gpioListener.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

public:
    void setBars(int a, int b, int c, int d, int e);
    void setBar(int num, int val);
    void updateToStatus();
    void setSelectedFrame();
    void incBar(int num, int val);
    void decBar(int num, int val);
    void connectButtons(gpioListener* in);


private:
    QScopedPointer<Ui::MainWindow> ui;
    gpioListener gpiol;
 	QPushButton *m_button;
 	int selected;
 	QGraphicsScene *scene;
 	QGraphicsEllipseItem *face;
 	QGraphicsEllipseItem *lEye;
 	QGraphicsEllipseItem *rEye;
	QGraphicsLineItem *lMouth;
	QGraphicsLineItem *rMouth;


public slots:
	void handleButton0();
	void handleButton1();
	void handleButton2();
	void handleButton3();
};

#endif
