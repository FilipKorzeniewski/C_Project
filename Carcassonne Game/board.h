//  board.h
//  carcassonne game

#ifndef board_h
#define board_h

#define ROWS 10
#define COLUMNS 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiles.h"

void start_board(char [][COLUMNS][TILE_LENGTH]);

void read_board(const char [], char [][COLUMNS][TILE_LENGTH]);

void print_board(char [][COLUMNS][TILE_LENGTH]);

void board_to_file(const char [], char [][COLUMNS][TILE_LENGTH]);

int empty_field(char [][COLUMNS][TILE_LENGTH], int, int);

int biggerX(int);

int smallerX(int);

int biggerY(int);

int smallerY(int);

int can_place(int, int, char [][COLUMNS][TILE_LENGTH], char *);

int count_points(char [][COLUMNS][TILE_LENGTH]);

#endif /* board_h */
