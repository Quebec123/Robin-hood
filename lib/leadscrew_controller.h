//
// Created by wikto on 07/02/2025.
//

#ifndef UNTITLED4_LEADSCREW_CONTROLLER_H
#define UNTITLED4_LEADSCREW_CONTROLLER_H
#include "Stepper.h"

class leadscrew_controller {
int pin_A;
int pin_B;
int pin_C;
int pin_D;
int stepsPerRevolution;
bool is_moving;
bool direction;
Stepper stepper;
public:
    leadscrew_controller(int pin_A, int pin_B, int pin_C, int pin_D, int stepsPerRevolution);
    void stop();
    void start();
    void move_random();
    bool random();
    void move();
};


#endif //UNTITLED4_LEADSCREW_CONTROLLER_H
