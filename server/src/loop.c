/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-antoine.tmpigny
** File description:
** loop
*/

#include <sys/socket.h>
#include "maccro.h"
#include "definitions.h"
#include "teams_server.h"

bool cmd(info_t *info, int fd)
{
    info->buff = get_next_line(fd);
    if (info->buff == NULL) {
        delete_client(&info->list, fd, &info->_readfds);
        --info->curr_co;
    }
    printf("socket number #%d said: %s\n", fd, info->buff);
    teams_cmd(info, fd);
    free(info->buff);
    return true;
}

bool get_client(info_t *info)
{
    socklen_t addr_len = sizeof(info->cli_addr);

    if ((info->cli_sock = accept(info->serv_sock, SOCK &info->cli_addr,
    &addr_len)) == -1)
        return false;
    printf("New client connected on socket: %d\n", info->cli_sock);
    add_client(&info->list, info->cli_sock);
    ++info->curr_co;
    FD_SET(info->cli_sock, &info->_readfds);
    return true;
}

bool line_connect(int fd, info_t *info)
{
    return (info->serv_sock == fd) ? get_client(info) : cmd(info, fd);
}

bool loop_fd(info_t *info)
{
    for (int i = 0; i < FD_SETSIZE; ++i) {
        if (FD_ISSET(i, &info->afds) && !line_connect(i, info))
            return false;
    }
    return true;
}

int loop(info_t *info)
{
    if (!info)
        return 84;
    while (true) {
        info->afds = info->_readfds;
        if (select(FD_SETSIZE, &info->afds, NULL, NULL, NULL) == -1)
            break;
        if (!loop_fd(info))
            return 84;
    }
    close(info->serv_sock);
    return 0;
}