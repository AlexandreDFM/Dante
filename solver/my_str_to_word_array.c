/*
** EPITECH PROJECT, 2021
** str to word array
** File description:
** str to word array
*/

#include "solver.h"

int count_l(char *str, char delim)
{
    int counter = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delim || str[i] == '\n') counter++;
    }
    return (counter);
}

char **str_to_tok(char *str, const char *delim)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\t') str[i] = ' ';
    }
    int count = count_l(str, delim[0]) + 1;
    char **out = malloc(sizeof(char *) * (count + 1));
    int counter = 0;
    char *ptr = strtok(str, delim);
    while (ptr != NULL) {
        ptr[strlen(ptr)] = '\0';
        out[counter] = strdup(ptr);
        ptr = strtok(NULL, delim);
        counter++;
    }
    size_t len = strlen(out[counter - 1]);
    if (len > 1 && out[counter - 1][len - 1] == '\n') {
        out[counter - 1][--len] = '\0';
    }
    out[counter] = NULL;
    return out;
}
