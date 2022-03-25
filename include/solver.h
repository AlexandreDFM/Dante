/*
** EPITECH PROJECT, 2021
** generator.h
** File description:
** Header of Dante
*/

#pragma once

#include "my.h"
#include "printf.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct solver {
    int width;
    int height;
    char **labyrinthe;
}solver_t;

int count_int_read(char *mappath);
char *open_file(char *mappath, int size_of_read);
char **my_strtwa(char const *str, char *limit);
void my_free_array(char **array);
