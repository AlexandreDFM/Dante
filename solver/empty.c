/*
** EPITECH PROJECT, 2022
** empty
** File description:
** empty
*/

#include "solver.h"

int check_empty(solver_t *solver, int width, int height)
{
    int presence = 1;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            presence = (solver->maze[y][x] == 'X' ? 0 : presence);
        }
    }
    return presence;
}

void make_empty(solver_t *solver, int width, int height)
{
    for (int y = 0; y < height; y++) {
        solver->maze[y][0] = 'o';
    }
    for (int x = 0; x < width; x++) {
        solver->maze[height][x] = 'o';
    }
}

int empty(solver_t *solver, int width, int height)
{
    if (check_empty(solver, width, height)) {
        make_empty(solver, width + 1, height + 1);
        my_print_map(solver, solver->maze);
        my_free_array(solver->maze);
        return 1;
    } else {
        return 0;
    }
}
