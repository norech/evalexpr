/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** Check if string is lowercase
*/
#include <my.h>

static int is_char_lowercase(char c)
{
    return (c >= 'a' && c <= 'z');
}

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_char_lowercase(str[i]))
            return (0);
        i++;
    }

    return (1);
}
