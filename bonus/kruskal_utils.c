/*
** EPITECH PROJECT, 2022
** kruskal
** File description:
** kruskal
*/

#include "generator.h"

int *resort_pile(dante_t *dante, int *pile, int indice)
{
    if (indice != 0) {
        pile[indice] = pile[dante->pile_size - 3];
        pile[indice + 1] = pile[dante->pile_size - 2];
        pile[dante->pile_size - 3] = 11;
        pile[dante->pile_size - 2] = 11;
        dante->pile_size -= 2;
    }
    return pile;
}

void my_print_int_tab(int **grid, int width, int height)
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%d,\t", grid[y][x]);
        }
        printf("\n");
    }
}
