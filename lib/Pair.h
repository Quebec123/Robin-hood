//
// Created by wikto on 07/02/2025.
//
#include "leadscrew_controller.h"
#include "Servo_controller.h"
#include "reciever.h"
#ifndef UNTITLED4_PAIR_H
#define UNTITLED4_PAIR_H


class Pair {
leadscrew_controller leadscrew;
Servo_controller servo;
reciever reciever;
bool is_on;
public:
    Pair(int pin_A, int pin_B, int pin_C, int pin_D, int stepsPerRevolution, int servo_pin, int reciever_pin);
    void start();
    void stop();
    void move();
    void move_random();
    void set_position(bool position);
    void switch_position();
    bool recieve();
    bool random();
    bool get_is_on();
    void set_is_on(bool is_on);
};


#endif //UNTITLED4_PAIR_H
