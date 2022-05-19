/*
** EPITECH PROJECT, 2021
** navy.c
** File description:
** navy
*/

#include "include/navy.h"

void handler_bip_boop1(int nb, siginfo_t *t, void *)
{
    kill(t->si_pid, SIGUSR1);
    g_var[0] = 'c';
    g_var[1] = 'o';
}

void handler_bip_boop2(int nb, siginfo_t *t, void *)
{
    g_var[0] = 'c';
    g_var[1] = 'o';
}

int player_1_loop(char *pos)
{
    struct sigaction sig;
    sig.sa_sigaction = handler_bip_boop1;
    sig.sa_flags = SA_SIGINFO;
    g_var = pos;
    sigaction(SIGUSR1, &sig, NULL);
    while (g_var[0] != 'c' && g_var[1] != 'o' && g_var[2] != '\0') { }
    my_printf("enemy connected\n\n");
    reset_str(g_var, 2);
    char **map = create_map(pos);
    char **enemy = create_map_empty();
    usleep(2000);
    return start_player_1(map, enemy);
}

int player_2_loop(char *pos, int pid)
{
    struct sigaction sig;
    sig.sa_sigaction = handler_bip_boop2;
    sig.sa_flags = SA_SIGINFO;
    g_var = pos;
    sigaction(SIGUSR1, &sig, NULL);
    while (g_var[0] != 'c' && g_var[1] != 'o' && g_var[2] != '\0') { }
    my_printf("successfully connected\n\n");
    reset_str(g_var, 2);
    char **map = create_map(pos);
    char **enemy = create_map_empty();
    usleep(2000);
    return start_player_2(map, enemy, pid);
}
