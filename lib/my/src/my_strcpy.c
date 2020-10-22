/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** Copy one string to another
*/
#include <my.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
