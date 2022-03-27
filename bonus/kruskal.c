/*
** EPITECH PROJECT, 2022
** kruskal
** File description:
** kruskal
*/

#include "generator.h"

void create_kruskal(dante_t *dante, int x, int y)
{
    for (int i = 0; i < dante->height - 1; i++) {
        for (int j = 0; j < dante->width - 1; j++) {
            if (i % 2 == 1 && i != 0) {
                if (j % 2 == 1) {
                    dante->grid[i][j] = 0;
                }
            }
        }
    }
}

int is_finished(int **grid, int width, int height)
{
    int nb = grid[1][1];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (grid[y][x] == 1 || grid[y][x] == 0) continue;
            if (grid[y][x] != nb) return 1;
        }
    }
    return 0;
}

void fill_kruskal(dante_t *dante, int width, int height)
{
    int nb = 1;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (dante->grid[y][x] == 0) {
                nb++;
                dante->grid[y][x] = nb;
            }
        }
    }
}

void kruskal_algorithm(dante_t *dante, int width, int height)
{
    while (is_finished(dante->grid, width, height) && dante->pile_size >= 0) {
        int x = rand() % (width - 2) + 1;
        int y = 0;
        if (x % 2 == 0) {
            y = (rand() % ((height - 1) / 2)) * 2 + 1;
        } else {
            y = (rand() % ((height - 2) / 2)) * 2 + 2;
        }
        int cell_1 = 0;
        int cell_2 = 0;
        if (dante->grid[y - 1][x] == 1) {
            cell_1 = dante->grid[y][x - 1];
            cell_2 = dante->grid[y][x + 1];
        } else {
            cell_1 = dante->grid[y - 1][x];
            cell_2 = dante->grid[y + 1][x];
        }
        if (cell_1 != cell_2) {
            dante->grid[x][y] = 0;
            for (int i = 1; i < height - 1; i += 2) {
                for (int j = 1; j < width - 1; j += 2) {
                    if (dante->grid[i][j] == cell_2)
                        dante->grid[i][j] = cell_1;
                }
            }
        }
    }
}

void kruskal(dante_t *dante, int width, int height)
{
    create_kruskal(dante, width, height);
    fill_kruskal(dante, width, height);
    dante->grid[0][0] = 0;
    dante->grid[0][1] = 0;
    dante->grid[height - 1][width - 1] = 0;
    dante->grid[height - 1][width - 2] = 0;
    dante->grid[height - 1][width - 3] = 0;
    int size = ((width - 2) * (width - 2)) * 2;
    if (size <= 0) size = 1;
    dante->pile = create_int_array(size, width + 1);
    dante->pile = fill_possibility(dante->pile, width, height);
    int i = 0;
    for (; width + 1 != dante->pile[i] && i < size - 1; i++)
    dante->pile_size = i;
    kruskal_algorithm(dante, width, height);
    printf("\n");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (dante->grid[y][x] == 1) {
                printf("X");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}
