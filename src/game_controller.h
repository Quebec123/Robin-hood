//
// Created by wikto on 07/02/2025.
//
#include "Pair.h"
#include "LiquidCrystal_I2C.h"
#ifndef UNTITLED4_GAME_CONTROLLER_H
#define UNTITLED4_GAME_CONTROLLER_H

class game_controller {
Pair set1;
Pair set2;
LiquidCrystal_I2C lcd;
int mode;
public:
    game_controller();
    void play();
    void pick_mode();
    void detect_hit();
    void game_mode_refleks();
    void after_game(int score);
    void start_game();
    void game_mode_czas();
};


#endif //UNTITLED4_GAME_CONTROLLER_H
