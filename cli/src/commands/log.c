/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** login
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <uuid/uuid.h>
#include "definitions.h"
#include "logging_client.h"

// Strtok_r is used two times to catch the username used to log-in.
int login(connection_t *connection, char *str)
{
    char *answer = NULL;
    if (str == NULL || str[0] != '/')
        return (ERROR);
    // Send command line gotten by the CLI to the server
    // example: /login thomas -> /login thomas
    send(connection->socket_fd, str, strlen(str), 0);
    if (read(connection->socket_fd, answer, BLOCK) <= 0)
        return (ERROR);
    // Got back an UUID from the server, applying it to the uuid field in the connection structure.
    if (uuid_parse(answer, connection->uuid) != 0)
        return (ERROR);
    return (OK);
}

int logout(connection_t *connection, char *str)
{
    char *answer = NULL;
    if (connection->connected == false)
    {
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