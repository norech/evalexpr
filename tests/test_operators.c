/*
** EPITECH PROJECT, 2020
** test_operators
** File description:
** Test
*/
#include <criterion/criterion.h>
#include "../operators.h"

Test (my_add, add)
{
    cr_assert_eq(my_add(1, 1), 2);
}

Test (my_sub, sub)
{
    cr_assert_eq(my_sub(1, 1), 0);
}

Test (my_mul, mul)
{
    cr_assert_eq(my_mul(2, 2), 4);
}

Test (my_div, div)
{
    cr_assert_eq(my_div(2, 2), 1);
}

Test (my_mod, mod)
{
    cr_assert_eq(my_mod(7, 4), 3);
}