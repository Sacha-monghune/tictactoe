/*
** EPITECH PROJECT, 2024
** fill_map
** File description:
** fill_map
*/

#include "tictactoe.h"

char **build_board(char **array, map_t *map)
{
    array[0][0] = '+';
    array[0][map->size_map + 1] = '+';
    for (int i = 0; i < map->size_map; i++) {
        for (int j = 0; j < map->size_map; j++)
            array[i + 1][j + 1] = ' ';
        array[0][i + 1] = '-';
        array[map->size_map + 1][i + 1] = '-';
        array[i + 1][map->size_map + 1] = '|';
        array[i + 1][0] = '|';
    }
    array[map->size_map + 1][0] = '+';
    array[map->size_map + 1][map->size_map + 1] = '+';
    return array;
}

map_t *fill_map(map_t *map)
{
    int i = 0;

    map->mapp = malloc(sizeof(char *) * (map->size_map + 3));
    while (i < map->size_map + 2) {
        map->mapp[i] = malloc(sizeof(char) * (map->size_map + 3));
        map->mapp[i][map->size_map + 2] = '\0';
        i++;
    }
    map->mapp[map->size_map + 2] = NULL;
    map->mapp = build_board(map->mapp, map);
    return map;
}
