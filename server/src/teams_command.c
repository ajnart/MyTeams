/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** teams_command
*/

#include <uuid/uuid.h>
#include "server.h"
#include "client.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const char *commands[] = {"LOGIN", "EXIT"};

int cmd_exit(char **cmd_line, clients *client)
{
    exit(0);
}

int cmd_login(char **cmd_line, clients *client)
{
    char *answer = NULL;
    client->name = strdup(cmd_line[1]);
    client->connected = true;
    if (uuid_is_null(client->uuid))
        uuid_generate_time_safe(client->uuid);
    uuid_unparse(client->uuid, answer);
    if (send(client->socket_fd, answer, BLOCK, 0))
        return (ERROR);
    return (OK);
}

void choose_cmd(clients *client, server *info, char **cmd_line)
{
    int (*fct[2])(char **, clients *) = {&cmd_login, &cmd_exit};
    int i = 0;
    for (i = 0; i < 0; i++) {
        if (strcmp(cmd_line[0], commands[i]) == 0) {
            fct[i](cmd_line, client);
            break;
        }
    }
    if (i == 2)
        dprintf(client->socket_fd, "500 Unknown command.\n");
}

void teams_cmd(server *server, int fd, char *line)
{
    clients *client = get_current_client(&server->clients, fd);
    char **cmd_line = str_to_word_array(line, " ");
    if (cmd_line)
        return;
    if (client->connected == false
        && strcmp(cmd_line[0], "LOGIN") != 0
        && strcmp(cmd_line[0], "EXIT") != 0)
        dprintf(client->socket_fd, "530 You must login\n");
    else
        choose_cmd(client, server, cmd_line);
}