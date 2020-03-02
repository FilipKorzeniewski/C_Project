//  tiles.c
//  carcassonne game

#include "tiles.h"

void number_of_tiles(const char fn[], set *p){
    int counter = 0;
    char tile[TILE_LENGTH];
    FILE *f;
    if((f = fopen(fn, "r+"))){
        while(fscanf(f, "%s", tile) != EOF){
            counter++;
        }
    }else{
        printf("Error: FILE NOT FOUND\n");
        counter = 0;
    }
    p->size = counter;
}

void read_tiles(const char fn[], set *p){
    int i;
    FILE *f;
    p->tiles = malloc(p->size * sizeof(char *));
    for(i = 0; i < p->size; i++){
        *(p->tiles + i) = malloc(TILE_LENGTH);
    }
    if((f = fopen(fn, "r+"))){
        i = 0;
        while(fscanf(f, "%s", *(p->tiles + i)) != EOF){
            i++;
        }
        fclose(f);
    }else{
        printf("Error: FILE NOT FOUND\n");
        free(p->tiles);
    }
}

void print_tiles(set *p){
    int i;
    printf("Available tiles:\n");
    for(i = 0; i < p->size; i++){
        if(*(*(p->tiles + i)) >= 'a' && *(*(p->tiles + i)) <= 'z'){
            printf("%s\n", p->tiles[i]);
        }
    }
    printf("\n");
}

void swap(char *t, int a, int b){
    char c = t[a];
    t[a] = t[b];
    t[b] = c;
}

void rotate_tile(char *t, int r){
    int i;
    for(i = 0; i < r; i++){
        swap(t, 0, 3);
        swap(t, 2, 3);
        swap(t, 1, 2);
    }
}

void tiles_to_file(const char fn[], set *p){
    int i;
    FILE *f;
    if((f = fopen(fn, "w+"))){
        for(i = 0; i < p->size; i++){
            fprintf(f, "%s\n", *(p->tiles + i));
        }
        fclose(f);
    }else{
        printf("Error: COULD NOT OPEN THE FILE");
    }
}

int tile_in_set(char *tile, set *p){
    int i;
    for(i = 0; i < p->size; i++){
        if(strcmp(tile, *(p->tiles + i)) == 0){
            return i;
        }
    }
    return -1;
}

void remove_used_tile(char *tile, set *p){
    int x = tile_in_set(tile, p);
    if(x >= 0){
        *(p->tiles + x) = "";
    }
}

void tiles_generator(const char fn1[], const char fn2[]){
    int i;
    char possible_tiles[POSSIBLE_TILES][TILE_LENGTH];
    FILE *f;
    if((f = fopen(fn1, "r+"))){
        i = 0;
        while(fscanf(f, "%s", possible_tiles[i]) != EOF){
            i++;
        }
        fclose(f);
        srand((unsigned int)time(NULL));
        if((f = fopen(fn2, "w+"))){
            for(i = 0; i < ROWS * COLUMNS; i++){
                fprintf(f, "%s ", possible_tiles[rand() % POSSIBLE_TILES]);
            }
        }else{
            printf("Error: FILE NOT FOUND");
        }
    }else{
        printf("Error: FILE NOT FOUND");
    }
}

int points_for_tile(char *tile){
    int i, points = 0;
    for(i = 0; i < TILE_LENGTH - 1; i++){
        if(*(tile + i) == 'r' || *(tile + i) == 'c' || *(tile + i) == 't'){
            points++;
        }
    }
    return points;
}

