//
// Created by wikto on 07/02/2025.
//

#include "leadscrew_controller.h"
#include "Stepper.h"
#include <stdlib.h>
#include <time.h>

leadscrew_controller::leadscrew_controller(int pin_A, int pin_B, int pin_C, int pin_D, int stepsPerRevolution)
        : stepper(stepsPerRevolution, pin_A, pin_B, pin_C, pin_D) {
    this->pin_A = pin_A;
    this->pin_B = pin_B;
    this->pin_C = pin_C;
    this->pin_D = pin_D;
    this->stepsPerRevolution = stepsPerRevolution;
    this->is_moving = false;
    this->direction = true;
    stepper.setSpeed(60);
}

void leadscrew_controller::stop() {
    stepper.step(0);
    this->is_moving = false;
}

bool leadscrew_controller::random() {
    bool random = rand() %2;
    return random;
}

void leadscrew_controller::start() {
    this->is_moving = true;
}

void leadscrew_controller::move_random() {
    bool random_direction = random();
    if (random_direction != this-> direction){
        this->direction = random_direction;
    }
    move();
}

void leadscrew_controller::move() {
    if (this->is_moving) {
        if (this->direction) {
            stepper.step(stepsPerRevolution);
        } else {
            stepper.step(-stepsPerRevolution);
        }
    }
}