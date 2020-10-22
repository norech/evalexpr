/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** Check if string is alphabetic
*/
#include <my.h>

static int is_char_num(char c)
{
    return (c >= '0' && c <= '9');
}

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!is_char_num(str[i]))
            return (0);
        i++;
    }

    return (1);
}
