/*
** EPITECH PROJECT, 2021
** dante.h
** File description:
** Header of Dante
*/

#pragma once

#include "my.h"
#include "printf.h"
#include "unistd.h"
#include "math.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct dante {
    int length;
    int basewidth;
    int baseheight;
    int width;
    int height;
    int **grid;
    char **labyrinthe;
}dante_t;

char *my_itoa(int num);
void recursive_division(dante_t *dante, int x, int y, int width, int height, int orientation);
int choose_orientation(int width, int height);
void make_maze(dante_t *dante);
