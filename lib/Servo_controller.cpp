//
// Created by wikto on 07/02/2025.
//
#include "Pin_definition.h"
#include "Servo_controller.h"
#include "Arduino.h"
#include "ESP32Servo.h"
Servo_controller::Servo_controller(int pin) {
    this->pin = pin;
    this->position = 0;
    Servo servo;
    servo.attach(pin);
    servo.write(position);
}

void Servo_controller::change_position(bool position) {
    if (position == 0) {
        this -> position = MIN_POSITION;
    } else {
        this -> position = MAX_POSITION;
    }
}

void Servo_controller::set_position(bool position) {
    change_position(position);
    servo.write(this -> position);
}

void Servo_controller::switch_position() {
    if (this->position == MIN_POSITION) {
        this->position = MAX_POSITION;
    } else {
        this->position = MIN_POSITION;
    }
    servo.write(this->position);
}