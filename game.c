/*
** EPITECH PROJECT, 2024
** tictactoe
** File description:
** game
*/

#include "tictactoe.h"

void game(map_t *map, bool p1_turn)
{
    while (!is_win_case(map, map->p1) &&
        !is_win_case(map, map->p2) && !is_tie(map)) {
        place(map, &p1_turn);
        p1_turn = (p1_turn) ? false : true;
    }
}
