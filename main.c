/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "tictactoe.h"

map_t *fill_struct(char **av)
{
    map_t *map = malloc(sizeof(map_t));

    map->p1 = 'X';
    map->p2 = 'O';
    map->size_map = 3;
    for (int i = 0; av[i] != NULL; i++) {
        if (strcmp(av[i], "-p1") == 0)
            map->p1 = av[i + 1][0];
        if (strcmp(av[i], "-p2") == 0)
            map->p2 = av[i + 1][0];
        if (strcmp(av[i], "-s") == 0)
            map->size_map = atoi(av[i + 1]);
    }
    return map;
}

int check_arg(char **av)
{
    for (int i = 0; av[i] != NULL; i++) {
        if (strcmp(av[i], "-p1") == 0 && av[i + 1] && strlen(av[i + 1]) != 1)
            return -1;
        if (strcmp(av[i], "-p2") == 0 && av[i + 1] && strlen(av[i + 1]) != 1)
            return -1;
        if (strcmp(av[i], "-s") == 0 && av[i + 1] && atoi(av[i + 1]) <= 0)
            return -1;
    }
    return 0;
}

void print_map(char **map)
{
    for (int i = 0; map[i]; i++)
        printf("%s\n", map[i]);
}

int main(int ac, char **av)
{
    map_t *map = NULL;
    bool p1_turn = true;

    if (ac == 2 && strcmp(av[1], "-h") == 0)
        return help();
    if ((ac != 1 && ac != 3 && ac != 5 && ac != 7) || (check_arg(av) == -1))
        return 84;
    map = fill_struct(av);
    fill_map(map);
    if (map->p1 == map->p2) {
        printf("Les joueurs ne peuvent pas jouer la même lettre\n");
        return 84;
    }
    print_map(map->mapp);
    game(map, p1_turn);
    free_tab(map->mapp);
    free(map);
    return 0;
}
