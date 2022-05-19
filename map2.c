/*
** EPITECH PROJECT, 2021
** map2.c
** File description:
** mao2
*/

#include "include/navy.h"

char **create_map_empty(void)
{
    char **map = malloc(sizeof(char) * 8 * 9);
    for (int i = 0; i < 8; i++)
        map[i] = malloc(sizeof(char) * 9);
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            map[y][x] = '.';
        }
        map[y][8] = '\0';
    }
    return map;
}

void print_both_map(char **map, char **enemy)
{
    my_printf("my positions:\n");
    show_map(map);
    my_printf("\n");
    my_printf("enemy's positions:\n");
    show_map(enemy);
    my_printf("\n");
}
