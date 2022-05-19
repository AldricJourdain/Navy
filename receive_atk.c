/*
** EPITECH PROJECT, 2021
** receive_atk.c
** File description:
** receive_atk
*/

#include "include/navy.h"

void check_hit(char **map, int pid, char *msg)
{
    int line = get_digits(msg[1]) - 1;
    int pos = convert_pos(msg[0]);
    if (map[line][pos] >= '2' && map[line][pos] <= '5') {
        my_printf("hit\n\n");
        map[line][pos] = 'x';
        usleep(2000);
        send_char('h', pid);
    } else if (map[line][pos] != 'x') {
        map[line][pos] = 'o';
        my_printf("missed\n\n");
        usleep(2000);
        send_char('m', pid);
    } else {
        my_printf("hit\n\n");
        usleep(2000);
        send_char('h', pid);
    }
}

void receive_atk(char **map, int pid, char *msg)
{
    my_printf("waiting for enemy’s attack...\n");
    while (my_strlen(g_var) < 7) { }
    msg[my_strlen(msg)] = bin_to_char(g_var);
    reset_str(g_var, my_strlen(g_var));
    usleep(2000);
    kill(pid, SIGUSR1);
    while (my_strlen(g_var) < 7) { }
    msg[my_strlen(msg)] = bin_to_char(g_var);
    reset_str(g_var, my_strlen(g_var));
    usleep(2000);
    my_printf("%s: ", msg);
    check_hit(map, pid, msg);
    while (my_strlen(g_var) < 7) { }
    reset_str(g_var, my_strlen(g_var));
    reset_str(msg, my_strlen(msg));
    usleep(2000);
}
