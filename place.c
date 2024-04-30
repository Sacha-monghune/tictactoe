/*
** EPITECH PROJECT, 2024
** place
** File description:
** place
*/

#include "tictactoe.h"

int tab_len(char **tab)
{
    int len = 0;

    if (!tab)
        return -1;
    while (tab[len] != NULL) {
        len += 1;
    }
    return len;
}

bool is_valid_input(char **data, int *pos, map_t *map)
{
    if ((pos[0] == 0 && data[0][0] != '0') ||
        (pos[1] == 0 && data[1][0] != '0')) {
        printf("Mauvaise input veuiller recommencer\n");
        return false;
    }
    if ((pos[0] < 0) || (pos[1] < 0)) {
        printf("Mauvaise input veuiller recommencer\n");
        return false;
    }
    if (pos[0] > map->size_map || pos[1] > map->size_map) {
        printf("Mauvaise input veuiller recommencer là\n");
        return false;
    }
    if (map->mapp[pos[0] + 1][pos[1] + 1] != ' ') {
        printf("Mauvaise input veuiller recommencer ici\n");
        return false;
    }
    return true;
}

int *get_input(map_t *map, bool p1_turn)
{
    char **data = NULL;
    char *info = NULL;
    size_t len = 0;
    int *pos = malloc(sizeof(int) * 2);

    do {
        if (p1_turn)
            printf("Player 1> ");
        else
            printf("Player 2> ");
        getline(&info, &len, stdin);
        data = str_to_word_array(info, ",\n");
        if (!data[0] || !data[1]) {
            printf("Mauvaise input veuiller recommencer\n");
            continue;
        }
        pos[0] = atoi(data[0]);
        pos[1] = atoi(data[1]);
    } while (tab_len(data) != 2 || !is_valid_input(data, pos, map));
    return pos;
}

void place(map_t *map, bool *p1_turn)
{
    int *pos = NULL;

    if (*p1_turn) {
        pos = get_input(map, *p1_turn);
        map->mapp[pos[0] + 1][pos[1] + 1] = map->p1;
    } else {
        pos = get_input(map, *p1_turn);
        map->mapp[pos[0] + 1][pos[1] + 1] = map->p2;
    }
    print_map(map->mapp);
    free(pos);
}
