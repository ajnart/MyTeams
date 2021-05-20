/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** add_client
*/

#include "teams_server.h"

void add_client(list_t **list, int fd)
{
    list_t *create = malloc(sizeof(*create));
    list_t *tmp = *list;

    create->next = NULL;
    create->is_authenticated = false;
    create->sockfd = fd;
    if (!*list) {
        create->prev = NULL;
        *list = create;
    }
    else {
        while (tmp->next) tmp = tmp->next;
        tmp->next = create;
        create->prev = tmp;
    }
}