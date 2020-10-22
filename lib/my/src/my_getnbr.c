/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** Parses a number
*/
#include <my.h>

static int may_overflow_if_pushed(int number, int digit)
{
    return (number > 2147483647 - (number * 9 + digit));
}

static int process_digit(int *has_started_number, int *number, char c)
{
    if (c >= '0' && c <= '9') {
        if (may_overflow_if_pushed(*number, c - '0')) {
            *number = 0;
            return (1);
        }
        *number = *number * 10 + (c - '0');
        *has_started_number = 1;
    } else if (c != ' ' && c != '+' && c != '-') {
        return (1);
    }
    return (0);
}

int my_getnbr(char const *str)
{
    int number = 0;
    int multiplier = 1;
    int has_started_number = 0;
    int i = 0;
    while (str[i] != '\0') {
        char c = str[i];
        if (c == '-' && !has_started_number) {
            multiplier *= -1;
        }
        if (multiplier == -1 && number == 214748364 && c == '8') {
            number = 2147483648;
            break;
        }
        if (process_digit(&has_started_number, &number, c))
            break;
        i++;
    }
    return (multiplier * number);
}
