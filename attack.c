/*
** EPITECH PROJECT, 2021
** get_input.c
** File description:
** get_input
*/

#include "include/navy.h"

char *get_attack(void)
{
    char *attack;
    size_t len = 0;
    char *buffer;
    my_printf("attack: \033[3m");
    while (getline(&buffer, &len, stdin) < 0) { }
    my_printf("\033[0m");
    for (len = 0; buffer[len] != '\0' && buffer[len] != '\n'; len++) { }
    if (len == 2) {
        attack = malloc(sizeof(char) * 3);
        my_strcpy(attack, buffer);
        free(buffer);
        return attack;
    } else {
        my_printf("wrong position\n");
        attack = get_attack();
        free(buffer);
        return attack;
    }
}

int check_attack(char *atk)
{
    if (!(atk[0] >= 'A' && atk[0] <= 'H'))
        return 84;
    if (!(atk[1] >= '0' && atk[1] <= '8'))
        return 84;
    return 0;
}

void attack(char **enemy, int pid, char *msg)
{
    char *atk = get_attack();
    if (check_attack(atk) == 84) {
        my_printf("wrong position\n");
        attack(enemy, pid, msg);
        return;
    }
    my_printf("%c%c: ", atk[0], atk[1]);
    usleep(2000);
    send_char(atk[0], pid);
    while (my_strlen(g_var) == 0) { }
    usleep(2000);
    send_char(atk[1], pid);
    reset_str(g_var, my_strlen(g_var));
    while (my_strlen(g_var) < 7) { }
    msg[my_strlen(msg)] = bin_to_char(g_var);
    reset_str(g_var, my_strlen(g_var));
    attack2(enemy, msg, atk);
    send_char('e', pid);
    free(atk);
}

void attack2(char **enemy, char *msg, char *atk)
{
    if (msg[0] == 'h') {
        my_printf("hit\n\n");
        put_attack(enemy, atk, 'x');
    } else if (msg[0] == 'm') {
        my_printf("missed\n\n");
        put_attack(enemy, atk, 'o');
    }
    reset_str(msg, my_strlen(msg));
}

void put_attack(char **enemy, char *atk, char sign)
{
    int line = get_digits(atk[1]) - 1;
    int pos = convert_pos(atk[0]);
    enemy[line][pos] = sign;
}
