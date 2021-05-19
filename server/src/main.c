/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-thomas.camlong
** File description:
** main
*/

#include "maccro.h"

int usage()
{
    printf(USAGE);
    return EXIT_SUCCESS;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    if (!strcmp(argv[1], HELP))
        return usage();
    return teams_server(atoi(argv[1]));
}