//
// Created by wikto on 07/02/2025.
//
#include "Pair.h"
#ifndef UNTITLED4_GAME_CONTROLLER_H
#define UNTITLED4_GAME_CONTROLLER_H
#include <LiquidCrystal_I2C.h>

class game_controller {
Pair set1;
Pair set2;
int mode;
LiquidCrystal_I2C lcd;
public:
    game_controller();
    void play();
    void pick_mode();
    void game_mode_refleks();
};


#endif //UNTITLED4_GAME_CONTROLLER_H
