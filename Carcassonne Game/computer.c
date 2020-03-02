//  computer.c
//  carcassonne game

#include "computer.h"

void picking_the_tile(char **t, set *p){
    int i, points, max = 0;
    for(i = 0; i < p->size; i++){
        points = points_for_tile(*(p->tiles + i));
        if(points > max){
            max = points;
            *t = *(p->tiles + i);
        }
    }
}

void rotating_the_tile(char *t){
    srand((unsigned int)time(NULL));
    int i;
    i = rand() % 4;
    rotate_tile(t, i);
}

void placing_on_board(char t[][COLUMNS][TILE_LENGTH], set *p, char *tile){
    int i, j, points, maxX = 0, maxY = 0, max = 0;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            if(empty_field(t, i, j) == 1){
                if(can_place(i, j, t, tile) == 1){
                    strcpy(t[i][j], tile);
                    points = count_points(t);
                    if(points > max){
                        max = points;
                        maxX = i;
                        maxY = j;
                    }
                    strcpy(t[i][j], "\t");
                }
            }
        }
    }
    strcpy(t[maxX][maxY], tile);
}

void play_computer(void){
    set s;
    set *p = &s;
    int i, first_size;
    char *tile = malloc(TILE_LENGTH);
    char computer_board[ROWS][COLUMNS][TILE_LENGTH];
    start_board(computer_board);
    number_of_tiles("starting_tiles.txt", p);
    first_size = p->size;
    read_tiles("starting_tiles.txt", p);
    printf("Used tiles: \n");
    for(i = 0; i < first_size; i++){
        picking_the_tile(&tile, p);
        remove_used_tile(tile, p);
        printf("%s\n", tile);
        placing_on_board(computer_board, p, tile);
    }
    printf("Computer board: \n\n");
    print_board(computer_board);
    printf("\n\n");
    board_to_file("computer_board.txt", computer_board);
}
