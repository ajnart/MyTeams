/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** teams_command
*/

#include "definitions.h"
#include "server.h"
#include <uuid/uuid.h>
#include "client.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int (*pf[])(char *, clients *) = {help, login, logout, user, users};

int user(char *line, clients *client)
{
    dprintf(client->socket_fd, "%s\n", client->name);
    return (OK);
}

int users(char *line, clients *client)
{
    //list_client(&client, client->socket_fd);
    return (OK);
}

int help(char *line, clients *client)
{
    dprintf(client->socket_fd, USAGE);
    return (OK);
}

int logout(char *line, clients *client)
{
    client->connected = false;
}

int login(char *line, clients *client)
{
    char *answer = NULL;
    client->name = strdup(line);
    client->connected = true;
    if (uuid_is_null(client->uuid))
        uuid_generate_time_safe(client->uuid);
    uuid_unparse(client->uuid, answer);
    if (send(client->socket_fd, answer, BLOCK, 0))
        return (ERROR);
    return (OK);
}

enum commands getcommand(const char *line)
{
    enum commands result = NONE;
    const char *commands[] = {"help", "login", "logout", "user", "users"};
    char *rest = strdup(line);

    if (line == NULL || line[0] != '/')
        return result;
    const char *cmd = strtok_r(rest, " \n", &rest);
    for (unsigned long i = 0; i < sizeof(commands) / 8; i++) {
        if (strcmp(cmd + 1, commands[i]) == 0)
            result = i; // I is set to the index of the command needed
    }
    return result; // If nothing is found it will return NONE
}


void teams_cmd(server *server, clients *client, char *line)
{
    int read = 0;
    char **cmd_line = str_to_word_array(line, " ");
    if (cmd_line)
        return;
    enum commands command = NONE;
    command = getcommand(line);
    if (client->connected == false
        && command != LOGIN
        && command != HELP
        && command != LOGOUT)
        dprintf(client->socket_fd, "530 You must login\n");
    else {
        if (command != NONE)
            read = pf[command](cmd_line[1], client);
    }
        
}