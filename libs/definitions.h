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
#include <stdbool.h>
#include <sys/socket.h>
#include <uuid/uuid.h>

#define OK                     0
#define BLOCK                  4096
#define ERROR                  84
#define BITS                   64
#define MAX_NAME_LENGTH        32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH        512
#define MAX_CLIENTS            32

#define USAGE                                                        \
    "USAGE: ./my_teams port\n\tport is the port number on wich the " \
    "server socket listents\n"

// Enum containing all the valid commands. To be used in the runner.
enum commands
{
    NONE = -1,
    HELP,
    LOGIN,
    LOGOUT,
    USER,
    USERS
};

// Alligned for easier access to values
typedef struct {
    int socket_fd;
    struct sockaddr_in server;
    bool connected;
    uuid_t uuid;
} __attribute__((aligned(BITS))) connection_t;

#endif /* !DEFINITIONS_H_ */
