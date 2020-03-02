//  main.c
//  carcassonne game

#include <stdio.h>
#include "tiles.h"
#include "board.h"
#include "user.h"
#include "computer.h"

int main(){
    //tiles_generator("possible_tiles.txt", "starting_tiles.txt");
    play_computer();
    return 0;
}
