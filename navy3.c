/*
** EPITECH PROJECT, 2021
** navy3.c
** File description:
** navy3
*/

#include "include/navy.h"

void handler_zero(int nb, siginfo_t *t, void *)
{
    int len = my_strlen(g_var);
    g_var[len] = '0';
    g_var[len + 1] = '\0';
}

void handler_one(int nb, siginfo_t *t, void *)
{
    int len = my_strlen(g_var);
    g_var[len] = '1';
    g_var[len + 1] = '\0';
}

void setup_handler(void)
{
    struct sigaction sig;
    sig.sa_sigaction = handler_zero;
    sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sig, NULL);
    sig.sa_sigaction = handler_one;
    sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sig, NULL);
}

int player_1_game(char **map, char **enemy, int pid)
{
    int ret = 0;
    char *msg = malloc(sizeof(char) * 3);
    int end = 0;
    setup_handler();
    while (end == 0) {
        print_both_map(map, enemy);
        usleep(2000);
        attack(enemy, pid, msg);
        end = is_finished(msg, map, enemy);
        reset_str(g_var, my_strlen(g_var));
        reset_str(msg, my_strlen(msg));
        if (end == 0) {
            end = player_1_game_2(map, enemy, pid, msg);
            ret = end;
        }
    }
    free_all(map, enemy, msg);
    return ret;
}

int player_2_game(char **map, char **enemy, int pid)
{
    int ret = 0;
    int end = 0;
    char *msg = malloc(sizeof(char) * 3);
    setup_handler();
    while (end == 0) {
        print_both_map(map, enemy);
        receive_atk(map, pid, msg);
        if (is_navy(map) == 0) {
            send_char('W', pid);
            print_both_map(map, enemy);
            my_printf("Enemy won\n\n");
            end = 1;
            ret = 1;
        } else
            player_2_game_2(map, enemy, pid, msg);
    }
    free_all(map, enemy, msg);
    return ret;
}
