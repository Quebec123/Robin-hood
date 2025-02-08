#include <Arduino.h>
#include "Servo_controller.h"
#include "leadscrew_controller.h"
#include "game_controller.h"
#include "Pin_definition.h"
#include <time.h>
#include <stdlib.h>
void setup() {
    pinMode(SERVO_1_PIN, OUTPUT);
    pinMode(SERVO_2_PIN, OUTPUT);
    pinMode(STEPPER1_PIN_A, OUTPUT);
    pinMode(STEPPER1_PIN_B, OUTPUT);
    pinMode(STEPPER1_PIN_C, OUTPUT);
    pinMode(STEPPER1_PIN_D, OUTPUT);
    pinMode(STEPPER2_PIN_A, OUTPUT);
    pinMode(STEPPER2_PIN_B, OUTPUT);
    pinMode(STEPPER2_PIN_C, OUTPUT);
    pinMode(STEPPER2_PIN_D, OUTPUT);
    pinMode(RECIEVER1_PIN, INPUT);
    pinMode(RECIEVER2_PIN, INPUT);
    pinMode(BUTTON1_PIN, INPUT);
    pinMode(BUTTON2_PIN, INPUT);
    Serial.begin(9600);

}

void loop() {
game_controller game;
game.pick_mode();
Servo_controller servo1(SERVO_1_PIN);
servo1.set_position(0);
}