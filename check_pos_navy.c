/*
** EPITECH PROJECT, 2021
** check_pos_navy.c
** File description:
** check_pos_navy
*/

#include "include/navy.h"

int check_pos_navy(int **map, char *pos)
{
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        if (pos[2 + i * 8] == pos[5 + i * 8]) {
            ret += check_pos_navy_y(map, pos, i);
        } else if (pos[3 + i * 8] == pos[6 + i * 8]) {
            ret += check_pos_navy_x(map, pos, i);
        }
    }
    if (ret > 0)
        return 84;
    return 0;
}

int check_pos_navy_x(int **map, char *pos, int i)
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
        if (j >= 8)
            return 84;
        map[line - 1][j]++;
    }
    return 0;
}

int check_pos_navy_y(int **map, char *pos, int i)
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
        if (j >= 8)
            return 84;
        map[j][col]++;
    }
    return 0;
}

int check_navy(char *pos)
{
    if (pos[0] != '2' || pos[8] != '3' || pos[16] != '4' || pos[24] != '5')
        return 84;
    for (int i = 0; i < 4; i++) {
        if (!(pos[2 + i * 8] == pos[5 + i * 8] ||
        pos[3 + i * 8] == pos[6 + i * 8]))
            return 84;
        if (pos[2 + i * 8] == pos[5 + i * 8] &&
        pos[3 + i * 8] == pos[6 + i * 8])
            return 84;
    }
    if (check_size(pos) == 84 || is_stacked(pos) == 84)
        return 84;
    return 0;
}
