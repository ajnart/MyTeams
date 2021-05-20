/*
** EPITECH PROJECT, 2021
** MyTeams [SSH: garuda]
** File description:
** users
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <uuid/uuid.h>
#include "definitions.h"
#include "myteams/logging_client.h"

// "•/users:\t get the list of all users that exist on the domain\n"
int users(connection_t *connection, char *str)
{
    char answer[BLOCK];

    if (str == NULL || str[0] != '/')
        return (ERROR);
    send(connection->socket_fd, str, strlen(str), 0);
    if (read(connection->socket_fd, answer, BLOCK) <= 0)
        return (ERROR);
    printf("%s", answer);
    return (OK);
}

// "•/user\t [\"user_uuid\"] : get information about a user\n"
int user(connection_t *connection, char *str)
{
    char answer[BLOCK];
    const char *token = NULL;
    char *rest = strdup(str);
    token = strtok_r(rest, " \n", &rest);
    token = strtok_r(rest, " \n", &rest);
    if (token == NULL) {
        printf("[E] You need to specify an UUID !\n");
        return (ERROR);
    }
    send(connection->socket_fd, str, strlen(str), 0);
    if (read(connection->socket_fd, answer, BLOCK) <= 0)
        return (ERROR);
    printf("%s\n", answer);
    return (OK);
}