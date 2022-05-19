/*
** EPITECH PROJECT, 2021
** open_file.c
** File description:
** open_file
*/

#include "./include/my.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    return fd;
}

char *load_file(char const *filepath)
{
    int output = 0;
    char *buffer;
    int size = 0;
    int fd = open_file(filepath);
    if (fd == -1)
        return NULL;
    buffer = malloc(32000 * sizeof(char));
    output = read(fd, buffer, 32000);
    if (output == -1)
        return NULL;
    buffer[my_strlen(buffer)] = '\0';
    close(fd);
    return buffer;
}
