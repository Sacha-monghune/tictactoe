/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include "tictactoe.h"

bool is_hwin(map_t *map, char p, int y)
{
    int nb = 0;

    for (int i = 1; i <= map->size_map; i ++)
        if (map->mapp[y][i] == p)
            nb ++;
    if (nb == map->size_map) {
        if (p == map->p1)
            printf("P1 win!\n");
        else
            printf("P2 win!\n");
        return true;
    }
    return false;
}

bool is_vwin(map_t *map, char p, int x)
{
    int nb = 0;

    for (int i = 1; i <= map->size_map && map->mapp[x][i]; i ++)
        if (map->mapp[i][x] == p)
            nb ++;
    if (nb == map->size_map) {
        p = map->p1 ? printf("P1 win!\n") : printf("P2 win!\n");
        return true;
    }
    return false;
}

bool is_diagwin(map_t *map, char p)
{
    int nb = 0;
    int j = 1;

    for (int i = 1; i <= map->size_map && map->mapp[i][i]; i ++)
        if (map->mapp[i][i] == p)
            nb ++;
    if (nb == map->size_map) {
        p = map->p1 ? printf("P1 win!\n") : printf("P2 win!\n");
        return true;
    }
    nb = 0;
    for (int i = map->size_map; i >= 1 && map->mapp[j][i]; i --, j ++)
        if (map->mapp[j][i] == p)
            nb ++;
    if (nb == map->size_map) {
        p = map->p1 ? printf("P1 win!\n") : printf("P2 win!\n");
        return true;
    }
    return false;
}

bool is_win_case(map_t *map, char p)
{
    for (int y = 1; y <= map->size_map && map->mapp[y]; y ++)
        if (is_hwin(map, p, y))
            return true;
    for (int y = 1; y <= map->size_map && map->mapp[y]; y ++)
        if (is_vwin(map, p, y))
            return true;
    if (is_diagwin(map, p))
        return true;
    return false;
}

bool is_tie(map_t *map)
{
    int space = 0;

    for (int i = 0; map->mapp[i]; i ++)
        for (int j = 0; map->mapp[i][j]; j ++)
            space = (map->mapp[i][j] == ' ') ? space + 1 : space;
    if (space == 0) {
        printf("Égalité!\n");
        return true;
    }
    return false;
}
