/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Puts a number
*/
#include <my.h>

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    my_put_digit(nb % 10);

    return (0);
}
