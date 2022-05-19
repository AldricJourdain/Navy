/*
** EPITECH PROJECT, 2021
** check_map2.c
** File description:
** check_map2
*/

#include "include/navy.h"

int convert_pos(char letter)
{
    int res = letter - 'A';
    if (!(res >= 0 && res < 8))
        return 84;
    return res;
}

int check_letters(int letter1, int letter2)
{
    if (letter1 == 84 || letter2 == 84)
        return 84;
    else
        return 0;
}

int check_digits(int digit1, int digit2)
{
    if (digit1 == 84 || digit2 == 84)
        return 84;
    else
        return 0;
}

int get_digits(char nb)
{
    int res = nb - '0';
    if (res < 1 || res > 8)
        return 84;
    else
        return res;
}
