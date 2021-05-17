/*
** EPITECH PROJECT, 2021
** MyTeams
** File description:
** argparser
*/

#include "argparser.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "definitions.h"

//TODO: Finish this. Catch args and allocate memory accordingly
struct connection parse_args(char **argv)
{
    struct connection ret;
    ret.ip = strdup(argv[1]);
    ret.port = strtol(argv[2], &argv[2], 10);
#ifdef __DEBUG
    printf("[D] IP:%s\n", ret.ip);
    printf("[D] Port: %ld\n", ret.port);
#endif
    return (ret);
}