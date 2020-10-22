/*
** EPITECH PROJECT, 2020
** expr_utils
** File description:
** Source code
*/
#include <stdlib.h>
#include <stdio.h>
#include <my.h>
#include "expr.h"
#include "operators.h"

const operator_map_t operators_expr[] = {
    {'+', &my_add},
    {'-', &my_sub},
    {'*', &my_mul},
    {'/', &my_div},
    {'%', &my_mod},
    {'\0', NULL}
};

expr_node_t *new_number_node(int number)
{
    expr_node_t *current = NULL;
    current = malloc(sizeof(expr_node_t));
    current->is_computed = 1;
    current->result = number;
    current->node1 = NULL;
    current->node2 = NULL;
    current->do_operation = NULL;

    return (current);
}

expr_node_t *new_expr_node(expr_node_t *node1, char op, expr_node_t *node2)
{
    expr_node_t *current = NULL;
    current = malloc(sizeof(expr_node_t));
    int i = 0;

    current->is_computed = 0;
    current->result = 0;
    current->node1 = node1;
    current->node2 = node2;
    while (operators_expr[i].key != '\0') {
        if (operators_expr[i].key == op) {
            current->do_operation = operators_expr[i].value;
            break;
        }
        i++;
    }

    return (current);
}

int compute(expr_node_t *node)
{
    int result = 0;

    if (!node->is_computed) {
        if (node->node1 == NULL || node->node2 == NULL)
            return (0);
        if (!node->node1->is_computed)
            compute(node->node1);
        if (!node->node2->is_computed)
            compute(node->node2);
        result = node->do_operation(node->node1->result, node->node2->result);
        node->result = result;
        node->is_computed = 1;
    }
    return (node->result);
}

void free_expr(expr_node_t *node)
{
    if (node->node1 != NULL) {
        free_expr(node->node1);
        node->node1 = NULL;
    }
    if (node->node2 != NULL) {
        free_expr(node->node2);
        node->node2 = NULL;
    }
    free(node);
}