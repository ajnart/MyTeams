/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** argumentaprser
*/

#ifndef ARGUMENTAPRSER_H_
#define ARGUMENTAPRSER_H_

#include "connection.h"

struct connection {
    char *ip;
    long port;

};

int checkargs(int argc, char **argv);
struct connection parse_args(char **);
int tryconnect(struct connection c, connection_t *connection);

#endif /* !ARGUMENTAPRSER_H_ */
