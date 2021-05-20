/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** teams_command
*/

#include "teams_server.h"

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
        dprintf(client->sockfd, "500 Unknown command.\n");
    print_client(info->list);
}