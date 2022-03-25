/*
** EPITECH PROJECT, 2022
** recursive_backtracking
** File description:
** recursive_backtracking
*/

#include "generator.h"

void shuffle(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

int get_index(int *array, int nb)
{
    int i = 0;
    for (; array[i] != nb; i++);
    return i;
}

int bewteen(int low, int up, int nb)
{
    return (nb >= low && nb <= up) ? 1 : 0;
}

int **exit_check(int **grid, int x, int y)
{
    grid[y - 1][x - 1] = 0;
    grid[y - 1][x - 2] = 0;
    return grid;
}

int **al_recusive_backtracking(dante_t *dante, int cx, int cy, int **grid)
{
    grid[cy][cx] = 0;
    int nx = 0, ny = 0, ly = 0, lx = 0, direction = 0;
    int directions[4] = {1, 2, 4, 8}, save_dir[4] = {1, 2, 4 , 8};
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
    shuffle(directions, 4);
    for (int i = 0; i < 4; i++) {
        direction = directions[i];
        nx = cx + dx[get_index(save_dir, direction)] * 2;
        ny = cy + dy[get_index(save_dir, direction)] * 2;
        if (bewteen(0, dante->height - 1, ny) == 1 &&
        bewteen(0, dante->width - 1, nx) == 1 && grid[ny][nx] == 1) {
            lx = cx + dx[get_index(save_dir, direction)];
            ly = cy + dy[get_index(save_dir, direction)];
            grid[ly][lx] = 0;
            grid = al_recusive_backtracking(dante, nx, ny, grid);
        }
    }
    return grid;
}
