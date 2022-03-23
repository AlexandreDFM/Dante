/*
** EPITECH PROJECT, 2022
** main
** File description:
** Main of generator of Dante
*/

#include "dante.h"

void create_arrays(dante_t *dante, int x, int y)
{
    char **array = malloc(sizeof(char *) * (y + 1));
    array[y] = NULL;
    for (int i = 0; i < y; i++) {
        array[i] = malloc(sizeof(char) * (x + 1));
        for (int j = 0; j < x; j++)
            array[i][j] = '*';
        array[i][x] = '\0';
    }
    dante->labyrinthe = array;
    int **grid = malloc(sizeof(int *) * (y + 1));
    for (int i = 0; i < y; i++) {
        grid[i] = malloc(sizeof(int) * (x + 1));
        for (int j = 0; j < x; j++)
            grid[i][j] = 0;
    }
    dante->grid = grid;
}

void entry_exit_points(dante_t *dante)
{
    dante->labyrinthe[0][0] = '*';
    dante->labyrinthe[0][1] = '*';
    dante->labyrinthe[1][1] = '*';
    dante->labyrinthe[0][0] = '*';
    dante->labyrinthe[dante->height - 1][dante->width - 1] = '*';
    dante->labyrinthe[dante->height - 2][dante->width - 1] = '*';
    dante->labyrinthe[dante->height - 2][dante->width - 2] = '*';
}

void create_recursive_division(int x, int y)
{
    if (x <= 2 || y <= 2) exit(84);
    dante_t dante;
    dante.basewidth = x;
    dante.baseheight = y;
    dante.width = x;
    dante.height = y;
    create_arrays(&dante, x, y);
    recursive_division(&dante, 0, 0, x, y, choose_orientation(x, y));
    make_maze(&dante);
    entry_exit_points(&dante);
    for (int i = 0; dante.labyrinthe[i] != NULL; i++)
        printf("%s\n", dante.labyrinthe[i]);
}

int main(int argc, char **argv)
{
    if (argc == 3) {
        srand(time(0));
        if (strlen(argv[1]) != strlen(my_itoa(atoi(argv[1])))) return 84;
        if (strlen(argv[2]) != strlen(my_itoa(atoi(argv[2])))) return 84;
        create_recursive_division(atoi(argv[1]), atoi(argv[2]));
        return 1;
    } else if (argc == 4) {
        return 0;
    }
    return 0;
}
