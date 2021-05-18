/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** main
*/

#include "teams_server.h"
#include "maccro.h"

int usage()
{
    printf(USAGE);
    return EXIT_SUCCESS;
}

int main(int argc, char **argv)
{
    return (argc != 3) ?
    (!strcmp(argv[1], HELP)) ? usage() : 84
    : teams_server(atoi(argv[1]));
}