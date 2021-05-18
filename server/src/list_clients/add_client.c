/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** add_client
*/

#include "teams_server.h"

void add_client(list_t **list, int fd)
{
    list_t *new = malloc(sizeof(*new));
    list_t *tmp = *list;

    new->next = NULL;
    new->is_authenticated = false;
    new->sockfd = fd;
    if (!*list) {
        new->prev = NULL;
        *list = new;
    }
    else {
        while (tmp->next) tmp = tmp->next;
        tmp->next = new;
        new->prev = tmp;
    }
}