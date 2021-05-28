/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong [WSL: Ubuntu]
** File description:
** setfd_client
*/

#include "client.h"

void setfd_client(clients **list, fd_set fd)
{
    clients *tmp = *list;

    while (tmp->next) {
        FD_SET(tmp->socket_fd, &fd);
        tmp = tmp->next;
    }
}