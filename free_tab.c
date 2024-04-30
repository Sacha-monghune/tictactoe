/*
** EPITECH PROJECT, 2024
** free_tab
** File description:
** free_tab
*/

#include "tictactoe.h"

void free_tab(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
