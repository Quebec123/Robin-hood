//
// Created by wikto on 07/02/2025.
//

#include "Pair.h"

Pair::Pair(int pin_A, int pin_B, int pin_C, int pin_D, int stepsPerRevolution, int servo_pin, int reciever_pin) : leadscrew(pin_A, pin_B, pin_C, pin_D, stepsPerRevolution), servo(servo_pin), recieverled(reciever_pin) {
    this->is_on = false;
}

bool Pair::random() {
    return leadscrew.random();
}

bool Pair::recieve() {
    return recieverled.recieve();
}

void Pair::move() {
    leadscrew.move();
}

void Pair::move_random() {
    leadscrew.move_random();
}

void Pair::set_position(bool position) {
    servo.set_position(position);
}

void Pair::switch_position() {
    servo.switch_position();
}

void Pair::start() {
    this->is_on = false;
    servo.switch_position();
    leadscrew.start();
}

void Pair::stop() {
    leadscrew.stop();
    this->is_on = true;
    servo.switch_position();
}

bool Pair::get_is_on() {
    return this->is_on;
}

void Pair::set_is_on(bool is_on) {
    this->is_on = is_on;
}

void Pair::get_hit() {
    this->is_on = false;
    servo.switch_position();
    leadscrew.move_random();
}
 void Pair::become_target() {
    this->is_on = true;
    leadscrew.stop();
    servo.switch_position();
}

