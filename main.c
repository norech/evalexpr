/*
** EPITECH PROJECT, 2020
** main
** File description:
** Evaluate expressions
*/

#include <my.h>
#include "eval_expr.h"

int main(int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}
