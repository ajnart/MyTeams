/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** get_client
*/

#include "client.h"
#include <stdlib.h>

clients *get_current_client(clients **list, int fd)
{
    clients *tmp = *list;

    while (tmp) {
        if (tmp->socket_fd == fd)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}