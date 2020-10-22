/*
** EPITECH PROJECT, 2020
** my_put_float
** File description:
** Print a floatting number
*/
#include <my.h>

int my_put_float(float nb, int digits)
{
    int power = my_compute_power_rec(10, digits);
    int decimals = (int)((nb - (int)nb) * power);
    int zeros_count = digits - my_numlen(decimals) - 1;
    int i = 0;
    my_put_nbr((int) nb);
    my_putchar('.');
    while (i < zeros_count) {
        my_put_digit(0);
        i++;
    }
    my_put_nbr(decimals);

    return (0);
}
