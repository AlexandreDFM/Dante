/*
** EPITECH PROJECT, 2022
** main
** File description:
** Main of solver of Dante
*/

#include "solver.h"

int alg_solver(solver_t *s, int pos_x, int pos_y)
{
    if (pos_x == -1 || pos_y == -1) return 0;
    if (pos_x == s->width + 1 || pos_y == s->height + 1) return 0;
    if (s->labyrinthe[pos_x][pos_y] == 'X' ||
    s->labyrinthe[pos_x][pos_y] == 'o') return 0;
    else if (s->labyrinthe[pos_x][pos_y] == 'E') return 1;
    else {
        s->labyrinthe[pos_x][pos_y] = 'o';
        if (alg_solver(s, pos_x + 1, pos_y) == 1)
            return 1;
        if (alg_solver(s, pos_x - 1, pos_y) == 1)
            return 1;
        if (alg_solver(s, pos_x, pos_y + 1) == 1)
            return 1;
        if (alg_solver(s, pos_x, pos_y - 1) == 1)
            return 1;
        s->labyrinthe[pos_x][pos_y] = '*';
        return 0;
    }
}

int solver(char *filepath)
{
    solver_t solver;
    solver.labyrinthe = my_strtwa(open_file(filepath,
    count_int_read(filepath)), "\n");
    int y = 0, x = 0;
    for (y = 0; solver.labyrinthe[y] != NULL; y++)
        for(; solver.labyrinthe[y][x] != '\0'; x++);
    solver.height = y - 1;
    solver.width = x;
    solver.labyrinthe[y - 2][x - 1] = 'E';
    if (!alg_solver(&solver, 0, 0)) return 0;
    solver.labyrinthe[y - 2][x - 1] = 'o';
    for (y = 0; solver.labyrinthe[y] != NULL; y++) {
        printf(solver.labyrinthe[y]);
        if (y < solver.height - 1) printf("\n");
    }
    return 1;
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        solver(argv[1]);
        return 1;
    }
    return 84;
}
