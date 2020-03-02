//  board.c
//  carcassonne game

#include "board.h"

void start_board(char t[][COLUMNS][TILE_LENGTH]){
    int i, j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            strcpy(t[i][j], "\t");
        }
    }
}

void read_board(const char fn[], char t[][COLUMNS][TILE_LENGTH]){
    int i, j;
    FILE *f;
    if((f = fopen(fn, "r+"))){
        for(i = 0; i < ROWS; i++){
            for(j = 0; j < COLUMNS; j++){
                fscanf(f, "%s", t[i][j]);
            }
        }
    }else{
        printf("Error: FILE NOT FOUND\n");
        
    }
}

void print_board(char t[][COLUMNS][TILE_LENGTH]){
    int i, j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            if(t[i][j][0] >= 'a' && t[i][j][0] <= 'z'){
                printf(" %s ", t[i][j]);
            }else{
                printf("   X   ");
            }
        }
        printf("\n");
    }
}

void board_to_file(const char fn[], char t[][COLUMNS][TILE_LENGTH]){
    int i, j;
    FILE *f;
    if((f = fopen(fn, "w+"))){
        for(i = 0; i < ROWS; i++){
            for(j = 0; j < COLUMNS; j++){
                fprintf(f, "%s", t[i][j]);
            }
            fprintf(f, "%s", "\n");
        }
    }else{
        printf("Error\n");
    }
}

int empty_field(char t[][COLUMNS][TILE_LENGTH], int x, int y){
    if(x >= 0 && x < ROWS && y >= 0 && y < COLUMNS){
        if(strcmp(t[x][y], "\t") == 0){
            return 1;
        }
    }
    return 0;
}

int biggerX(int x){
    if(x + 1 == ROWS){
        return x;
    }
    return x + 1;
}

int smallerX(int x){
    if(x - 1 < 0){
        return x;
    }
    return x - 1;
}

int biggerY(int y){
    if(y + 1 == COLUMNS){
        return y;
    }
    return y + 1;
}

int smallerY(int y){
    if(y - 1 < 0){
        return y;
    }
    return y - 1;
}

int can_place(int x, int y, char t[][COLUMNS][TILE_LENGTH], char *tile){
    if(x >= 0 && x < ROWS && y >= 0 && y < COLUMNS){
        if(empty_field(t, x, y) == 1){
            if(empty_field(t, smallerX(x), y) == 0 && t[smallerX(x)][y][2] != tile[0]){
                return 0;
            }else if(empty_field(t, x, biggerY(y)) == 0 && t[x][biggerY(y)][3] != tile[1]){
                return 0;
            }else if(empty_field(t, biggerX(x), y) == 0 && t[biggerX(x)][y][0] != tile[2]){
                return 0;
            }else if(empty_field(t, x, smallerY(y)) == 0 && t[x][smallerY(y)][1] != tile[3]){
                return 0;
            }
            return 1;
        }
    }
    return 0;
}

int count_points(char t[][COLUMNS][TILE_LENGTH]){
    int i, j, points = 0;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            points += points_for_tile(t[i][j]);
            if(t[i][j][4] == 't'){
                if(strcmp(t[smallerX(i)][smallerY(j)], "\t") != 0){
                    points++;
                }
                if(strcmp(t[smallerX(i)][j], "\t") != 0){
                    points++;
                }
                if(strcmp(t[smallerX(i)][biggerY(j)], "\t") != 0){
                    points++;
                }
                if(strcmp(t[i][smallerY(j)], "\t") != 0){
                    points++;
                }
                if(strcmp(t[i][biggerY(j)], "\t") != 0){
                    points++;
                }
                if(strcmp(t[biggerX(i)][smallerY(j)], "\t") != 0){
                    points++;
                }
                if(strcmp(t[biggerX(i)][j], "\t") != 0){
                    points++;
                }
                if(strcmp(t[biggerX(i)][biggerY(j)], "\t") != 0){
                    points++;
                }
            }
        }
    }
    return points;
}




