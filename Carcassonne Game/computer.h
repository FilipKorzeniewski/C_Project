//  computer.h
//  carcassonne game

#ifndef computer_h
#define computer_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tiles.h"
#include "board.h"
#include "user.h"

void picking_the_tile(char **, set*);

void rotating_the_tile(char *);

void placing_on_board(char [][COLUMNS][TILE_LENGTH], set*, char *);

void play_computer(void);

#endif /* computer_h */
