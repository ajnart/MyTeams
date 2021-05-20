/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** ftp
*/

#include "teams_server.h"
#include "maccro.h"

struct sockaddr_in *assign(info_t *info)
{
    struct sockaddr_in *addr = malloc(sizeof(*addr));
    if (!addr)
        return NULL;
    addr->sin_addr.s_addr = INADDR_ANY;
    addr->sin_family = AF_INET;
    addr->sin_port = htons(info->port);
    return addr;
}

info_t *start(info_t *info)
{
    struct sockaddr_in *addr;
    if ((info->serv_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1
        || (addr = assign(info)) == NULL || !info)
        return NULL;
    if (((bind(info->serv_sock, SOCK addr, sizeof(*addr))) == -1)
        || (listen(info->serv_sock, 5) == -1)) {
        close(info->serv_sock);
        return NULL;
    }
    printf("-> %d\n", info->port);
    FD_ZERO(&info->_readfds);
    FD_SET(info->serv_sock, &info->_readfds);
    return info;
}

info_t *init_struct(info_t *info, int port)
{
    if (!info)
        return NULL;
    info->port = port;
    info->cli_sock = 0;
    memset(&info->cli_addr, 0, sizeof(info->cli_addr));
    info->curr_co = 0;
    info->buff = NULL;
    return info;
}

int teams_server(unsigned int port)
{
    info_t *info = malloc(sizeof(*info));
    return loop(start(init_struct(info, port)));
}