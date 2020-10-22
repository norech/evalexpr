/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** Compare one string with another
*/
#include <my.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    while (s1[i] != '\0' && s1[i] == s2[i] && i < n) {
        i++;
    }

    return s1[i] - s2[i];
}
