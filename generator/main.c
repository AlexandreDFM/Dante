/*
** EPITECH PROJECT, 2022
** main
** File description:
** Main of generator of Dante
*/

#include "generator.h"

int is_finished_2(int **grid, int width, int height)
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (grid[y][x] == 1 || grid[y][x] == 2) continue;
            else return 1;
        }
    }
    return 0;
}

int count_x(int **grid, int x, int y)
{
    int counter1 = 0;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            counter1 += (grid[i][j]) ? 1 : 0;
        }
    }
    return counter1;
}

int count_s(int **grid, int x, int y)
{
    int counter2 = 0;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            counter2 += (!grid[i][j]) ? 1 : 0;
        }
    }
    return counter2;
}

void create_recusive_backtracking(int x, int y)
{
    if (x <= 2 || y <= 2) exit(84);
    dante_t dante;
    dante.width = x;
    dante.height = y;
    dante.grid = create_int_tab(x, y, 1);
    dante.stackx = 0;
    dante.stacky = 0;
    dante.stackmax = 0;
    dante.grid = al_recusive_backtracking(&dante,
    dante.stackx, dante.stacky, dante.grid);
    dante.stackmax = 0;
    dante.grid = exit_check(dante.grid, x, y);
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++)
            printf("%c", (dante.grid[i][j]) ? 'X' : '*');
        if (i < y - 1) printf("\n");
    }
    for (int i = 0; i < y; i++)
        free(dante.grid[i]);
    free(dante.grid);
}

int main(int argc, char **argv)
{
    if (argc == 3) {
        srand(time(0));
        char *number1 = my_itoa(atoi(argv[1]));
        char *number2 = my_itoa(atoi(argv[2]));
        if (strlen(argv[1]) != strlen(number1)) {
            free(number1);
            return 84;
        }
        if (strlen(argv[2]) != strlen(number2)) {
            free(number2);
            return 84;
        }
        free(number1);
        free(number2);
        create_recusive_backtracking(atoi(argv[1]), atoi(argv[2]));
        return 1;
    } else if (argc == 4) {
        return 0;
    }
    return 0;
}
