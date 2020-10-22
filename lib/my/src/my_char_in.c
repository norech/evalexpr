/*
** EPITECH PROJECT, 2020
** my_char_in
** File description:
** Search if a char is in a char list
*/
#include <my.h>

int my_char_in(char needle, char const *haystack)
{
    int i = 0;
    while (haystack[i] != '\0') {
        if (haystack[i] == needle)
            return (1);
    }

    return (0);
}
