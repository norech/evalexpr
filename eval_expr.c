/*
** EPITECH PROJECT, 2020
** eval_expr
** File description:
** Evaluate expressions
*/
#include <defmy.h>
#include "parser.h"
#include "expr.h"

int eval_expr(char const *str)
{
    char *expr = (char *)str;
    expr_node_t *node = make_tree(&expr, 1);
    int res = compute(node);
    free_expr(node);
    return (res);
}