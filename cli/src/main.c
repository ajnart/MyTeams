/*
** EPITECH PROJECT, 2021
** MyTeams [SSH: elitebook]
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include "logging_client.h"

int printhelp()
{
    printf("USAGE: ./myteams_cli ip port\n"
           "\tip\tis the server ip address on which the server socket listens\n"
           "\tport\tis the port number on which the server socket listens\n");
    return 0;
}

int checkargs(int argc, const char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-help") == 0)
        return printhelp();
    return 0;
}

#ifndef __TESTS

int main(int argc, char const *argv[])
{
    checkargs(argc, argv);
    return 0;
}

#endif