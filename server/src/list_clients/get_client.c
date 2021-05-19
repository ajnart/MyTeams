/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** get_client
*/

#include "teams_server.h"

list_t *get_current_client(list_t **list, int fd)
{
    list_t *tmp = *list;

    while (tmp) {
        if (tmp->sockfd == fd)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}