/*
** EPITECH PROJECT, 2022
** main
** File description:
** Main of solver of Dante
*/

#include "solver.h"

int alg_solver(solver_t *s, int pos_x, int pos_y)
{
    if (pos_x <= -1 || pos_y <= -1) return 0;
    if (pos_x >= s->width || pos_y >= s->height + 1) return 0;
    if (s->maze[pos_x][pos_y] == 'X' ||
    s->maze[pos_x][pos_y] == 'o') return 0;
    else if (s->maze[pos_x][pos_y] == 'E') return 1;
    else {
        s->maze[pos_x][pos_y] = 'o';
        if (alg_solver(s, pos_x + 1, pos_y) == 1)
            return 1;
        if (alg_solver(s, pos_x - 1, pos_y) == 1)
            return 1;
        if (alg_solver(s, pos_x, pos_y + 1) == 1)
            return 1;
        if (alg_solver(s, pos_x, pos_y - 1) == 1)
            return 1;
        s->maze[pos_x][pos_y] = '*';
        return 0;
    }
}

void my_print_map(solver_t *solver, char **map)
{
    for (int y = 0; y < solver->height; y++) {
        for (int x = 0; x <= solver->width; x++)
            printf("%c", map[y][x]);
        if (y < solver->height - 1) printf("\n");
    }
}

int check_map(char *map)
{
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '*' || map[i] == 'X' || map[i] == '\n') {
            continue;
        } else {
            return 84;
        }
    }
    return 0;
}

int solver(char *filepath)
{
    solver_t solver;
    char *map = open_file(filepath, count_int_read(filepath));
    if (count_int_read(filepath) <= 1) return 84;
    if (check_map(map) == 84) return 84;
    solver.maze = str_to_tok(map, "\n");
    free(map);
    for (solver.height = 0; solver.maze[solver.height];solver.height++);
    solver.width = strlen(solver.maze[0]);
    solver.height -= 1, solver.width -= 1;
    solver.maze[solver.height - 1][solver.width] = 'E';
    if (!alg_solver(&solver, 0, 0)) {
        printf("no solution found");
        return 0;
    }
    solver.maze[solver.height - 1][solver.width] = 'o';
    my_print_map(&solver, solver.maze);
    my_free_array(solver.maze);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        if (solver(argv[1]) == 84) return 84;
        else return 0;
    }
    return 84;
}
