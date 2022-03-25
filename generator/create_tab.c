/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCE-2-1-dante-alexandre-kevin.de-freitas-martins
** File description:
** create_tab
*/

#include "generator.h"

char **create_char_tab(int x, int y)
{
    char **array = malloc(sizeof(char *) * (y + 1));
    array[y] = NULL;
    for (int i = 0; i < y; i++) {
        array[i] = malloc(sizeof(char) * (x + 1));
        for (int j = 0; j < x; j++)
            array[i][j] = '*';
        array[i][x] = '\0';
    }
    return array;
}

int **create_int_tab(int x, int y, int nb)
{
    int **grid = malloc(sizeof(int *) * (y + 1));
    for (int i = 0; i < y; i++) {
        grid[i] = malloc(sizeof(int) * (x + 1));
        for (int j = 0; j < x; j++)
            grid[i][j] = nb;
    }
    return grid;
}

int *create_int_array(int size, int nb)
{
    int *grid = malloc(sizeof(int) * (size + 1));
    for (int i = 0; i < size; i++) {
        grid[i] = nb;
    }
    return grid;
}
