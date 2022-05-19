/*
** EPITECH PROJECT, 2021
** navy2.c
** File description:
** navy2
*/

#include "include/navy.h"

void reset_str(char *str,int nb)
{
    for (int i = 0; i < nb; i++) {
        str[i] = '\0';
    }
}

void handler_pid(int nb, siginfo_t *t, void *)
{
    kill(t->si_pid, SIGUSR2);
    g_var = int_to_char(t->si_pid);
}

void handler_plr2(int nb, siginfo_t *t, void *)
{
    g_var[0] = 'o';
    g_var[1] = 'k';
}

int start_player_1(char **map, char **enemy)
{
    int pid = 0;
    struct sigaction sig;
    sig.sa_sigaction = handler_pid;
    sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sig, NULL);
    while (my_strlen(g_var) == 0) { }
    pid = my_getnbr(g_var);
    reset_str(g_var, my_strlen(g_var));
    usleep(2000);
    return player_1_game(map, enemy, pid);
}

int start_player_2(char **map, char **enemy, int pid)
{
    struct sigaction sig;
    sig.sa_sigaction = handler_plr2;
    sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sig, NULL);
    usleep(4000);
    kill(pid, SIGUSR2);
    while (g_var[0] != 'o' && g_var[1] != 'k' && g_var[2] != '\0') { }
    reset_str(g_var, 2);
    usleep(2000);
    return player_2_game(map, enemy, pid);
}
