/*
** EPITECH PROJECT, 2021
** is_stacked.c
** File description:
** is_stacked
*/

#include "include/navy.h"

int is_stacked(char *pos)
{
    int **map = malloc(sizeof(int) * 8 * 8);
    for (int i = 0; i < 8; i++)
        map[i] = malloc(sizeof(int) * 8);
    fill_map(map);
    if (check_pos_navy(map, pos) == 84) {
        free(map);
        return 84;
    }
    for (int i = 0; i < 8; i++) {
        if (is_stacked2(map, i) == 84)
            return 84;
    }
    return 0;
}

int is_stacked2(int **map, int i)
{
    for (int j = 0; j < 8; j++) {
        if (map[i][j] > 1) {
            free(map);
            return 84;
        }
    }
    return 0;
}
