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
#include <signal.h>
#include <errno.h>
#include <string.h>
#include "definitions.h"
#include "server.h"

static volatile int keep_running = true;


static void sig_handler()
{
    keep_running = false;
}

static bool get_cmd(clients *client, server *server)
{
    char *line = get_next_line(client->socket_fd);
    dprintf(server->server_socket, "%s\n", line);
    if (line == NULL) {
        delete_client(&server->clients, client->socket_fd);
        return false;
    }
    teams_cmd(server, client, line);
    free(line);
    return true;
}

void loop(clients **list, server *server)
{
    clients *tmp = *list;

    while (tmp->next) {
        if (FD_ISSET(tmp->socket_fd, &server->fd)) {
            get_cmd(tmp, server);
        }
        tmp = tmp->next;
    }

}

static void msg_client(server *server)
{
    loop(&server->clients, server);
}

static void accept_client(server *server)
{
    int new_client = 0;
    struct sockaddr_in addr = {0};
    int size = sizeof(addr);

    if (FD_ISSET(server->server_socket, &server->fd)) {
        if ((new_client = accept(server->server_socket,
        (struct sockaddr *)&addr, (socklen_t *)&size)) == -1)
            exit(84);
        printf("New client connected on socket: %d\n", new_client);
        if (server->connected == MAX_CLIENTS) // check full
            return;
        add_client(&server->clients, new_client); // add to list
        ++server->connected;
    }
}

static bool select_client(server *server)
{
    bool ret = false;
    FD_ZERO(&server->fd);
    FD_SET(server->server_socket, &server->fd);
    setfd_client(&server->clients, server->fd);
    if (select(FD_SETSIZE, &server->fd, NULL, NULL, NULL) == -1)
        (errno == EINTR) ? ret = true : exit(84);
    return ret;
}

int run(server server)
{
    // loop run server
    signal(SIGINT, sig_handler);
    while (keep_running)
    {
        select_client(&server);
        accept_client(&server);
        msg_client(&server);
    }
    printf("server close\n");
    close(server.server_socket);
    return (OK);
}