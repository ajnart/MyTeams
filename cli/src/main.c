/*
** EPITECH PROJECT, 2021
** MyTeams [SSH: elitebook]
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"
#include "setup.h"
#include "runner.h"
#include "myteams/logging_client.h"

int printhelp()
{
    printf(
        "USAGE: ./myteams_cli ip port\n"
        "\tip\tis the server ip address on which the server socket listens\n"
        "\tport\tis the port number on which the server socket listens\n");
    return OK;
}

int checkargs(int argc, char **argv)
{
    struct connection c;
    connection_t *connection = (connection_t *)malloc(sizeof(connection_t));
    if (argc == 2 && strcmp(argv[1], "-help") == 0)
        return printhelp();
    if (argc != 3)
        return (ERROR);
    c = parse_args(argv);
    if (tryconnect(c, connection) == ERROR)
        return (ERROR);
    if (run(connection) == ERROR)
        return (ERROR);
    return (OK);
}

int cli(int argc, char **argv)
{
    if (checkargs(argc, argv) == ERROR)
        return (ERROR);
    return OK; // Returns OK if the program exits succesfully.
}

#ifndef __TESTS

int main(int argc, char *argv[])
{
    return (cli(argc, argv));
}

#endif