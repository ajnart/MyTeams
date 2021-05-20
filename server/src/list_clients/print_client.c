/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** print_client
*/

#include "list.h"
#include <stdio.h>

void print_client(list_t *list)
{
    list_t *tmp = list;

    while (tmp) {
        printf("fd -> %d\n", tmp->sockfd);
        tmp = tmp->next;
    }
}