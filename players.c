/*
** EPITECH PROJECT, 2021
** players.c
** File description:
** players
*/

#include "include/navy.h"

int player_1(int argc, const char **argv)
{
    struct sigaction sig;
    char *pos = load_file(argv[1]);
    if (pos == NULL)
        return 84;
    if (check_pos(pos) == 84)
        return 84;
    my_printf("my_pid: %d\n", getpid());
    my_printf("waiting for enemy connection...\n\n");
    return player_1_loop(pos);
}

int player_2(int argc, const char **argv)
{
    char *pos = load_file(argv[2]);
    int pid = 0;
    if (pos == NULL)
        return 84;
    if (!is_number(argv[1]))
        return 84;
    if (check_pos(pos) == 84)
        return 84;
    pid = my_getnbr(argv[1]);
    my_printf("my_pid: %d\n", getpid());
    kill(pid, SIGUSR1);
    return player_2_loop(pos, pid);
}
