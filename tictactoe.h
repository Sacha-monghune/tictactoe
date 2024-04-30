/*
** EPITECH PROJECT, 2024
** tictactoe
** File description:
** tictactoe
*/

#ifndef _TICTACTOE_H_
    #define _TICTACTOE_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdbool.h>

typedef struct map_s {
    char p1;
    char p2;
    int size_map;
    char **mapp;
} map_t;

bool is_hwin(map_t *map, char p, int y);
bool is_vwin(map_t *map, char p, int x);
bool is_diagwin(map_t *map, char p);
bool is_win_case(map_t *map, char p);
bool is_tie(map_t *map);
char **str_to_word_array(char *str, char *del);
map_t *fill_map(map_t *map);
void free_tab(char **array);
void place(map_t *map, bool *p1_turn);
void print_map(char **map);
int help(void);
void game(map_t *map, bool p1_turn);
#endif /*_TICTACTOE_H_*/
