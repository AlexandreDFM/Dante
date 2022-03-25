/*
** EPITECH PROJECT, 2022
** my_free_array
** File description:
** Free double array function
*/

#include "solver.h"

void my_free_array(char **array)
{
    for (int i = 0; array[i]; i++) {
        free(array[i]);
        array[i] = NULL;
    }
    free(array);
    array = NULL;
}
