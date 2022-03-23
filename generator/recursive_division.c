/*
** EPITECH PROJECT, 2022
** recursive_division
** File description:
** recursive_division
*/

#include "dante.h"

void make_maze(dante_t *dante)
{
    int bottom = 0, south = 0, south2 = 0, east = 0;
    dante->labyrinthe[0][0] = '*';
    for (int x = 0; x < dante->basewidth; x++)
        dante->labyrinthe[0][x] = 'X';
    for (int y = 1; y < dante->baseheight; y++) {
        dante->labyrinthe[y][0] = 'X';
        for (int x = 1; x < dante->width; x++) {
            bottom = (y + 1) >= dante->baseheight ? 1 : 0;
            south = ((dante->grid[y][x] & 1) != 0 || bottom) ? 1 : 0;
            south2 = ((x + 1 < dante->baseheight &&
            (dante->grid[y][x + 1] & 1)) != 0 || bottom);
            east = ((dante->grid[y][x] & 2) != 0 || x + 1 >=
            dante->baseheight);
            dante->labyrinthe[y][x] = (south ? 'X' : '*');
            dante->labyrinthe[y][x] = east ? 'X' :
            ((south && south2) ? 'X' : '*');
        }
    }
}

int choose_orientation(int width, int height)
{
    if (width < height) {
        return 1;
    } else if (height < width) {
        return 2;
    } else {
        int tmp = rand() % 2 == 0 ? 1 : 2;
        return tmp;
    }
}

void recursive_division(dante_t *dante, int x, int y, int wi, int he, int ori)
{
    if (wi <= 2 || he <= 2) return;
    make_maze(dante);
    int horizontal = (ori == 1 ? 1 : 0);
    int wx = x + (horizontal ? 0 : rand() % (wi - 2));
    int wy = y + (horizontal ? rand() % (he - 2) : 0);
    int px = wx + (horizontal ? rand() % wi : 0);
    int py = wy + (horizontal ? 0 : rand() % he);
    int dx = horizontal ? 1 : 0, dy = horizontal ? 0 : 1;
    int length = horizontal ? wi : he, dir = horizontal ? 1 : 2;
    for (int i = 0; i < length; i++) {
        if (wx != px || wy != py) dante->grid[wy][wx] |= dir;
        wx += dx, wy += dy;
    }
    int nx = x, ny = y;
    int w = horizontal ? wi : wx - x + 1, h = horizontal ? wy - y + 1 : he;
    recursive_division(dante, nx, ny, w, h, choose_orientation(w, h));
    nx = horizontal ? x : wx + 1, ny = horizontal ? wy + 1 : y;
    w = horizontal ? wi : x + wi - wx - 1;
    h = horizontal ? y + he - wy - 1 : he;
    recursive_division(dante, nx, ny, w, h, choose_orientation(w, h));
}
