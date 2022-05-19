/*
** EPITECH PROJECT, 2021
** map
** File description:
** map
*/

#include "./include/navy.h"
#include "./include/my_macro_abs.h"

int check_line(char *pos)
{
    int result = 0;
    int count = 0;
    for (int i = 0; pos[i] != '\0';i++) {
        if (pos[i] == '\n')
            count += 1;
    }
    if (count != 4)
        return 84;
    count = 0;
    for (int i = 0; pos[i] != '\0'; i++) {
        count++;
        if (pos[i] == '\n' && count != 8)
            return 84;
        if (pos[i] == '\n')
            count = 0;
    }
    return 0;
}

void fill_map(int **map)
{
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            map[y][x] = 0;
        }
    }
}

int check_size(char *pos)
{
    int res = 0;
    int letter = 0;
    int digit = 0;
    for (int i = 0; i < 4; i++) {
        letter = convert_pos(pos[2 + i * 8]);
        digit = get_digits(pos[3 + i * 8]);
        if (check_letters(letter, convert_pos(pos[5 + i * 8]) == 84))
            return 84;
        if (check_digits(digit, get_digits(pos[6 + i * 8])) == 84)
            return 84;
        res = convert_pos(pos[2 + i * 8]) - convert_pos(pos[5 + i * 8]);
        if (!(res == 1 + i || res == 0 || res == -1 -i))
            return 84;
        res = get_digits(pos[3 + i * 8]) - get_digits(pos[6 + i * 8]);
        if (!(res == 1 + i || res == 0 || res == -1 - i))
            return 84;
    }
    return 0;
}

int check_pos(char *pos)
{
    if (check_line(pos) == 84)
        return 84;
    if (check_navy(pos) == 84)
        return 84;
}
