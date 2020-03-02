//  user.c
//  carcassonne game

#include "user.h"

void pick_tile(char **t){
    printf("Pick the tile: ");
    scanf("%s", *t);
    printf("");
}

void tile_on_board(char *t[][COLUMNS], set *p, char *tile, int x, int y){
    t[x][y] = tile;
    remove_used_tile(tile, p);
}

void pick_coordinates(int *x, int *y){
    printf("Pick coordinates: ");
    scanf("%d %d", x, y);
    printf("\n\n");
}

void user_rotate_tile(char *t){
    int r;
    printf("Rotate tile %s: ", t);
    scanf("%d", &r);
    rotate_tile(t, r);
    printf("Your tile: %s\n\n", t);
}

void instruction(){
    printf("There will be instruction\n\n");
}

void play_as_user(void){
    set s;
    set *p = &s;
    int i, first_size;
    int x = 0, y = 0;
    char *tile = malloc(TILE_LENGTH);
    char user_board[ROWS][COLUMNS][TILE_LENGTH];
    start_board(user_board);
    number_of_tiles("tiles.txt", p);
    first_size = p->size;
    printf("Welcome to the carcassonne game!\n\n");
    read_tiles("tiles.txt", p);
    for(i = 0; i < first_size; i += 2){
        print_tiles(p);
        pick_tile(&tile);
        while(tile_in_set(tile, p) < 0){
            printf("You must pick tile from the set!\n");
            pick_tile(&tile);
        }
        remove_used_tile(tile, p);
        user_rotate_tile(tile);
        pick_coordinates(&x, &y);
        while(can_place(x, y, user_board, tile) == 0){
            printf("You can't place the tile here!\n");
            pick_coordinates(&x, &y);
        }
        strcpy(user_board[x][y], tile);
        print_board(user_board);
    }
    board_to_file("user_board.txt", user_board);
}
