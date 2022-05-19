/*
** EPITECH PROJECT, 2021
** is_finish.c
** File description:
** is_finish
*/

#include "include/navy.h"

int is_finished(char *msg, char **map, char **enemy)
{
    while (my_strlen(g_var) < 7) { }
    msg[my_strlen(msg)] = bin_to_char(g_var);
    if (msg[0] == 'W') {
        print_both_map(map, enemy);
        my_printf("I won\n\n");
        return 1;
    }
    reset_str(msg, my_strlen(msg));
    return 0;
}

int is_navy(char **map)
{
    int count = 0;
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            count += is_navy2(map, x, y);
        }
    }
    if (count == 0)
        return 0;
    else
        return 1;
}

int is_navy2(char **map, int x, int y)
{
    if (map[y][x] >= '2' && map[y][x] <= '5')
        return 1;
    else
        return 0;
}
