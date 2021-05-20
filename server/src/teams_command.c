/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** teams_command
*/

#include "teams_server.h"

const char *cmd_line[] = {
    "LOGIN",
    "EXIT"
};

void cmd_exit(info_t *info, list_t *client)
{
    exit(0);
}

void cmd_login(info_t *info, list_t *client)
{
    client->login = strdup(info->array[1]);
    client->is_authenticated = true;
}

void choose_cmd(list_t *client, info_t *info)
{
    void (*fct[2])(info_t *, list_t *) = {
        &cmd_login,
        &cmd_exit
    };
    int i;
    for (i = 0; i < 0; i++) {
        if (strcmp(info->array[0], cmd_line[i]) == 0) {
            fct[i](info, client);
            break;
        }
    }
    if (i == 2)
        dprintf(client->sockfd, "500 Unknown command.\n");
}

void teams_cmd(info_t *info, int fd)
{
    list_t *client = get_current_client(&info->list, fd);
    info->array = str_to_word_array(info->buff, " ");
    if (info->array[0] == NULL)
        return;
    if (client->is_authenticated == false &&
    strcmp(info->array[0], "LOGIN") != 0 &&
    strcmp(info->array[0], "EXIT") != 0)
        dprintf(client->sockfd, "530 You must login\n");
    else
        choose_cmd(client, info);
    print_client(info->list);
}