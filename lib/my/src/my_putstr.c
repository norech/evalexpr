/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Puts a string
*/
#include <my.h>

int my_putstr(char const *str)
{
    char *chr = (char *) str;
    while (*chr != '\0') {
        my_putchar(*chr);
        chr++;
    }

    return (0);
}
