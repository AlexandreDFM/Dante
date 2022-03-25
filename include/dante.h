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
#include <pthread.h>

typedef struct vector_2i {
    int x;
    int y;
}vector_2i_t;

typedef struct dante {
    int length;
    int stackx;
    int stacky;
    int stackmax;
    int basewidth;
    int baseheight;
    int width;
    int height;
    int pile_size;
    vector_2i_t size;
    int **grid;
    int *pile;
    char **labyrinthe;
}dante_t;

char *my_itoa(int num);
char **create_char_tab(int x, int y);
int **create_int_tab(int x, int y, int nb);
int *create_int_array(int size, int nb);
int **exit_check(int **grid, int x, int y);
int **al_recusive_backtracking(dante_t *dante, int cx, int cy, int **grid);
