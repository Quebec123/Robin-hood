//
// Created by wikto on 07/02/2025.
//

#ifndef UNTITLED4_SERVO_CONTROLLER_H
#define UNTITLED4_SERVO_CONTROLLER_H
#include "Servo.h"

class Servo_controller {
    bool position;
    int pin;
    Servo servo;
public:
    Servo_controller(int pin);
    void change_position(bool position);
    void set_position(bool position);
    void switch_position();
};


#endif //UNTITLED4_SERVO_CONTROLLER_H
