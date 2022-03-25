/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCE-2-1-dante-alexandre-kevin.de-freitas-martins
** File description:
** pile
*/

#include "generator.h"

int *add_pile(int *pile, int x, int y, int size)
{
    for (int i = 0; i < size - 1; i++) {
        if (pile[i] == (size + 1)) {
            pile[i] = x;
            pile[i + 1] = y;
            return pile;
        }
    }
    return pile;
}

int check_in_pile(int *pile, int nb1, int nb2, int size)
{
    for (int x = 0; x < size - 1; x++) {
        if (pile[x] == nb1 && pile[x + 1] == nb2) return 1;
    }
    return 0;
}
