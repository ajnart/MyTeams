/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** ftp
*/

#include "server.h"
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

static struct sockaddr_in *assign(int port)
{
    struct sockaddr_in *addr = malloc(sizeof(*addr));
    if (!addr)
        return NULL;
    addr->sin_addr.s_addr = INADDR_ANY;
    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);
    return addr;
}

static server set_server(server new_server, int port)
{
    struct sockaddr_in *addr;

    // set socket bind or listen to a port
    if ((new_server.server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1
        || (addr = assign(port)) == NULL)
        exit(84);
    if (((bind(new_server.server_socket, (struct sockaddr *)addr, sizeof(*addr))) == -1)
        || (listen(new_server.server_socket, MAX_CLIENTS) == -1)) {
        close(new_server.server_socket);
        perror("");
        exit(84);
    }
    printf("$> %d\n", port);
    return (new_server);
}

static server init_server(long port)
{
    server new_server;
    new_server.clients = malloc(sizeof(clients));
    new_server.teams = malloc(sizeof(team));
    if (new_server.clients == NULL || new_server.teams == NULL)
        exit(84);
    new_server.server_socket = 0;
    new_server.connected = 0;
    return (set_server(new_server, port));
}

int teams_server(unsigned int port)
{
    // init struct server
    server server = init_server(port);
    //run server
    return run(server);
}