/*
** EPITECH PROJECT, 2021
** map.c
** File description:
** map
*/

#include "include/navy.h"

char **create_map(char *pos)
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
    place_navy(map, pos);
    return map;
}

void show_map(char **map)
{
    my_printf("%s", " |A B C D E F G H\n");
    my_printf("%s", "-+---------------\n");
    for (int y = 0; y < 8; y++) {
        my_printf("%d|%c", y + 1, map[y][0]);
        for (int x = 1; x < 8; x++) {
            my_printf(" %c", map[y][x]);
        }
        my_printf("\n");
    }
}

void place_navy(char **map, char *pos)
{
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        if (pos[2 + i * 8] == pos[5 + i * 8]) {
            place_navy_y(map, pos, i);
        } else if (pos[3 + i * 8] == pos[6 + i * 8]) {
            place_navy_x(map, pos, i);
        }
    }
}

void place_navy_x(char **map, char *pos, int i)
{
    int line = get_digits(pos[3 + i * 8]);
    int pos1 = 0;
    int pos2 = 0;
    if (pos[2 + i * 8] < pos[5 + i * 8]) {
        pos1 = convert_pos(pos[2 + i * 8]);
        pos2 = convert_pos(pos[5 + i * 8]);
    } else if (pos[2 + i * 8] > pos[5 + i * 8]) {
        pos1 = convert_pos(pos[5 + i * 8]);
        pos2 = convert_pos(pos[2 + i * 8]);
    }
    for (int j = pos1; j < pos2 + 1; j++) {
        map[line - 1][j] = i + 2 + '0';
    }
}

void place_navy_y(char **map, char *pos, int i)
{
    int col = convert_pos(pos[2 + i * 8]);
    int pos1 = 0;
    int pos2 = 0;
    if (pos[3 + i * 8] < pos[6 + i * 8]) {
        pos1 = get_digits(pos[3 + i * 8]);
        pos2 = get_digits(pos[6 + i * 8]);
    } else if (pos[3 + i * 8] > pos[6 + i * 8]) {
        pos1 = get_digits(pos[6 + i * 8]);
        pos2 = get_digits(pos[3 + i * 8]);
    }
    for (int j = pos1 - 1; j < pos2; j++) {
        map[j][col] = i + 2 + '0';
    }
}
