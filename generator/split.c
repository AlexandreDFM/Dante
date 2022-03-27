/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCE-2-1-dante-alexandre-kevin.de-freitas-martins
** File description:
** split
*/

#include "generator.h"

void split_maze(dante_t *dante)
{
    for (int i = dante->height / 2; i < dante->height; i++) {
        dante->grid[i][dante->width / 2] = 1;
    }
}
