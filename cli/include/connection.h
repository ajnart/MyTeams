/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** connection
*/

#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

typedef struct 
{
    int socket_fd;
    struct sockaddr_in server;

} connection_t;

#endif /* !CONNECTION_H_ */
