/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** get_next_line
*/

#include "teams_server.h"

char *get_next_line(int fd)
{
    char *buf = malloc(sizeof(char) * 1);
    int index = 0;
    char current = 0;

    if (!buf || read(fd, &current, 1) <= 0)
        return NULL;
    if (!index && current == '\n')
        current = -1;
    buf[index] = current;
    buf = realloc(buf, ++index + 1);
    while (current && current != '\n') {
        if (!buf || read(fd, &current, 1) <= 0)
            return NULL;
        if (!index && current == '\n') {
            current = -1;
            continue;
        } buf[index] = current;
        buf = realloc(buf, ++index + 1);
    } buf[index] = 0;
    return (!current ? NULL : buf);
}