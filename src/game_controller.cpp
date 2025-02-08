//
// Created by wikto on 07/02/2025.
//

#include "game_controller.h"
#include "Pin_definition.h"
#include "LiquidCrystal_I2C.h"

game_controller::game_controller()
        : lcd(0x27, 16, 2), // Initialize the lcd object
          set1(STEPPER1_PIN_A, STEPPER1_PIN_B, STEPPER1_PIN_C, STEPPER1_PIN_D, STEPS_PER_REVOLUTION, SERVO_1_PIN, RECIEVER1_PIN),
          set2(STEPPER2_PIN_A, STEPPER2_PIN_B, STEPPER2_PIN_C, STEPPER2_PIN_D, STEPS_PER_REVOLUTION, SERVO_2_PIN, RECIEVER2_PIN) {
    lcd.begin(20, 2);
    this->mode = 0;
}

void game_controller::detect_hit() {
    if(set1.recieve() == true and set1.get_is_on() == true) {
        set1.get_hit();
        set2.become_target();
        Serial.println("Cel 1 trafiony");
    }
    if(set2.recieve() == true and set2.get_is_on() == true) {
        set2.get_hit();
        set1.become_target();
        Serial.println("Cel 2 trafiony");
    }
}


void game_controller::after_game(int score) {
lcd.clear();
lcd.print("Ilość punktów: ");
lcd.println(score);
lcd.print("naciśnij przycisk");
}

void game_controller::start_game() {
    lcd.println("Gra zacznie się za:");
    lcd.print("3");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("2");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("1");
    lcd.clear();
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
    delay(1000);
}



void game_controller::game_mode_refleks() {
    int start_time = millis();
    int current_time = millis();
    int hits = 0;
    while (current_time - start_time < 30000) {
        current_time = millis();
        lcd.scrollDisplayLeft();
        lcd.println("Tryb refleksomierz");
        lcd.noAutoscroll();
        lcd.print("Czas: ");
        float ftime_UI = current_time-start_time / 1000;
        lcd.print(ftime_UI);
        detect_hit();
        lcd.setCursor(0, 1);
        lcd.print("Trafienia: ");
        lcd.print(hits);
        Serial.println(hits);
        start_time = millis();
        current_time = millis();
    }
    start_time = millis();
    current_time = millis();
    while (current_time - start_time <5000){
        current_time = millis();
        after_game(hits);
    }
}

void game_controller::play(){
    if(this->mode ==1){
        start_game();
        game_mode_refleks();
    }
    if(this->mode ==2){
        start_game();
        game_mode_czas();
    }
}

void game_controller::game_mode_czas() {
    int start_time = millis();
    int hits = 0;
    int time = 0;
    while(hits<10) {
        int current_time = millis();
        set1.become_target();
        set2.get_hit();
        detect_hit();
        hits++;
        lcd.clear();
        time = current_time - start_time;
        lcd.println("Czas:");
        lcd.println(time);
    }
    int end_time = millis();
    time = end_time - start_time/1000;
    after_game(time);
}