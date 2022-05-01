/*
** EPITECH PROJECT, 2022
** main
** File description:
** Main of generator of Dante
*/

#include "generator.h"
#include "time.h"

void carve_imperfect(dante_t *dante)
{
    int random = rand() % 2;
    for (int i = 0; i < dante->height; i++) {
        for (int j = 0; j < dante->width; j++) {
            dante->grid[i][j] = (dante->grid[i][j] == 1 && random == 0)
            ? 1 : 0;
            random = rand() % 2;
        }
    }
    split_maze(dante);
}

void make_imperfect(int x, int y)
{
    if (x <= 2 || y <= 2) exit(84);
    dante_t dante;
    dante.width = x;
    dante.height = y;
    dante.grid = create_int_tab(x, y, 1);
    dante.stackx = 0, dante.stacky = 0, dante.stackmax = 0;
    dante.grid = al_recusive_backtracking(&dante,
    dante.stackx, dante.stacky, dante.grid);
    dante.stackmax = 0;
    dante.grid = exit_check(dante.grid, x, y);
    carve_imperfect(&dante);
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%c", (dante.grid[i][j]) ? 'X' : '*');
        }
        if (i < y - 1) printf("\n");
    }
    for (int i = 0; i < y; i++) free(dante.grid[i]);
    free(dante.grid);
}

void make_perfect(int x, int y)
{
    if (x <= 2 || y <= 2) exit(84);
    dante_t dante;
    dante.width = x;
    dante.height = y;
    dante.grid = create_int_tab(x, y, 1);
    dante.stackx = 0, dante.stacky = 0, dante.stackmax = 0;
    dante.grid = al_recusive_backtracking(&dante,
    dante.stackx, dante.stacky, dante.grid);
    dante.stackmax = 0;
    dante.grid = exit_check(dante.grid, x, y);
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++)
            printf("%c", (dante.grid[i][j]) ? 'X' : '*');
        if (i < y - 1) printf("\n");
    }
    for (int i = 0; i < y; i++) free(dante.grid[i]);
    free(dante.grid);
}

int choose_maze_format(char *x, char *y, char *format)
{
    char *number1 = my_itoa(atoi(x));
    char *number2 = my_itoa(atoi(y));
    if (strlen(x) != strlen(number1)) {
        free(number1);
        return 84;
    }
    if (strlen(y) != strlen(number2)) {
        free(number2);
        return 84;
    }
    free(number1);
    free(number2);
    if (!(strcmp("perfect", format))) {
        make_perfect(atoi(x), atoi(y));
        return 0;
    } else {
        return 84;
    }
    return 0;
}

int main(int argc, char **argv)
{
    srand(time(0));
    if (argc == 3) {
        char *number1 = my_itoa(atoi(argv[1]));
        char *number2 = my_itoa(atoi(argv[2]));
        if (strlen(argv[1]) != strlen(number1)) {
            free(number1); return 84;
        }
        if (strlen(argv[2]) != strlen(number2)) {
            free(number2); return 84;
        }
        free(number1); free(number2);
        make_imperfect(atoi(argv[1]), atoi(argv[2]));
        return 0;
    }
    if (argc == 4 && choose_maze_format(argv[1], argv[2], argv[3]) == 84)
        return 84;
    return 0;
}
