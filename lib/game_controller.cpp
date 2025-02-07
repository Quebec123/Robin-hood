//
// Created by wikto on 07/02/2025.
//

#include "game_controller.h"
#include "Pin_definition.h"
#include <LiquidCrystal_I2C.h>
game_controller::game_controller() : set1(STEPPER1_PIN_A, STEPPER1_PIN_B, STEPPER1_PIN_C, STEPPER1_PIN_D, STEPS_PER_REVOLUTION, SERVO_1_PIN, RECIEVER1_PIN),
set2(STEPPER2_PIN_A, STEPPER2_PIN_B, STEPPER2_PIN_C, STEPPER2_PIN_D, STEPS_PER_REVOLUTION, SERVO_2_PIN, RECIEVER2_PIN), lcd.begin(16, 2) {
    this->mode = 0;
}

void game_controller::pick_mode() {
    lcd.scrollDisplayLeft();
    lcd.print("Wybierz tryb Gry:");
    if(digitalRead(BUTTON1_PIN) == HIGH) {
        this->mode = 1;
    } else if(digitalRead(BUTTON2_PIN) == HIGH) {
        this->mode = 2;
    }
    lcd.noAutoscroll();
    lcd.print("Wybrano tryb");
}

void game_controller::game_mode_refleks() {
    int start_time = millis();
    int current_time = millis();
    int hits = 0;
    while (current_time - start_time < 30000) {
        current_time = millis();
        lcd.scrollDisplayLeft();
        lcd.println("Tryb refleks");
        lcd.noAutoscroll();
        lcd.print("Czas: ");
        float ftime_UI = current_time-start_time / 1000;
        lcd.print(ftime_UI);
        if(set1.recieve() == true and set1.get_is_on() == true) {
            set1.stop();
            set1.switch_position();
            set1.start();
            hits++;
        }
        if(set2.recieve() == true and set2.get_is_on() == true) {
            set2.stop();
            set2.switch_position();
            set2.start();
            hits++;
        }
        lcd.setCursor(0, 1);
        lcd.print("Trafienia: ");
        lcd.print(hits);
        start_time = millis();
        current_time = millis();
        while(current_time - start_time < 1000) {
            if(digitalRead(BUTTON1_PIN) == HIGH and digitalRead(BUTTON2_PIN) == HIGH) {
                lcd.clear();
                pick_mode();
            }

        }
    }
}
