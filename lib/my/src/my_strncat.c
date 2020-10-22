/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** Append a string to another
*/
#include <my.h>

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0' && i < nb) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';

    return (dest);
}
