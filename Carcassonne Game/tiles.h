//  tiles.h
//  carcassonne game

#ifndef tiles_h
#define tiles_h

#define TILE_LENGTH 6
#define POSSIBLE_TILES 14
#define MAX_SIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "board.h"

typedef struct {
    int size;
    char **tiles;
} set;

void number_of_tiles(const char [], set*);

void read_tiles(const char fn[], set*);

void print_tiles(set*);

void swap(char *, int, int);

void rotate_tile(char *, int);

void tiles_to_file(const char [], set*);

int tile_in_set(char *, set*);

void remove_used_tile(char *, set*);

void tiles_generator(const char [], const char []);

int points_for_tile(char *);

#endif /* tiles_h */
