/*
** EPITECH PROJECT, 2022
** recursive_bactracking
** File description:
** new_recur_backtracking
*/

#include "generator.h"

int **carve_passages_from(dante_t *dante, int cx, int cy, int **grid)
{
    int nx = 0, ny = 0, direction = 0;
    int directions[4] = {1, 2, 4 ,8};
    int save_dir[4] = {1, 2, 4 ,8};
    int oppposite[4] = {2, 1, 8, 4}; // to rand;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
    shuffle(directions, 4);
    for (int i = 0; i < 4; i++) {
        direction = directions[i];
        //printf("%d %d\n", direction, dy[get_index(save_dir, direction)]);
        nx = cx + dx[get_index(save_dir, direction)];
        ny = cy + dy[get_index(save_dir, direction)];
        // printf("%d\n", bewteen(0, dante->height, ny));
        if (bewteen(0, dante->height - 1, ny) == 1 && bewteen(0, dante->width - 1, nx) == 1 && grid[ny][nx] == 0) {
            //printf("ICI\n");
            // grid[cy][cx] = 1;
            // grid[ny][nx] = 2;
            grid[cy][cx] |= direction;
            //printf("Oppposite of %d is %d\n", direction, oppposite[get_index(save_dir, direction)]);
            grid[ny][nx] |= oppposite[get_index(save_dir, direction)];
            grid = carve_passages_from(dante, nx, ny, grid);
        }
    }
    return grid;
}
