/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** definitions
*/

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdbool.h>
#include <uuid/uuid.h>

#define OK    0
#define BLOCK 4096
#define ERROR 84

// Enum containing all the valid commands. To be used in the runner.
enum commands
{
    NONE = -1,
    HELP,
    LOGIN,
    LOGOUT,
};

// Alligned for easier access to values
typedef struct {
    int socket_fd;
    struct sockaddr_in server;
    bool connected;
    uuid_t uuid;
} __attribute__((aligned(64))) connection_t;

#endif /* !DEFINITIONS_H_ */
