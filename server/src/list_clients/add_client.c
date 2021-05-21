/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** add_client
*/

#include "client.h"
#include <stdlib.h>

void add_client(clients **list, int fd)
{
    clients *create = malloc(sizeof(*create));
    clients *tmp = *list;

    create->next = NULL;
    create->connected = false;
    create->name = NULL;
    create->socket_fd = fd;
    create->pms = malloc(sizeof(*create->pms));
    if (!*list) {
        create->prev = NULL;
        *list = create;
    } else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = create;
        create->prev = tmp;
    }
}