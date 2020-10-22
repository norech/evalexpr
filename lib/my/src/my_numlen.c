/*
** EPITECH PROJECT, 2020
** my_numlen
** File description:
** Get length of a number
*/
#include <my.h>

int my_numlen(int number)
{
    int length = 0;

    while (number >= 10) {
        length++;
        number /= 10;
    }
    return (length);
}
