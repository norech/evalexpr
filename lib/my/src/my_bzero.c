/*
** EPITECH PROJECT, 2020
** my_bzero
** File description:
** Set bytes to zero in a char
*/

void my_bzero(char *res, int size)
{
    int i = 0;
    while (i < size) {
        res[i] = '\0';
        i++;
    }
}