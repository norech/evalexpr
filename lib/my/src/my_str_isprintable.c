/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** Check if string is printable
*/
#include <my.h>

static int is_char_printable(char c)
{
    return (c >= 31 && c < 127);
}

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!is_char_printable(str[i]))
            return (0);
        i++;
    }

    return (1);
}
