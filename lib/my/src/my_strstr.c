/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** Search a string in another
*/
#include <my.h>

char *my_strstr(char *str, char const *to_find)
{
    if (str[0] == '\0' && to_find[0] == '\0') {
        return (&str[0]);
    }

    int i = 0;
    while (str[i] != '\0') {
        int j = 0;
        int is_end = (to_find[j] == '\0' || str[i + j] == '\0');
        while (!is_end && str[i + j] == to_find[j]) {
            j++;
        }
        if (to_find[j] == '\0')
            return (&str[i]);
        i++;
    }
    return ((void *)0);
}
