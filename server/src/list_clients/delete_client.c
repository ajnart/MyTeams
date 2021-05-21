/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** delete_client
*/

#include "client.h"
#include <stdlib.h>

void delete_client(clients **list, int fd)
{
    clients *tmp = *list;

    while (tmp != NULL && tmp->socket_fd != fd)
        tmp = tmp->next;
    if (*list == NULL || tmp == NULL)
        return;
    if (*list == tmp)
        *list = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;
    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;
    free(tmp);
    tmp = NULL;
}