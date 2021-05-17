/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** connect
*/

#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include "argparser.h"
#include "definitions.h"

int tryconnect(struct connection c)
{
    int socket_desc = 0;
    struct sockaddr_in server;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("[E] Could not create socket\n");
        return (ERROR);
    }

    server.sin_addr.s_addr = inet_addr(c.ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(c.port);

    // Connect to remote server
    if (connect(socket_desc, (struct sockaddr *) &server, sizeof(server))
        < 0) {
        printf("[E] Could not connect to server.\n");
        return (ERROR);
    }
    return (OK);
}