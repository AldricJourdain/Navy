/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "./include/navy.h"

char *g_var;

int navy(int argc, const char **argv)
{
    g_var = malloc(sizeof(char) * 8);
    if (g_var == NULL)
        return 84;
    if (argc == 2) {
        return player_1(argc, argv);
    }
    if (argc == 3) {
        return player_2(argc, argv);
    }
    return 84;
}

void print_help(void)
{
    my_printf("USAGE\n");
    my_printf("     ./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n");
    my_printf("     first_player_pid: only for the 2nd player.\
pid of the first player.\n");
    my_printf("     navy_positions: file representing the \
positions of the ships.\n");
}

int main(int argc, const char **argv)
{
    if (argc == 2 && argv[1][0] == '-' &&
    argv[1][1] == 'h' && argv[1][2] == '\0') {
        print_help();
        return 0;
    }
    return (navy(argc, argv));
}
