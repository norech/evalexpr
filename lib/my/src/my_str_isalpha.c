/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** Check if string is alphabetic
*/
#include <my.h>

static int is_char_alpha(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!is_char_alpha(str[i]))
            return (0);
        i++;
    }

    return (1);
}
