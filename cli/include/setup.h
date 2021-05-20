/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** setup
*/

#ifndef ARGUMENTAPRSER_H_
#define ARGUMENTAPRSER_H_

#include "definitions.h"

struct connection {
    char *ip;
    long port;
};

int checkargs(int argc, char **argv);
struct connection parse_args(char **);
int tryconnect(struct connection c, connection_t *connection);

#endif /* !ARGUMENTAPRSER_H_ */
