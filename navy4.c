/*
** EPITECH PROJECT, 2022
** navy4.c
** File description:
** navy4
*/

#include "include/navy.h"

void free_all(char **map, char **enemy, char *msg)
{
    for (int i = 0; i < 8; i++) {
        free(map[i]);
        free(enemy[i]);
    }
    free(map);
    free(enemy);
    free(msg);
    free(g_var);
}

int player_2_game_2(char **map, char **enemy, int pid, char *msg)
{
    int ret = 0;
    reset_str(g_var, my_strlen(g_var));
    reset_str(msg, my_strlen(msg));
    send_char('N', pid);
    usleep(2000);
    attack(enemy, pid, msg);
    ret = is_finished(msg, map, enemy);
    reset_str(g_var, my_strlen(g_var));
    reset_str(msg, my_strlen(msg));
    return ret;
}

int player_1_game_2(char **map, char **enemy, int pid, char *msg)
{
    int ret = 0;
    receive_atk(map, pid, msg);
    if (is_navy(map) == 0) {
        send_char('W', pid);
        print_both_map(map, enemy);
        my_printf("Enemy won\n\n");
        ret = 1;
    } else {
        send_char('N', pid);
    }
    return ret;
}