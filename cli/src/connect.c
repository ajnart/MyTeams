/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** connect
*/

#include <stdio.h>
#include "definitions.h"
#include "setup.h"

int tryconnect(struct connection c, connection_t *connection)
{
    connection->socket_fd = 0;
    // Create socket
    connection->socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (connection->socket_fd == -1) {
        printf("[E] Could not create socket\n");
        return (ERROR);
    }

    connection->server.sin_addr.s_addr = inet_addr(c.ip);
    connection->server.sin_family = AF_INET;
    connection->server.sin_port = htons(c.port);

    // Connect to remote server
    if (connect(connection->socket_fd, (struct sockaddr *) &connection->server,
            sizeof(connection->server))
        < 0) {
        printf("[E] Could not connect to server.\n");
        return (ERROR);
    }
    return (OK);
}