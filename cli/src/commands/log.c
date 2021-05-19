/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** login
*/

#include <string.h>
#include "definitions.h"
#include "logging_client.h"

// Strtok_r is used two times to catch the username used to log-in.
int login(connection_t *connection, char *str)
{
    char *rest = str;
    const char *token = NULL;
    if (str == NULL || str[0] != '/')
        return (ERROR);
    token = strtok_r(rest, " \n", &rest);
    token = strtok_r(rest, " \n", &rest);
    // Send command line gotten by the CLI to the server
    // example: /login thomas -> /login thomas
    send(connection->socket_fd, str, strlen(str), 0);
    return (OK);
}

int logout(connection_t *connection, char *str)
{
    return (OK);
}