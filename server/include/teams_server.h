/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** teams_server
*/


#ifndef TEAMS_SERVER_H_
#define TEAMS_SERVER_H_

#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include "list.h"

typedef struct info
{
    int port;
    char *path;
    int cli_sock;
    struct sockaddr_in cli_addr;
    int serv_sock;
    struct sockaddr_in serv_addr;
    int curr_co;
    fd_set __readfds;
    char *buff;
    list_t *list;
} info_t;

int teams_server(int port);
int loop(info_t *info);
char *get_next_line(int fd);

#endif /* !TEAMS_SERVER_H_ */
