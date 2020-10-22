/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** Check if string is lowercase
*/
#include <my.h>

static int is_char_uppercase(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_char_uppercase(str[i]))
            return (0);
        i++;
    }

    return (1);
}
