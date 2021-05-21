/*
** EPITECH PROJECT, 2021
** MyTeams [SSH: garuda]
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <sys/socket.h>
#include "client.h"
#include "teams.h"

typedef struct server {
    clients *clients;
    team *teams;
    fd_set fd;
    int server_socket;
    unsigned int connected;
} __attribute__((aligned(BITS))) server;


int teams_server(unsigned int port);
int run(server server);
void teams_cmd(server *server, int fd, char *line);
char **str_to_word_array(char *str, char *delim);

#endif /* !SERVER_H_ */
