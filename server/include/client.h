/*
** EPITECH PROJECT, 2021
** MyTeams [SSH: garuda]
** File description:
** clients
*/

#ifndef CLIENTS_H_
#define CLIENTS_H_

#include <stdbool.h>
#include <uuid/uuid.h>
#include "definitions.h"

typedef struct clients {
    struct clients *next;
    struct clients *prev;
    struct pm *pms;
    int socket_fd;
    char *name;
    bool connected;
    uuid_t uuid;
} __attribute__((aligned(BITS))) clients;

// /send [“user_uuid”] [“message_body”] : send a message to a user
typedef struct pm {
    struct pm *next;
    uuid_t from;
    char *message;
    time_t time;
} __attribute__((aligned(BITS))) pm;

int user(char *line, clients *client);
int users(char *line, clients *client);
int help(char *line, clients *client);
int logout(char *line, clients *client);
int login(char *line, clients *client);

#endif /* !CLIENTS_H_ */
