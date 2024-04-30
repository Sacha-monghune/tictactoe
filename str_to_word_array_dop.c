/*
** EPITECH PROJECT, 2024
** str to word array
** File description:
** same shit                    //"-bonjour--moi-c'est-malo"
*/
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool is_del(char c, char *del)
{
    if (!del)
        return false;
    for (int i = 0; del[i]; i ++)
        if (c == del[i])
            return true;
    return false;
}

int word_counting(char *str, char *del)
{
    int len = 0;
    int i = 0;

    for (; is_del(str[i], del); i ++);
    while (str[i]){
        if (!is_del(str[i], del))
            len ++;
        for (; !is_del(str[i], del) && str[i]; i ++);
        for (; is_del(str[i], del) && str[i]; i ++);
    }
    return len;
}

int wrdlen(char *str, char *del, int nb)
{
    int wordlen = 0;
    int i = 0;

    for (; is_del(str[i], del); i ++);
    while (nb){
        for (; !is_del(str[i], del) && str[i]; i ++);
        for (; is_del(str[i], del) && str[i]; i ++);
        nb --;
    }
    for (; !is_del(str[i], del) && str[i]; i ++)
        wordlen++;
    return wordlen;
}

char *my_word_dup(char *str, char *del, int nb)
{
    int i = 0;
    int wlent = wrdlen(str, del, nb);
    char *copy = malloc(sizeof(char) * (wlent + 1));

    for (; is_del(str[i], del); i ++);
    while (nb){
        for (; !is_del(str[i], del); i ++);
        for (; is_del(str[i], del); i ++);
        nb --;
    }
    for (int j = 0; j < wlent; i ++){
        copy[j] = str[i];
        j++;
    }
    copy[wlent] = '\0';
    return copy;
}

char **str_to_word_array(char *str, char *del)
{
    int words = word_counting(str, del);
    char **res = malloc(sizeof(char *) * (words + 1));

    for (int i = 0; i < words; i ++)
        res[i] = my_word_dup(str, del, i);
    res[words] = NULL;
    return res;
}
