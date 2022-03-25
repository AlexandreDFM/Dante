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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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
    char **maze;
}dante_t;

char *my_itoa(int num);
void my_free_array(char **array);
char **create_char_tab(int x, int y);
int **create_int_tab(int x, int y, int nb);
int *create_int_array(int size, int nb);
int **exit_check(int **grid, int x, int y);
int **al_recusive_backtracking(dante_t *dante, int cx, int cy, int **grid);

