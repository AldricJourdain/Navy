/*
** EPITECH PROJECT, 2021
** conversion.c
** File description:
** conversion
*/

#include "include/navy.h"

char *char_to_bin(char c)
{
    char *bin = malloc(sizeof(char) * 8);
    int val = c;
    int i = 0;
    for (i = 0; val >= 1; i++) {
        bin[i] = (val % 2) + '0';
        val /= 2;
    }
    bin[i] = '\0';
    if (my_strlen(bin) < 7) {
        for (int j = my_strlen(bin); j < 7; j++) {
            bin[j] = '0';
            bin[j + 1] = '\0';
        }
    }
    my_revstr(bin);
    return bin;
}

char bin_to_char(char *bin)
{
    int tmp = 0;
    int res = 0;
    char c;
    char *cpy = my_strdup(bin);
    my_revstr(cpy);
    for (int i = 0; i < my_strlen(cpy); i++) {
        tmp = cpy[i] - '0';
        res += tmp * my_compute_power_rec(2, i);
    }
    c = res;
    free(cpy);
    return c;
}

char *int_to_char(int nb)
{
    int size = find_power_pid(nb);
    char *nbr = malloc(sizeof(char) * size + 1);
    int current = 0;
    for (int i = 0; i < size; i++) {
        current = nb % 10;
        nbr[i] = current + '0';
        nb /= 10;
    }
    my_revstr(nbr);
    return nbr;
}

int find_power_pid(int nb)
{
    int i = 0;
    for (i = 0; nb > 0; i++)
        nb /= 10;
    return i;
}
