//  user.h
//  carcassonne game

#ifndef user_h
#define user_h

#include <stdio.h>
#include "tiles.h"
#include "board.h"
#include "computer.h"

void pick_tile(char **);

void tile_on_board(char * [][COLUMNS], set*, char *, int, int);

void pick_coordinates(int *, int *);

void user_rotate_tile(char *);

void play_as_user(void);

#endif /* user_h */
