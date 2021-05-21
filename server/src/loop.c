/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-antoine.tmpigny
** File description:
** loop
*/

#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"
#include "server.h"

static bool cmd(server *server, int fd)
{
    size_t len = 0;
    char *line = NULL;

    getline(&line, &len, fdopen(fd, "r+"));
    if (line == NULL) {
        close(fd);
        FD_CLR(fd, &server->fd);
        delete_client(&server->clients, fd);
        --server->connected;
    }
    printf("socket number #%d said: %s\n", fd, line);
    teams_cmd(server, fd, line);
    free(line);
    return true;
}

static bool get_client(server *server)
{
    // accept client connection and stock it
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    memset(&addr, 0, addr_len);
    int client_socket;

    if ((client_socket = accept(server->server_socket,
    (struct sockaddr *)&addr, &addr_len)) == -1)
        return false;
    if (server->connected == MAX_CLIENTS) {
        dprintf(client_socket, "Too many clients already connected\n");
            return true;
    }
    ++server->connected;
    printf("New client connected on socket: %d\n", client_socket);
    add_client(&server->clients, client_socket);
    FD_SET(client_socket, &server->fd);
    return true;
}

static bool line_connect(int fd, server server)
{
    return (server.server_socket == fd) ? get_client(&server) : cmd(&server, fd);
}

static bool loop_fd(server server, fd_set tmp)
{
    // check fd
    for (int i = 0; i < FD_SETSIZE; ++i) {
        if (FD_ISSET(i, &tmp) && !line_connect(i, server))
            return false;
    }
    return true;
}

int run(server server)
{
    fd_set tmp;

    // loop run server
    while (true)
    {
        tmp = server.fd;
        if (select(FD_SETSIZE, &tmp, NULL, NULL, NULL) == -1)
            break;
        if (!loop_fd(server, tmp))
            return (ERROR);
    }
    close(server.server_socket);
    return (OK);
}