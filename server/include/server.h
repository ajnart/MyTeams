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
} __attribute__((aligned(BITS))) server;

#endif /* !SERVER_H_ */
