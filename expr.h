/*
** EPITECH PROJECT, 2020
** expr_node
** File description:
** Header
*/

#ifndef EXPR_H
#define EXPR_H

typedef struct expr_node {
    int result;
    int is_computed;
    struct expr_node *node1;
    struct expr_node *node2;
    int (*do_operation)(int number1, int number2);
} expr_node_t;

typedef struct operator_map {
    char key;
    int (*value)(int number1, int number2);
} operator_map_t;

expr_node_t *new_number_node(int number);

expr_node_t *new_expr_node(expr_node_t *node1, char op, expr_node_t *node2);

int compute(expr_node_t *node);

#endif