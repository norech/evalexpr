/*
** EPITECH PROJECT, 2020
** my_strsplit
** File description:
** Splits str to word array
*/

#include <my.h>
#include <stdlib.h>

static int fill_words_lengths(char const *str,
int *lengths_ptr, char separator)
{
    int all_length = 0;
    int j = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (i != 0 && str[i - 1] != separator && str[i] == separator)
            j++;
        if (str[i] != separator)
            lengths_ptr[j]++;
        i++;
    }
    i = 0;
    while (lengths_ptr[i] != '\0') {
        all_length += lengths_ptr[i] + 1;
        i++;
    }
    return (all_length);
}

static void fill_words(char **words, char const *str,
int const *lengths, char separator)
{
    int i = 0;
    int j = 0;
    int word_pos = 0;

    while (str[i] != '\0') {
        if (i == 0 || (str[i - 1] == separator && str[i] != separator)) {
            words[j] = malloc(sizeof(char) * (lengths[j] + 1));
            word_pos = 0;
        }
        if (i != 0 && str[i - 1] != separator && str[i] == separator) {
            words[j][word_pos] = '\0';
            j++;
        } else {
            words[j][word_pos] = str[i];
            word_pos++;
        }
        i++;
    }
}

static int count_words(char const *str, char separator)
{
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (i == 0 || (str[i - 1] == separator && str[i] != separator))
            count++;
        i++;
    }

    return (count);
}

char **my_strsplit(char const *str, char separator)
{
    int words_count = count_words(str, separator);
    int *lengths = malloc(sizeof(int) * words_count);
    int cumulated_length = fill_words_lengths(str, lengths, separator);
    char **words = malloc(sizeof(char*) * cumulated_length);
    fill_words(words, str, lengths, separator);
    return (words);
}
