//
// Created by wikto on 07/02/2025.
//

#include "reciever.h"
#include "Arduino.h"

reciever::reciever(int pin) {
    this->pin = pin;
}

int reciever::recieve() {
    return pulseIn(this->pin, HIGH,100);
}