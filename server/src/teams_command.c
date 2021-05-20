/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** teams_command
*/

#include <uuid/uuid.h>
#include "teams_server.h"

const char *cmd_line[] = {"LOGIN", "EXIT"};

int cmd_exit(info_t *info, list_t *client)
{
    exit(0);
}

int cmd_login(info_t *info, list_t *client)
{
    char *answer = NULL;
    client->login = strdup(info->array[1]);
    client->is_authenticated = true;
    printf("logging in %s\n", info->buff);
    if (uuid_is_null(client->uuid))
        uuid_generate_time_safe(client->uuid);
    uuid_unparse(client->uuid, answer);
    if (send(client->sockfd, answer, BLOCK, 0))
        return (ERROR);
    return (OK);
}

void choose_cmd(list_t *client, info_t *info)
{
    int (*fct[2])(info_t *, list_t *) = {&cmd_login, &cmd_exit};
    int i = 0;
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
    if (client->is_authenticated == false
        && strcmp(info->array[0], "LOGIN") != 0
        && strcmp(info->array[0], "EXIT") != 0)
        dprintf(client->sockfd, "530 You must login\n");
    else
        choose_cmd(client, info);
    print_client(info->list);
}