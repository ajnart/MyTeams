/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** argumentaprser
*/

#ifndef ARGUMENTAPRSER_H_
#define ARGUMENTAPRSER_H_

struct connection {
    unsigned int errno;
    char *ip;
    unsigned int port;
} __attribute__((aligned(16)));

int checkargs(int argc, const char **argv);
struct connection parse_args(const char **);

#endif /* !ARGUMENTAPRSER_H_ */
