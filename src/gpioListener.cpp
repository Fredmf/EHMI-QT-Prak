#include "gpioListener.h"
#include <stdio.h>

void gpioListener::run() {
	buttonLoop();
}

void gpioListener::buttonLoop(){
    wiringPiSetupGpio();
	const int button0 = 27;
    const int button1 = 23;
    const int button2 = 22;
    const int button3 = 17;
    pinMode(button0, INPUT);
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    pinMode(button3, INPUT);
    pullUpDnControl(button0, PUD_UP);
    pullUpDnControl(button1, PUD_UP);
    pullUpDnControl(button2, PUD_UP);
    pullUpDnControl(button3, PUD_UP);
    bool b1pressed=false;
    bool b2pressed=false;
	while(true){
		msleep(100);
        if (digitalRead(button0)){
            b3sig();
        }
        if (digitalRead(button1) && !b1pressed){
        	b1sig();
        	b1pressed=true;
        }
        if (!digitalRead(button1) && b1pressed){
        	b1pressed=false;
        }
        if (digitalRead(button2) && !b2pressed){
            b2sig();
            b2pressed=true;
        }
        if (!digitalRead(button2) && b2pressed){
            b2pressed=false;
        }
        if (digitalRead(button3)){
            b0sig();
        }
	}
}