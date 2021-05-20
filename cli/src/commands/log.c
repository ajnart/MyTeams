/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** login
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "definitions.h"
#include "myteams/logging_client.h"

// Strtok_r is used two times to catch the username used to log-in.
int login(connection_t *connection, char *str)
{
    char answer[BLOCK];
    char *rest = strdup(str);
    const char *token = NULL;

    if (str == NULL || str[0] != '/')
        return (ERROR);
    token = strtok_r(rest, " \n", &rest);
    token = strtok_r(rest, " \n", &rest);
    if (token == NULL) {
        printf("[E] You need a name to login!\n");
        return (ERROR);
    }
    send(connection->socket_fd, str, strlen(str), 0);
    if (read(connection->socket_fd, answer, BLOCK) <= 0)
        return (ERROR);
    if (uuid_parse(answer, connection->uuid) != 0)
        return (ERROR);
    connection->connected = true;
    return (OK);
}

int logout(connection_t *connection, char *str)
{
    char answer[BLOCK];
    if (connection->connected == false) {
        printf("You are not currently logged-in.\n");
        return (ERROR);
    }
    sprintf(answer, "%s %s", str, connection->uuid);
    send(connection->socket_fd, answer, strlen(answer), 0);
    if (read(connection->socket_fd, answer, BLOCK) <= 0)
        return (ERROR);
    uuid_clear(connection->uuid);
    connection->connected = false;
    return (OK);
}