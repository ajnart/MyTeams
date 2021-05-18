/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** delete_client
*/

#include "teams_server.h"

void delete_client(list_t **list, int fd, fd_set *__readfds)
{
    list_t *tmp = *list;

    close(fd);
    FD_CLR(fd, __readfds);
    while (tmp != NULL && tmp->sockfd != fd) tmp = tmp->next;
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