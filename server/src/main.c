/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** main
*/

#include "definitions.h"
#include "maccro.h"

int usage()
{
    printf(USAGE);
    return EXIT_SUCCESS;
}

#ifndef __TESTS

int main(int argc, char **argv)
{
    // check error
    if (argc != 2)
        return (ERROR);
    if (strcmp(argv[1], "-help") == 0)
        return usage();
    long port = strtol(argv[1], NULL, 10);
    if (port < 0)
        return (ERROR);
        // init teams server
    return teams_server(port);
}

#endif