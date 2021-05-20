/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** teams_server
*/

#ifndef TEAMS_SERVER_H_
#define TEAMS_SERVER_H_

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
#include "list.h"
#include "definitions.h"

typedef struct info {
    int port;
    char *path;
    int cli_sock;
    struct sockaddr_in cli_addr;
    int serv_sock;
    struct sockaddr_in serv_addr;
    int curr_co;
    fd_set _readfds;
    fd_set afds;
    char *buff;
    char **array;
    list_t *list;
} info_t;

int teams_server(unsigned int port);
int loop(info_t *info);
void teams_cmd(info_t *info, int fd);

char *get_next_line(int fd);
char **str_to_word_array(char *str, char *delim);

#endif /* !TEAMS_SERVER_H_ */
