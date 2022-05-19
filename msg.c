/*
** EPITECH PROJECT, 2021
** msg.c
** File description:
** msg
*/

#include "include/navy.h"

void send_signal(char c, int pid)
{
    if (c == '0')
        kill(pid, SIGUSR1);
    if (c == '1')
        kill(pid, SIGUSR2);
}

void send_msg(char *msg, int pid)
{
    int len = my_strlen(msg);
    char *bin;
    for (int i = 0; i < len; i++) {
        char *bin = char_to_bin(msg[i]);
        for (int j = 0; j < my_strlen(bin); j++) {
            send_signal(bin[j], pid);
        }
    }
}

void send_char(char c, int pid)
{
    char *bin = char_to_bin(c);
    for (int j = 0; j < my_strlen(bin); j++) {
        send_signal(bin[j], pid);
        usleep(3000);
    }
}
