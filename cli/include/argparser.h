/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** argumentaprser
*/

#ifndef ARGUMENTAPRSER_H_
#define ARGUMENTAPRSER_H_

struct connection {
    char *ip;
    long port;
} __attribute__((aligned(16)));

int checkargs(int argc, char **argv);
struct connection parse_args(char **);

#endif /* !ARGUMENTAPRSER_H_ */
