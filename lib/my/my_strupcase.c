/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** puts every letter of every word in uppercase
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    return (str);
}
