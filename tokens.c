/*
** EPITECH PROJECT, 2020
** tokens
** File description:
** Source code
*/

#include <stdlib.h>
#include <my.h>
#include "tokens.h"

const operator_token_t operators_tokens[] = {
    {'*', 2},
    {'/', 2},
    {'%', 2},
    {'+', 1},
    {'-', 1},
    {'\0', 0}
};

void consume_char(char **expr)
{
    *expr = *expr + 1;
}

int number(char **expr)
{
    char number[my_strlen(*expr) + 1];
    int i = 0;

    my_bzero(number, my_strlen(*expr) + 1);
    while ((**expr >= '0' && **expr <= '9') || (i == 0 && **expr == '-')) {
        number[i] = **expr;
        consume_char(expr);
        i++;
    }
    return (my_getnbr(number));
}

operator_token_t operator(char **expr)
{
    int i = 0;

    while (operators_tokens[i].symbol != '\0') {
        if (operators_tokens[i].symbol == **expr)
            break;
        i++;
    }
    consume_char(expr);
    return (operators_tokens[i]);
}